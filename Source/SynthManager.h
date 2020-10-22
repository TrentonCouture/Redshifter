/*
  ==============================================================================

    SynthManager.h
    Created: 21 Oct 2020 6:45:38pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MidiManager.h"

class SynthManager
{
protected:
	void processMidi(const juce::MidiBuffer& midiMessages);
private:
	MidiManager m_midiManager;
};
