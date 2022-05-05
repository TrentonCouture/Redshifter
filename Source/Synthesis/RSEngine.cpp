/*
  ==============================================================================

    RSEngine.cpp
    Created: 27 Oct 2020 2:58:55pm
    Author:  Trenton

  ==============================================================================
*/

#include "RSEngine.h"

RSEngine::RSEngine() : m_oscEng(&m_params) {}


void RSEngine::initialize(const int sampleRate, const int numSamples, const int numChannels)
{
	m_oscEng.initialize(sampleRate);

	juce::dsp::ProcessSpec effectsSpec;
	effectsSpec.sampleRate = sampleRate;
	effectsSpec.maximumBlockSize = numSamples;
	effectsSpec.numChannels = numChannels;
	m_effects.prepare(effectsSpec);

	juce::dsp::ProcessSpec lfoSpec;
	lfoSpec.sampleRate = sampleRate / 100;
	lfoSpec.maximumBlockSize = numSamples;
	lfoSpec.numChannels = numChannels;
	m_lfo.prepare(lfoSpec);
	m_lfo.initialise([](float x) {return 0.5 * std::sin(x); });

	m_effects.get<2>().setMode(juce::dsp::LadderFilterMode::LPF24);
}

void RSEngine::updateFloatParameter(std::string name, float val)
{
	m_params.getParam(name)->setValueNotifyingHost(val);
}

#include <iostream>

void RSEngine::updateChoiceParameter(std::string name)
{
	auto param = m_params.getChoiceParam(name);
	if (param)
		//param->setValueNotifyingHost(0.5);
		*param = (param->getIndex() + 1) % 5;
}

void RSEngine::process(juce::AudioBuffer<float>& buffer, const juce::MidiBuffer& midiBuffer)
{
	m_oscEng.renderNextBlock(buffer, midiBuffer, 0, buffer.getNumSamples());

	juce::dsp::Reverb::Parameters reverbParams;
	reverbParams.roomSize = *m_params.getParam("roomSize");
	reverbParams.wetLevel = *m_params.getParam("wet");
	m_effects.get<Effect::reverb>().setParameters(reverbParams);

	const float maxChorusRate = 5;
	m_effects.get<Effect::chorus>().setRate(*m_params.getParam("chorusRate") * maxChorusRate);
	m_effects.get<Effect::chorus>().setDepth(*m_params.getParam("chorusDepth"));
	m_effects.get<Effect::chorus>().setMix(*m_params.getParam("chorusMix"));

	const float lfoMaxFreq = 50;
	m_lfo.setFrequency(*m_params.getParam("lfoFilterFreq") * lfoMaxFreq);
	auto lfoGain = m_lfo.processSample(0.0);
	const float maxCutoff = 20000;
	m_effects.get<Effect::filter>().setCutoffFrequencyHz((1 + lfoGain * *m_params.getParam("lfoFilterAmp")) * *m_params.getParam("cutoff") * maxCutoff);
	m_effects.get<Effect::filter>().setResonance(*m_params.getParam("resonance"));
	m_effects.get<Effect::filter>().setDrive(*m_params.getParam("filterDrive") * 10 + 1);

	const float maxPhaserRate = 5;
	m_effects.get<Effect::phaser>().setRate(*m_params.getParam("phaserRate") * maxPhaserRate);
	m_effects.get<Effect::phaser>().setDepth(*m_params.getParam("phaserDepth"));
	m_effects.get<Effect::phaser>().setMix(*m_params.getParam("phaserMix"));

	m_effects.get<Effect::gain>().setGainLinear(*m_params.getParam("gain"));

	auto block = juce::dsp::AudioBlock<float>(buffer);
	juce::dsp::ProcessContextReplacing<float> context(block);
	m_effects.process(context);
}
