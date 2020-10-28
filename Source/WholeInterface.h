/*
  ==============================================================================

    WholeInterface.h
    Created: 27 Oct 2020 9:10:29pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "GUISection.h"

class WholeInterface : public GUISection
{
public:
	WholeInterface();
	void resized() override;
private:
	juce::Slider m_attackSlider;
};
