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

class OscillatorSection : public GUISection, public juce::AudioProcessorParameter::Listener
{
public:
	OscillatorSection();
	void resized() override;
	void paint(juce::Graphics& g) override;
	void parameterValueChanged(int parameterIndex, float newValue) override;
	void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override {};

private:
	void drawSineWave(juce::Rectangle<int> section, juce::Graphics& g, int side);
	void drawSawWave(juce::Rectangle<int> section, juce::Graphics& g, int side);
	void drawSquareWave(juce::Rectangle<int> section, juce::Graphics& g, int side);
	void drawTriangleWave(juce::Rectangle<int> section, juce::Graphics& g, int side);
	void drawLabel(juce::Rectangle<int> section, int side);

	const int m_numOscs = 2;
	juce::Label m_additiveLabel[2];

	juce::Slider m_oscMixSlider;
	juce::ShapeButton m_oscButton;
	juce::ShapeButton m_oscButton2;

	juce::Rectangle<int> m_icons1;
	juce::Rectangle<int> m_icons2;

	bool m_initialized;
};
