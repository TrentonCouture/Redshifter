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

	m_isLeft = false;
}


void ReverbSection::resized()
{
	auto area = getLocalBounds();
	const int labelHeight = 24;
	area.removeFromTop(labelHeight);
	const int sliderHeight = 50;
	m_roomSizeSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_wetSlider.setBounds(area.removeFromLeft(sliderHeight));
}
