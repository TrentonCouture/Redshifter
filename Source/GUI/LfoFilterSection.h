/*
  ==============================================================================

    LfoFilterSection.h
    Created: 29 Oct 2020 4:06:58pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "GUISection.h"

class LfoFilterSection : public GUISection
{
public:
	LfoFilterSection();
	void resized() override;
private:
	juce::Slider m_freqSlider;
	juce::Slider m_ampSlider;
};
