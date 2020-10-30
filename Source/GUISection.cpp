/*
  ==============================================================================

    GUISection.cpp
    Created: 27 Oct 2020 9:02:40pm
    Author:  Trenton

  ==============================================================================
*/

#include "GUISection.h"
#include "PluginEditor.h"

//GUISection::GUISection()
//{
//	//m_isLeft = true;
//}

void GUISection::addSlider(juce::Slider& slider)
{
	addAndMakeVisible(slider);

	m_labels.add(new juce::Label());
	m_labels.getLast()->attachToComponent(&slider, false);
	m_labels.getLast()->setText(slider.getName().toStdString(), juce::NotificationType::dontSendNotification);

	addAndMakeVisible(*m_labels.getLast());

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

	juce::ColourGradient gradient;
	gradient.point1 = inner.getTopLeft().toFloat();
	gradient.point2 = inner.getBottomRight().toFloat();

	if (m_isLeft)
	{
		gradient.addColour(0, juce::Colours::black);
		gradient.addColour(0.2, juce::Colours::darkred);
		gradient.addColour(1.0, juce::Colours::darkred);
	}
	else
	{
		gradient.addColour(0, juce::Colours::darkred);
		gradient.addColour(0.9, juce::Colours::darkred);
		gradient.addColour(1.0, juce::Colours::crimson);
	}

	g.setGradientFill(gradient);
	g.fillRoundedRectangle(inner.toFloat(), 20.0);


}
