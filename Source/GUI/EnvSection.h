/*
  ==============================================================================

    EnvSection.h
    Created: 28 Oct 2020 8:48:56am
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "GUISection.h"

class EnvSection : public GUISection
{
public:
	EnvSection();
	void resized() override;
private:
	juce::Slider m_attackSlider;
	juce::Slider m_decaySlider;
	juce::Slider m_sustainSlider;
	juce::Slider m_releaseSlider;
};
