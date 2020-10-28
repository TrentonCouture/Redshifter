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
	m_attackSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	m_attackSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
	addSlider(m_attackSlider);

	m_decaySlider.setName("decay");
	m_decaySlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	m_decaySlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
	addSlider(m_decaySlider);

	m_sustainSlider.setName("sustain");
	m_sustainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	m_sustainSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
	addSlider(m_sustainSlider);

	m_releaseSlider.setName("release");
	m_releaseSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	m_releaseSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
	addSlider(m_releaseSlider);
}

void EnvSection::paint(juce::Graphics& g)
{
	g.fillAll(juce::Colours::black);
}

void EnvSection::resized()
{
	auto area = getLocalBounds();
	const int sliderHeight = 100;
	m_attackSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_decaySlider.setBounds(area.removeFromLeft(sliderHeight));
	m_sustainSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_releaseSlider.setBounds(area.removeFromLeft(sliderHeight));
}
