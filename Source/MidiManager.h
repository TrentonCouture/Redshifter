/*
  ==============================================================================

    MidiManager.h
    Created: 22 Oct 2020 4:33:18pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class MidiManager
{
public:
	void takeMidiMessage(const juce::MidiMessage& message);
};
