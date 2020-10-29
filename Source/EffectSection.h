/*
  ==============================================================================

    EffectSection.h
    Created: 29 Oct 2020 6:26:46am
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GUISection.h"

class EffectSection : public GUISection
{
public:
	EffectSection();
	void resized() override {};
	void paint(juce::Graphics& g) override {};
};
