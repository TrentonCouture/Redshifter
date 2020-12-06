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
	addAndMakeVisible(m_oscillatorSection);
	addAndMakeVisible(m_envSection);
	addAndMakeVisible(m_reverbSection);
	addAndMakeVisible(m_chorusSection);
	addAndMakeVisible(m_filterSection);
	addAndMakeVisible(m_phaserSection);
	addAndMakeVisible(m_gainSection);
	addAndMakeVisible(m_lfoFilterSection);
	addAndMakeVisible(m_additiveSection);
}


void WholeInterface::resized()
{
	auto area = getLocalBounds();

	const int sectionHeight = 100;
	const int sectionWidth = getWidth() / 2;
	const int additiveHeight = 150;

	auto additive = area.removeFromTop(additiveHeight);
	m_additiveSection.setBounds(additive);

	auto oscAndLfo = area.removeFromTop(sectionHeight);
	m_oscillatorSection.setBounds(oscAndLfo.removeFromLeft(sectionWidth));
	m_lfoFilterSection.setBounds(oscAndLfo.removeFromLeft(sectionWidth));

	auto envAndReverb = area.removeFromTop(sectionHeight);
	m_envSection.setBounds(envAndReverb.removeFromLeft(sectionWidth));
	m_reverbSection.setBounds(envAndReverb.removeFromLeft(sectionWidth));

	auto chorusAndFilter = area.removeFromTop(sectionHeight);
	m_chorusSection.setBounds(chorusAndFilter.removeFromLeft(sectionWidth));
	m_filterSection.setBounds(chorusAndFilter.removeFromLeft(sectionWidth));

	auto phaserAndGain = area.removeFromTop(sectionHeight);
	m_phaserSection.setBounds(phaserAndGain.removeFromLeft(sectionWidth));
	m_gainSection.setBounds(phaserAndGain.removeFromLeft(sectionWidth));
}
