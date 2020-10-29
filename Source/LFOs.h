/*
  ==============================================================================

    LFOs.h
    Created: 29 Oct 2020 11:30:58am
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Parameters.h"

class LFOs
{
public:
	void initialize(const int sampleRate, const int numSamples, const int numChannels);
	void process(juce::dsp::LadderFilter<float>& filter);
private:
	juce::dsp::Oscillator<float> m_lfo;
	Parameters m_params;
};
