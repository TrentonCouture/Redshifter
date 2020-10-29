/*
  ==============================================================================

    ChorusSection.cpp
    Created: 28 Oct 2020 8:00:15pm
    Author:  Trenton

  ==============================================================================
*/

#include "ChorusSection.h"

ChorusSection::ChorusSection()
{
	m_rateSlider.setName("chorusRate");
	addSlider(m_rateSlider);
}

void ChorusSection::paint(juce::Graphics& g)
{
	g.fillAll(juce::Colours::aqua);
}

void ChorusSection::resized()
{
	auto area = getLocalBounds();
	const int sliderHeight = 50;
	m_rateSlider.setBounds(area.removeFromLeft(sliderHeight));
}
