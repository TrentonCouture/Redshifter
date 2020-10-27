/*
  ==============================================================================

    Oscillators.cpp
    Created: 23 Oct 2020 12:58:56pm
    Author:  Trenton

  ==============================================================================
*/

#include "Oscillators.h"

Oscillators::Oscillators() : m_osc([](float x) { return std::sin(x); }, 128)
{

}

void Oscillators::initialize(int sampleRate, int numSamples, int numChannels)
{
	m_numChannels = numChannels;
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
	m_play = true;
	m_osc.setFrequency(noteToFreq(midiNoteNumber), true);
}

void Oscillators::stopNote(float velocity, bool tailOff)
{
	m_play = false;
}

void Oscillators::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	if (m_play)
	{
		auto block = juce::dsp::AudioBlock<float>(outputBuffer);
		juce::dsp::ProcessContextReplacing<float> context(block);
		m_osc.process(context);
	}
}
