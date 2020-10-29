/*
  ==============================================================================

    RSEngine.h
    Created: 27 Oct 2020 2:58:55pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "OscillatorEngine.h"
#include "Parameters.h"

class RSEngine
{
public:
	void initialize(const int sampleRate, const int numSamples, const int numChannels);
	void process(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiBuffer);
private:
	OscillatorEngine m_oscEng;
	juce::dsp::ProcessorChain<juce::dsp::Reverb, juce::dsp::Chorus<float>> m_effects;

	Parameters m_params;
};
