/*
  ==============================================================================

    Oscillators.cpp
    Created: 23 Oct 2020 12:58:56pm
    Author:  Trenton

  ==============================================================================
*/

#include "Oscillators.h"

Oscillators::Oscillators(const int sampleRate, const int numSamples, const int numChannels) : m_osc([](float x) { return 0.2 * std::sin(x); }, 128)
{
	m_adsr.setSampleRate(sampleRate);
	juce::ADSR::Parameters adsrParams;
	m_adsr.setParameters(adsrParams);

	juce::dsp::ProcessSpec pSpec;
	pSpec.maximumBlockSize = numSamples;
	pSpec.sampleRate = sampleRate;
	pSpec.numChannels = numChannels;

	m_osc.prepare(pSpec);
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
	m_osc.setFrequency(noteToFreq(midiNoteNumber), true);
	m_adsr.noteOn();
}

void Oscillators::stopNote(float velocity, bool tailOff)
{
	m_adsr.noteOff();
}

void Oscillators::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	juce::AudioBuffer<float> tempBuffer(outputBuffer.getNumChannels(), outputBuffer.getNumSamples());
	tempBuffer.clear();
	auto wholeBlock = juce::dsp::AudioBlock<float>(tempBuffer);
	auto block = wholeBlock.getSubBlock(startSample, (size_t)numSamples);
	juce::dsp::ProcessContextReplacing<float> context(block);
	m_osc.process(context);
	m_adsr.applyEnvelopeToBuffer(tempBuffer, startSample, numSamples);

	for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
		outputBuffer.addFrom(channel, startSample, tempBuffer, channel, startSample, numSamples);
}
