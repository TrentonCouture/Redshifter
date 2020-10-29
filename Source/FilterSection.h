/*
  ==============================================================================

    FilterSection.h
    Created: 28 Oct 2020 9:59:38pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GUISection.h"

class FilterSection : public GUISection
{
public:
	FilterSection();
	void resized() override;
	void paint(juce::Graphics& g) override;
private:
	juce::Slider m_cutoffSlider;
};
