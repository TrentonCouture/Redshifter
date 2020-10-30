/*
  ==============================================================================

    PhaserSection.cpp
    Created: 28 Oct 2020 10:48:08pm
    Author:  Trenton

  ==============================================================================
*/

#include "PhaserSection.h"

PhaserSection::PhaserSection()
{
	m_rateSlider.setName("phaserRate");
	addSlider(m_rateSlider);

	m_depthSlider.setName("phaserDepth");
	addSlider(m_depthSlider);

	m_mixSlider.setName("phaserMix");
	addSlider(m_mixSlider);

	m_isLeft = true;
}

void PhaserSection::resized()
{
	auto area = getLocalBounds();
	const int labelHeight = 24;
	area.removeFromTop(labelHeight);
	const int sliderHeight = 50;
	m_rateSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_depthSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_mixSlider.setBounds(area.removeFromLeft(sliderHeight));
}
