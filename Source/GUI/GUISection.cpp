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

	m_labels.add(new juce::Label());

	addAndMakeVisible(*m_labels.getLast());

	slider.setRange(m_paramDescs.getParam(slider.getName().toStdString()).lowVal, m_paramDescs.getParam(slider.getName().toStdString()).highVal);
	slider.setValue(m_paramDescs.getParam(slider.getName().toStdString()).defaultVal);

	slider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	slider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
	slider.addListener(this);

	m_labels.getLast()->attachToComponent(&slider, false);
	m_labels.getLast()->setText(m_paramDescs.getParam(slider.getName().toStdString()).name, juce::NotificationType::dontSendNotification);
}

void GUISection::addButton(juce::ShapeButton& button)
{
	addAndMakeVisible(button);

	juce::Path buttonPath;
	buttonPath.addRectangle(0, 0, 15, 7);
	button.setShape(buttonPath, true, true, true);
	button.addListener(this);
}

void GUISection::sliderValueChanged(juce::Slider* slider)
{
	auto name = slider->getName().toStdString();

	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
		parent->getEngine()->updateFloatParameter(name, slider->getValue());
}

void GUISection::buttonClicked(juce::Button* button)
{
	auto name = button->getName().toStdString();

	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
		parent->getEngine()->updateChoiceParameter(name);
}

void GUISection::paint(juce::Graphics& g)
{
	juce::BorderSize<int> border(1, 1, 1, 1);
	auto inner = border.subtractedFrom(getLocalBounds());

	juce::ColourGradient gradient;
	gradient.point1 = inner.getTopLeft().toFloat();
	gradient.point2 = inner.getBottomRight().toFloat();

	if (m_isLeft)
	{
		gradient.addColour(0, juce::Colours::black);
		gradient.addColour(0.1, juce::Colours::darkred);
		gradient.addColour(1.0, juce::Colours::darkred);
	}
	else
	{
		gradient.addColour(0, juce::Colours::darkred);
		gradient.addColour(0.9, juce::Colours::darkred);
		gradient.addColour(1.0, juce::Colours::black);
	}

	g.setGradientFill(gradient);
	g.fillRoundedRectangle(inner.toFloat(), 20.0);


}
