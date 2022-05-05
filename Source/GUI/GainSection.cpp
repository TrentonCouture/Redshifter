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
	const int numSliders = 1;
	const int sliderHeight = 50;
	const int spacingWidth = (getWidth() - numSliders * sliderHeight) / (numSliders + 1);
	area.removeFromLeft(spacingWidth);
	m_gainSlider.setBounds(area.removeFromLeft(sliderHeight));
}

