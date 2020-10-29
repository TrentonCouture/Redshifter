/*
  ==============================================================================

    LfoFilterSection.cpp
    Created: 29 Oct 2020 4:06:58pm
    Author:  Trenton

  ==============================================================================
*/

#include "LfoFilterSection.h"
LfoFilterSection::LfoFilterSection()
{
	m_freqSlider.setName("lfoFilterFreq");
	addSlider(m_freqSlider);

	m_ampSlider.setName("lfoFilterAmp");
	addSlider(m_ampSlider);
}


void LfoFilterSection::resized()
{
	auto area = getLocalBounds();
	const int sliderHeight = 50;
	m_freqSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_ampSlider.setBounds(area.removeFromLeft(sliderHeight));
}
