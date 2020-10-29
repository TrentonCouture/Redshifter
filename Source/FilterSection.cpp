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
}

void FilterSection::paint(juce::Graphics& g)
{
	g.fillAll(juce::Colours::green);
}

void FilterSection::resized()
{
	auto area = getLocalBounds();
	const int sliderHeight = 50;
	m_cutoffSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_resonanceSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_driveSlider.setBounds(area.removeFromLeft(sliderHeight));
}
