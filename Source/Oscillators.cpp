/*
  ==============================================================================

    Oscillators.cpp
    Created: 23 Oct 2020 12:58:56pm
    Author:  Trenton

  ==============================================================================
*/

#include "Oscillators.h"

Oscillators::Oscillators(const int sampleRate, const int numSamples, const int numChannels) : m_osc([](float x) { return std::sin(x); }, 128)
{
	m_adsr.setSampleRate(sampleRate);
	juce::ADSR::Parameters adsrParams;
	m_adsr.setParameters(adsrParams);

	m_numChannels = numChannels;
	juce::dsp::ProcessSpec pSpec;
	pSpec.maximumBlockSize = numSamples;
	pSpec.sampleRate = sampleRate;
	pSpec.numChannels = numChannels;

	m_osc.prepare(pSpec);
}

void Oscillators::initialize(const int sampleRate, const int numSamples, const int numChannels)
{
}

float Oscillators::noteToFreq(const int note) {
    const int a = 440; 
    return (a) * std::pow(2.0, ((note - 69) / 12.0));
}

void Oscillators::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
	juce::ADSR::Parameters adsrParams;
	adsrParams.attack = *m_params.getParam("attack");
	m_adsr.setParameters(adsrParams);
	m_adsr.noteOn();
	m_osc.setFrequency(noteToFreq(midiNoteNumber), true);
}

void Oscillators::stopNote(float velocity, bool tailOff)
{
	m_adsr.noteOff();
}

void Oscillators::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	auto wholeBlock = juce::dsp::AudioBlock<float>(outputBuffer);
	auto block = wholeBlock.getSubBlock(startSample, (size_t) numSamples);
	juce::dsp::ProcessContextReplacing<float> context(block);
	m_osc.process(context);
	m_adsr.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
}
