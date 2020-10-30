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

	m_isLeft = false;
}


void LfoFilterSection::resized()
{
	auto area = getLocalBounds();
	const int labelHeight = 24;
	area.removeFromTop(labelHeight);
	const int numSliders = 2;
	const int sliderHeight = 50;
	const int spacingWidth = (getWidth() - numSliders * sliderHeight) / (numSliders + 1);
	area.removeFromLeft(spacingWidth);
	m_freqSlider.setBounds(area.removeFromLeft(sliderHeight));
	area.removeFromLeft(spacingWidth);
	m_ampSlider.setBounds(area.removeFromLeft(sliderHeight));
}
