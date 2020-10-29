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
	addAndMakeVisible(m_filterSection);
	addAndMakeVisible(m_phaserSection);
	addAndMakeVisible(m_gainSection);
}


void WholeInterface::resized()
{
	auto area = getLocalBounds();

	int sectionHeight = 50;
	m_envSection.setBounds(area.removeFromTop(sectionHeight));
	m_reverbSection.setBounds(area.removeFromTop(sectionHeight));
	m_chorusSection.setBounds(area.removeFromTop(sectionHeight));
	m_filterSection.setBounds(area.removeFromTop(sectionHeight));
	m_phaserSection.setBounds(area.removeFromTop(sectionHeight));
	m_gainSection.setBounds(area.removeFromTop(sectionHeight));
}
