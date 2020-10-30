/*
  ==============================================================================

    EnvSection.cpp
    Created: 28 Oct 2020 8:48:56am
    Author:  Trenton

  ==============================================================================
*/

#include "EnvSection.h"

EnvSection::EnvSection()
{
	m_attackSlider.setName("attack");
	addSlider(m_attackSlider);

	m_decaySlider.setName("decay");
	addSlider(m_decaySlider);

	m_sustainSlider.setName("sustain");
	addSlider(m_sustainSlider);

	m_releaseSlider.setName("release");
	addSlider(m_releaseSlider);

	m_isLeft = true;
}

void EnvSection::resized()
{
	auto area = getLocalBounds();
	const int labelHeight = 24;
	area.removeFromTop(labelHeight);
	const int sliderHeight = 50;
	m_attackSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_decaySlider.setBounds(area.removeFromLeft(sliderHeight));
	m_sustainSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_releaseSlider.setBounds(area.removeFromLeft(sliderHeight));
}
