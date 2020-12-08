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

		juce::AudioParameterFloat* parameter;
		auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
		if (parent)
		{
			const int numPartials = 42;
			for (int i = 0; i < numPartials; i++)
			{
				parameter = parent->getParam("partialAmp" + std::to_string(i));
				if (parameter)
				{
					parameter->setValueNotifyingHost(0.5);
				}
			}
		}
}
