/*
  ==============================================================================

    AdditiveSection.cpp
    Created: 5 Dec 2020 8:49:31pm
    Author:  Trent

  ==============================================================================
*/

#include "AdditiveSection.h"
#include "PluginEditor.h"

AdditiveSection::AdditiveSection() :
	m_testButton("testButton", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey)
{
	addButton(m_testButton);
}

void AdditiveSection::resized()
{
	m_testButton.setBounds(getLocalBounds());
}

void AdditiveSection::buttonClicked(juce::Button* button)
{
	DBG("Button clicked");
	setPartialAmps();
}

void AdditiveSection::setPartialAmps()
{
	DBG("Running setPartialAmps()");
	juce::AudioParameterFloat* parameter;
	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
	{
		DBG("parent added");
		parameter = parent->getParam("attack");
		if (parameter)
		{
			DBG("Parameter is set");
		}
	}
}
