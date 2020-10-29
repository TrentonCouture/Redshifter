/*
  ==============================================================================

    ReverbSection.cpp
    Created: 28 Oct 2020 6:56:51pm
    Author:  Trenton

  ==============================================================================
*/

#include "ReverbSection.h"

ReverbSection::ReverbSection()
{
	m_roomSizeSlider.setName("roomSize");
	addSlider(m_roomSizeSlider);

	m_wetSlider.setName("wet");
	addSlider(m_wetSlider);
}

void ReverbSection::paint(juce::Graphics& g)
{
	g.fillAll(juce::Colours::white);
}

void ReverbSection::resized()
{
	auto area = getLocalBounds();
	const int sliderHeight = 50;
	m_roomSizeSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_wetSlider.setBounds(area.removeFromLeft(sliderHeight));
}
