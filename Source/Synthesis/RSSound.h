/*
  ==============================================================================

    RSSound.h
    Created: 23 Oct 2020 12:39:20pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class RSSound : public juce::SynthesiserSound
{
	bool appliesToNote(int midiNoteNumber) override;
	bool appliesToChannel(int midiChannel) override;
};
