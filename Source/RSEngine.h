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
#include "AmpEnvelope.h"

class RSEngine
{
public:
	void initialize(const int sampleRate, const int numSamples, const int numChannels);
	void process(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiBuffer);
private:
	OscillatorEngine m_oscEng;
};
