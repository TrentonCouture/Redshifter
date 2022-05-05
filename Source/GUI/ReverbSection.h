/*
  ==============================================================================

    ReverbSection.h
    Created: 28 Oct 2020 6:56:51pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GUISection.h"

class ReverbSection : public GUISection
{
public:
	ReverbSection();
	void resized() override;
private:
	juce::Slider m_roomSizeSlider;
	juce::Slider m_wetSlider;
};
