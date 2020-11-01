/*
  ==============================================================================

    OscillatorSection.cpp
    Created: 28 Oct 2020 11:40:01pm
    Author:  Trenton

  ==============================================================================
*/

#include "OscillatorSection.h"

OscillatorSection::OscillatorSection() : 
	m_sineButton("sine1", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_sawButton("saw1", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_squareButton("square1", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_triangleButton("triangle1", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_sineButton2("sine2", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_sawButton2("saw2", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_squareButton2("square2", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_triangleButton2("triangle2", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey)

{
	m_oscMixSlider.setName("oscMix");
	addSlider(m_oscMixSlider);

	addButton(m_sineButton);
	addButton(m_sawButton);
	addButton(m_squareButton);
	addButton(m_triangleButton);

	addButton(m_sineButton2);
	addButton(m_sawButton2);
	addButton(m_squareButton2);
	addButton(m_triangleButton2);

	m_isLeft = true;
}

void OscillatorSection::resized()
{
	auto area = getLocalBounds();

	const int labelHeight = 24;
	area.removeFromTop(labelHeight);

	const int sliderHeight = 50;
	const int spacingWidth = (getWidth() - (m_sineButton.getWidth() * 8 + sliderHeight)) / 2;
	area.removeFromLeft(spacingWidth);

	m_sineButton.setBounds(area.removeFromLeft(m_sineButton.getWidth()));
	m_sawButton.setBounds(area.removeFromLeft(m_sawButton.getWidth()));
	m_squareButton.setBounds(area.removeFromLeft(m_squareButton.getWidth()));
	m_triangleButton.setBounds(area.removeFromLeft(m_triangleButton.getWidth()));

	m_oscMixSlider.setBounds(area.removeFromLeft(sliderHeight));

	m_sineButton2.setBounds(area.removeFromLeft(m_sineButton.getWidth()));
	m_sawButton2.setBounds(area.removeFromLeft(m_sawButton.getWidth()));
	m_squareButton2.setBounds(area.removeFromLeft(m_squareButton.getWidth()));
	m_triangleButton2.setBounds(area.removeFromLeft(m_triangleButton.getWidth()));
} 

