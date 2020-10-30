/*
  ==============================================================================

    Oscillators.cpp
    Created: 23 Oct 2020 12:58:56pm
    Author:  Trenton

  ==============================================================================
*/

#include "Oscillators.h"

Oscillators::Oscillators(const int sampleRate, const int numSamples, const int numChannels) 
{
	m_adsr.setSampleRate(sampleRate);

	juce::dsp::ProcessSpec pSpec;
	pSpec.maximumBlockSize = numSamples;
	pSpec.sampleRate = sampleRate;
	pSpec.numChannels = numChannels;

	m_sinOsc.prepare(pSpec);
	m_sawOsc.prepare(pSpec);

	m_sinOsc.get<Osc::osc>().initialise([](float x) {return 0.2 * std::sin(x); }, 128);
	m_sawOsc.get<Osc::osc>().initialise([](float x) {return 0.2 * x / juce::MathConstants<float>::pi; }, 128);
}


float Oscillators::noteToFreq(const int note) {
    const int a = 440; 
    return (a) * std::pow(2.0, ((note - 69) / 12.0));
}

void Oscillators::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
	juce::ADSR::Parameters adsrParams;
	adsrParams.attack = *m_params.getParam("attack");
	adsrParams.decay = *m_params.getParam("decay");
	adsrParams.sustain = *m_params.getParam("sustain");
	adsrParams.release = *m_params.getParam("release");
	m_adsr.setParameters(adsrParams);
	m_sinOsc.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_sawOsc.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_adsr.noteOn();
}

void Oscillators::stopNote(float velocity, bool tailOff)
{
	m_adsr.noteOff();
}

void Oscillators::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	m_sinOsc.get<Osc::vol>().setGainLinear(*m_params.getParam("oscMix"));
	m_sawOsc.get<Osc::vol>().setGainLinear(1.0 - *m_params.getParam("oscMix"));

	juce::AudioBuffer<float> tempBuffer(outputBuffer.getNumChannels(), outputBuffer.getNumSamples());
	tempBuffer.clear();
	auto wholeBlock = juce::dsp::AudioBlock<float>(tempBuffer);
	auto block = wholeBlock.getSubBlock(startSample, (size_t)numSamples);
	juce::dsp::ProcessContextReplacing<float> context(block);
	m_sinOsc.process(context);


	juce::AudioBuffer<float> sawBuffer(outputBuffer.getNumChannels(), outputBuffer.getNumSamples());
	sawBuffer.clear();
	auto wholeSawBlock = juce::dsp::AudioBlock<float>(sawBuffer);
	auto sawBlock = wholeSawBlock.getSubBlock(startSample, (size_t)numSamples);
	juce::dsp::ProcessContextReplacing<float> sawContext(sawBlock);
	m_sawOsc.process(sawContext);

	m_adsr.applyEnvelopeToBuffer(tempBuffer, startSample, numSamples);
	m_adsr.applyEnvelopeToBuffer(sawBuffer, startSample, numSamples);

	for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
		outputBuffer.addFrom(channel, startSample, tempBuffer, channel, startSample, numSamples);

	for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
		outputBuffer.addFrom(channel, startSample, sawBuffer, channel, startSample, numSamples);
}
