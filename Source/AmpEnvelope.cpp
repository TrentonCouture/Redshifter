/*
  ==============================================================================

    Envelope.cpp
    Created: 27 Oct 2020 2:33:06pm
    Author:  Trenton

  ==============================================================================
*/

#include "AmpEnvelope.h"


void AmpEnvelope::initialize(const int sampleRate)
{
	m_adsr.setSampleRate(sampleRate);
	juce::ADSR::Parameters params;
	m_adsr.setParameters(params);
}

void AmpEnvelope::process(juce::AudioBuffer<float>& buffer, const juce::MidiBuffer& midiBuffer)
{

}
