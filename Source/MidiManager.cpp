/*
  ==============================================================================

    MidiManager.cpp
    Created: 22 Oct 2020 4:33:18pm
    Author:  Trenton

  ==============================================================================
*/

#include "MidiManager.h"

void MidiManager::takeMidiMessage(const juce::MidiMessage& message)
{
	if (message.isNoteOn())
		DBG(message.getNoteNumber());
}
