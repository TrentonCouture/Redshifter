/*
  ==============================================================================

    OscillatorSection.h
    Created: 28 Oct 2020 11:40:00pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GUISection.h"

class OscillatorSection : public GUISection
{
public:
	OscillatorSection();
	void resized() override;
private:
	juce::Slider m_oscMixSlider;
};
