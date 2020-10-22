/*
  ==============================================================================

    SynthManager.cpp
    Created: 21 Oct 2020 6:45:38pm
    Author:  Trenton

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SynthManager.h"


void SynthManager::processMidi(const juce::MidiBuffer& midiMessages)
{
	juce::MidiBuffer::Iterator iter(midiMessages);
	juce::MidiMessage message;
	int samplePosition;
	while (iter.getNextEvent(message, samplePosition))
	{
		m_midiManager.takeMidiMessage(message);
	}
}
