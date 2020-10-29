/*
  ==============================================================================

    GainSection.cpp
    Created: 28 Oct 2020 10:57:16pm
    Author:  Trenton

  ==============================================================================
*/

#include "GainSection.h"

GainSection::GainSection()
{
	m_gainSlider.setName("gain");
	addSlider(m_gainSlider);
}

void GainSection::paint(juce::Graphics& g)
{
	g.fillAll(juce::Colours::violet);
}

void GainSection::resized()
{
	auto area = getLocalBounds();
	const int sliderHeight = 50;
	m_gainSlider.setBounds(area.removeFromLeft(sliderHeight));
}
