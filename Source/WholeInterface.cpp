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
	m_attackSlider.setSliderStyle(juce::Slider::Rotary);
	m_attackSlider.setName("attack");
	addSlider(m_attackSlider);
}


void WholeInterface::resized()
{
	m_attackSlider.setBounds(50, 50, 50, 50);
}
