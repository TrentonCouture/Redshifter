/*
  ==============================================================================

    GUISection.h
    Created: 27 Oct 2020 9:02:40pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Parameters.h"

class GUISection : public juce::Component, public juce::Slider::Listener
{
protected:
	void addSlider(juce::Slider& slider);
	void sliderValueChanged(juce::Slider* slider) override;
	void paint(juce::Graphics& g) override;
private:
	Parameters m_params;
};
