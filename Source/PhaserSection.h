/*
  ==============================================================================

    PhaserSection.h
    Created: 28 Oct 2020 10:48:07pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GUISection.h"

class PhaserSection : public GUISection
{
public:
	PhaserSection();
	void resized() override;
private:
	juce::Slider m_rateSlider;
	juce::Slider m_depthSlider;
	juce::Slider m_mixSlider;
};
