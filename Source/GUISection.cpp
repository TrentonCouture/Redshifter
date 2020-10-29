/*
  ==============================================================================

    GUISection.cpp
    Created: 27 Oct 2020 9:02:40pm
    Author:  Trenton

  ==============================================================================
*/

#include "GUISection.h"
#include "PluginEditor.h"

void GUISection::addSlider(juce::Slider& slider)
{
	addAndMakeVisible(slider);
	auto parameter = m_params.getParam(slider.getName().toStdString());
	auto range = parameter->getNormalisableRange();
	slider.setRange(range.start, range.end);
	slider.setValue(parameter->get());

	slider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	slider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
	slider.addListener(this);
}

void GUISection::sliderValueChanged(juce::Slider* slider)
{
	auto name = slider->getName().toStdString();

	m_params.getParam(name)->setValueNotifyingHost(slider->getValue());
}

void GUISection::paint(juce::Graphics& g)
{
	juce::BorderSize<int> border(1, 1, 1, 1);
	auto inner = border.subtractedFrom(getLocalBounds());

	g.setColour(juce::Colours::black);
	g.fillRect(inner);

	//g.fillAll(juce::Colours::black);
}
