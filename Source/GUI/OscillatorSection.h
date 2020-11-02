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
	void paint(juce::Graphics& g) override;
private:
	void drawSineWave(juce::Rectangle<int> section, juce::Graphics& g, int side);
	void drawSawWave(juce::Rectangle<int> section, juce::Graphics& g, int side);
	void drawSquareWave(juce::Rectangle<int> section, juce::Graphics& g, int side);
	void drawTriangleWave(juce::Rectangle<int> section, juce::Graphics& g, int side);

	juce::Slider m_oscMixSlider;
	juce::ShapeButton m_oscButton;
	juce::ShapeButton m_oscButton2;

	juce::Rectangle<int> m_icons1;
	juce::Rectangle<int> m_icons2;

	Parameters m_params;
};
