/*
  ==============================================================================

    OscillatorSection.cpp
    Created: 28 Oct 2020 11:40:01pm
    Author:  Trenton

  ==============================================================================
*/

#include "OscillatorSection.h"

OscillatorSection::OscillatorSection()
{
	m_oscMixSlider.setName("oscMix");
	addSlider(m_oscMixSlider);

	m_isLeft = true;
}

void OscillatorSection::resized()
{
	auto area = getLocalBounds();
	const int labelHeight = 24;
	area.removeFromTop(labelHeight);
	const int sliderHeight = 50;
	m_oscMixSlider.setBounds(area.removeFromLeft(sliderHeight));
} 

