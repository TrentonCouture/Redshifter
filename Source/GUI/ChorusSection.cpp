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

	m_depthSlider.setName("chorusDepth");
	addSlider(m_depthSlider);

	m_mixSlider.setName("chorusMix");
	addSlider(m_mixSlider);

	m_isLeft = true;
}

void ChorusSection::resized()
{
	auto area = getLocalBounds();
	const int labelHeight = 24;
	area.removeFromTop(labelHeight);
	const int numSliders = 3;
	const int sliderHeight = 50;
	const int spacingWidth = (getWidth() - numSliders * sliderHeight) / (numSliders + 1);
	area.removeFromLeft(spacingWidth);
	m_mixSlider.setBounds(area.removeFromLeft(sliderHeight));
	area.removeFromLeft(spacingWidth);
	m_rateSlider.setBounds(area.removeFromLeft(sliderHeight));
	area.removeFromLeft(spacingWidth);
	m_depthSlider.setBounds(area.removeFromLeft(sliderHeight));
}
