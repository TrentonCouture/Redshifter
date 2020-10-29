/*
  ==============================================================================

    GainSection.h
    Created: 28 Oct 2020 10:57:15pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GUISection.h"

class GainSection : public GUISection
{
public:
	GainSection();
	void resized() override;
	void paint(juce::Graphics& g) override;
private:
	juce::Slider m_gainSlider;
};
