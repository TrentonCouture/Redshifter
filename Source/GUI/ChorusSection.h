/*
  ==============================================================================

    ChorusSection.h
    Created: 28 Oct 2020 8:00:15pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "GUISection.h"

class ChorusSection : public GUISection
{
public:
	ChorusSection();
	void resized() override;
private:
	juce::Slider m_rateSlider;
	juce::Slider m_depthSlider;
	juce::Slider m_mixSlider;
};
