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
	juce::ShapeButton m_sineButton;
	juce::ShapeButton m_sawButton;
	juce::ShapeButton m_squareButton;
	juce::ShapeButton m_triangleButton;

	juce::ShapeButton m_sineButton2;
	juce::ShapeButton m_sawButton2;
	juce::ShapeButton m_squareButton2;
	juce::ShapeButton m_triangleButton2;
};
