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
}


void WholeInterface::resized()
{
	auto area = getLocalBounds();

	int envSectionHeight = 100;
	m_envSection.setBounds(area.removeFromTop(envSectionHeight));
}
