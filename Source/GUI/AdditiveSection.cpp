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
	m_testButton("testButton", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	juce::Thread("AdditiveThread")
{
	addButton(m_testButton);
	startThread();
}

AdditiveSection::~AdditiveSection()
{
	stopThread(1000);
}

void AdditiveSection::resized()
{
	m_testButton.setBounds(getLocalBounds());
}

void AdditiveSection::buttonClicked(juce::Button* button)
{
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
					parameter->setValueNotifyingHost(0.0);
				}
			}

			for (int i = 0; i < numPartials; i++)
			{
				parameter = parent->getParam("partialAmp" + std::to_string(i));
				if (parameter && i % 2 == 0)
				{
					parameter->setValueNotifyingHost(1.0);
				}
			}
		}
}

void AdditiveSection::run()
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
				parameter->setValueNotifyingHost(1.0);
		}

		float t[numPartials];
		float amp[numPartials];
		float rands[numPartials];

		juce::Random rand;
		for (int i = 0; i < numPartials; i++)
		{
			t[i] = 0.0;
			amp[i] = 0.0;
			rands[i] = rand.nextFloat();
		}


		while (!threadShouldExit())
		{
			for (int i = 0; i < numPartials; i++)
			{
				amp[i] = (std::sin(t[i]) + 1) / 2;
				parameter = parent->getParam("partialFreq" + std::to_string(i));
				if (parameter)
					parameter->setValueNotifyingHost(amp[i]);

				parameter = parent->getParam("partialAmp" + std::to_string(i));
				if (parameter)
					parameter->setValueNotifyingHost(amp[i]);

				//t[i] += 0.00001 * (48 - i/2) ;
				//t[i] += 0.001 * i;
				//t[i] += 0.001 * rand.nextFloat();
				t[i] += 0.01 * rands[i];

				if (t[i] >= 2*juce::MathConstants<float>::pi)
					t[i] = 0.0;
			}
		}
	}
}
