/*
  ==============================================================================

    FilterSection.cpp
    Created: 28 Oct 2020 9:59:38pm
    Author:  Trenton

  ==============================================================================
*/

#include "FilterSection.h"

FilterSection::FilterSection()
{
	m_cutoffSlider.setName("cutoff");
	addSlider(m_cutoffSlider);

	m_resonanceSlider.setName("resonance");
	addSlider(m_resonanceSlider);

	m_driveSlider.setName("filterDrive");
	addSlider(m_driveSlider);

	m_cutoffSlider.setSkewFactorFromMidPoint(.1);

	m_isLeft = false;
}

void FilterSection::resized()
{
	auto area = getLocalBounds();
	const int labelHeight = 24;
	area.removeFromTop(labelHeight);
	const int numSliders = 3;
	const int sliderHeight = 50;
	const int spacingWidth = (getWidth() - numSliders * sliderHeight) / (numSliders + 1);
	area.removeFromLeft(spacingWidth);
	m_cutoffSlider.setBounds(area.removeFromLeft(sliderHeight));
	area.removeFromLeft(spacingWidth);
	m_resonanceSlider.setBounds(area.removeFromLeft(sliderHeight));
	area.removeFromLeft(spacingWidth);
	m_driveSlider.setBounds(area.removeFromLeft(sliderHeight));
}
