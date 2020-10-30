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

	m_isLeft = false;
}

void GainSection::resized()
{
	auto area = getLocalBounds();
	const int labelHeight = 24;
	area.removeFromTop(labelHeight);
	const int sliderHeight = 50;
	m_gainSlider.setBounds(area.removeFromLeft(sliderHeight));
}

