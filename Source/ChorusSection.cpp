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
}

void ChorusSection::resized()
{
	auto area = getLocalBounds();
	const int sliderHeight = 50;
	m_rateSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_depthSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_mixSlider.setBounds(area.removeFromLeft(sliderHeight));
}
