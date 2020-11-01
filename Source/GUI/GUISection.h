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
#include <vector>

class GUISection : public juce::Component, public juce::Slider::Listener
{
protected:
	void addSlider(juce::Slider& slider);
	void addButton(juce::ShapeButton& button);
	void sliderValueChanged(juce::Slider* slider) override;
	void paint(juce::Graphics& g) override;
protected:
	bool m_isLeft;
private:
	Parameters m_params;
	juce::OwnedArray<juce::Label> m_labels;

};
