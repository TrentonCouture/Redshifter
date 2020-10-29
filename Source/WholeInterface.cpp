/*
  ==============================================================================

    WholeInterface.cpp
    Created: 27 Oct 2020 9:10:29pm
    Author:  Trenton

  ==============================================================================
*/

#include "WholeInterface.h"

WholeInterface::WholeInterface()
{
	addAndMakeVisible(m_envSection);
	addAndMakeVisible(m_reverbSection);
	addAndMakeVisible(m_chorusSection);
}


void WholeInterface::resized()
{
	auto area = getLocalBounds();

	int sectionHeight = 50;
	m_envSection.setBounds(area.removeFromTop(sectionHeight));
	m_reverbSection.setBounds(area.removeFromTop(sectionHeight));
	m_chorusSection.setBounds(area.removeFromTop(sectionHeight));
}
