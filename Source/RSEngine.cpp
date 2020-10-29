/*
  ==============================================================================

    RSEngine.cpp
    Created: 27 Oct 2020 2:58:55pm
    Author:  Trenton

  ==============================================================================
*/

#include "RSEngine.h"

void RSEngine::initialize(const int sampleRate, const int numSamples, const int numChannels)
{
	m_oscEng.initialize(sampleRate, numSamples, numChannels);

	juce::dsp::ProcessSpec effectsSpec;
	effectsSpec.sampleRate = sampleRate;
	effectsSpec.maximumBlockSize = numSamples;
	effectsSpec.numChannels = numChannels;
	m_effects.prepare(effectsSpec);

}
void RSEngine::process(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiBuffer)
{
	m_oscEng.renderNextBlock(buffer, midiBuffer, 0, buffer.getNumSamples());

	juce::dsp::Reverb::Parameters reverbParams;
	reverbParams.roomSize = *m_params.getParam("roomSize");
	reverbParams.wetLevel = *m_params.getParam("wet");
	m_effects.get<0>().setParameters(reverbParams);

	const float maxChorusRate = 99.9;
	m_effects.get<1>().setRate(*m_params.getParam("chorusRate") * maxChorusRate);

	auto block = juce::dsp::AudioBlock<float>(buffer);
	juce::dsp::ProcessContextReplacing<float> context(block);
	m_effects.process(context);
}
