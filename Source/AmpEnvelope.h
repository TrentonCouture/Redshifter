/*
  ==============================================================================

    Envelope.h
    Created: 27 Oct 2020 2:33:06pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AmpEnvelope
{
public:
	void initialize(const int sampleRate);
	void process(juce::AudioBuffer<float>& buffer, const juce::MidiBuffer& midiBuffer);
private:
	juce::ADSR m_adsr;
};
