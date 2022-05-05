/*
  ==============================================================================

    OscillatorSection.cpp
    Created: 28 Oct 2020 11:40:01pm
    Author:  Trenton

  ==============================================================================
*/

#include "OscillatorSection.h"
#include "PluginEditor.h"

OscillatorSection::OscillatorSection() : 
	m_oscButton("oscType1", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_oscButton2("oscType2", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey)

{
	m_oscMixSlider.setName("oscMix");
	addSlider(m_oscMixSlider);
	addButton(m_oscButton);
	addButton(m_oscButton2);

	for (int i = 0; i < m_numOscs; i++)
	{
		m_additiveLabel[i].setText("ADD", juce::NotificationType::dontSendNotification);
		m_additiveLabel[i].setColour(juce::Label::ColourIds::textColourId, juce::Colours::black);
		m_additiveLabel[i].setMinimumHorizontalScale(.1);
		m_additiveLabel[i].setBorderSize(juce::BorderSize<int>(0,0,0,0));
		addAndMakeVisible(m_additiveLabel[i]);
	}

	m_isLeft = true;
	m_initialized = false;
}

void OscillatorSection::parameterValueChanged(int parameterIndex, float newValue)
{
	repaint();
	GUISection::parameterValueChanged(parameterIndex, newValue);
}

void OscillatorSection::paint(juce::Graphics& g)
{
	if (!m_initialized)
	{
		auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
		if (parent)
		{
			auto oscType1 = parent->getChoiceParam("oscType1");
			auto oscType2 = parent->getChoiceParam("oscType2");
			if (oscType1 && oscType2)
			{
				oscType1->addListener(this);
				oscType2->addListener(this);
				m_initialized = true;
			}
		}
	}

	GUISection::paint(g);

	const float numOptions = 5.0;
	const float padding = 4.0;

	drawSineWave    (m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() * (1.0 / numOptions) - padding), g, 1);
	drawSineWave    (m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() * (1.0 / numOptions) - padding), g, 2);
	drawSawWave     (m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() * (2.0 / numOptions) - padding).withTop(m_icons1.getY() + m_icons1.getHeight() * (1.0 / numOptions)), g, 1);
	drawSawWave     (m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() * (2.0 / numOptions) - padding).withTop(m_icons2.getY() + m_icons2.getHeight() * (1.0 / numOptions)), g, 2);
	drawSquareWave  (m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() * (3.0 / numOptions) - padding).withTop(m_icons1.getY() + m_icons1.getHeight() * (2.0 / numOptions)), g, 1);
	drawSquareWave  (m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() * (3.0 / numOptions) - padding).withTop(m_icons2.getY() + m_icons2.getHeight() * (2.0 / numOptions)), g, 2);
	drawTriangleWave(m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() * (4.0 / numOptions) - padding).withTop(m_icons1.getY() + m_icons1.getHeight() * (3.0 / numOptions)), g, 1);
	drawTriangleWave(m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() * (4.0 / numOptions) - padding).withTop(m_icons2.getY() + m_icons2.getHeight() * (3.0 / numOptions)), g, 2);
	drawLabel		(m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() * (5.0 / numOptions) - padding).withTop(m_icons1.getY() + m_icons1.getHeight() * (4.0 / numOptions)),	 1);
	drawLabel		(m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() * (5.0 / numOptions) - padding).withTop(m_icons2.getY() + m_icons2.getHeight() * (4.0 / numOptions)),    2);
}

void OscillatorSection::drawLabel(juce::Rectangle<int> section, int side)
{
	m_additiveLabel[side-1].setBounds(section);

	juce::AudioParameterChoice* parameter;
	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
		parameter = parent->getChoiceParam("oscType" + std::to_string(side));

	if (parameter)
	{
		if (parameter->getCurrentChoiceName() == "additive")
			//g.setColour(juce::Colours::white);
			m_additiveLabel[side-1].setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
		else
			//g.setColour(juce::Colours::black);
			m_additiveLabel[side-1].setColour(juce::Label::ColourIds::textColourId, juce::Colours::black);
	}
	else
		//g.setColour(juce::Colours::black);
		m_additiveLabel[side-1].setColour(juce::Label::ColourIds::textColourId, juce::Colours::black);
}

void OscillatorSection::drawSineWave(juce::Rectangle<int> section, juce::Graphics& g, int side)
{
	juce::Path path;
	path.startNewSubPath((float)section.getX(), (float)section.getCentreY());
	path.quadraticTo(section.getX() + section.getWidth() / 4, section.getY(), section.getCentreX(), section.getCentreY());
	path.quadraticTo(section.getX() + section.getWidth() * (3.0 / 4.0), section.getBottom(), section.getRight(), section.getCentreY());

	juce::AudioParameterChoice* parameter;
	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
		parameter = parent->getChoiceParam("oscType" + std::to_string(side));

	if (parameter)
	{
		if (parameter->getCurrentChoiceName() == "sine")
			g.setColour(juce::Colours::white);
		else
			g.setColour(juce::Colours::black);
	}
	else
		g.setColour(juce::Colours::black);

	g.strokePath(path, juce::PathStrokeType(2.0));
}

void OscillatorSection::drawSawWave(juce::Rectangle<int> section, juce::Graphics& g, int side)
{
	juce::Path path;
	path.startNewSubPath((float)section.getX(), (float)section.getCentreY());
	path.lineTo(section.getCentreX(), section.getY());
	path.lineTo(section.getCentreX(), section.getY() + section.getHeight());
	path.lineTo(section.getX() + section.getWidth(), section.getCentreY());

	juce::AudioParameterChoice* parameter;
	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
		parameter = parent->getChoiceParam("oscType" + std::to_string(side));

	if (parameter)
	{
		if (parameter->getCurrentChoiceName() == "saw")
			g.setColour(juce::Colours::white);
		else
			g.setColour(juce::Colours::black);
	}
	else
		g.setColour(juce::Colours::black);

	g.strokePath(path, juce::PathStrokeType(2.0));
}

void OscillatorSection::drawSquareWave(juce::Rectangle<int> section, juce::Graphics& g, int side)
{
	juce::Path path;
	path.startNewSubPath((float)section.getX(), (float)section.getCentreY());
	path.lineTo(section.getTopLeft().toFloat());
	path.lineTo(section.getCentreX(), section.getY());
	path.lineTo(section.getCentreX(), section.getY() + section.getHeight());
	path.lineTo(section.getBottomRight().toFloat());
	path.lineTo(section.getX() + section.getWidth(), section.getCentreY());

	juce::AudioParameterChoice* parameter;
	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
		parameter = parent->getChoiceParam("oscType" + std::to_string(side));

	if (parameter)
	{
		if (parameter->getCurrentChoiceName() == "square")
			g.setColour(juce::Colours::white);
		else
			g.setColour(juce::Colours::black);
	}
	else
		g.setColour(juce::Colours::black);

	g.strokePath(path, juce::PathStrokeType(2.0));
}

void OscillatorSection::drawTriangleWave(juce::Rectangle<int> section, juce::Graphics& g, int side)
{
	juce::Path path;
	path.startNewSubPath((float)section.getX(), (float)section.getCentreY());
	path.lineTo(section.getX() + section.getWidth() / 4, section.getY());
	path.lineTo(section.getX() + section.getWidth() * (3.0 / 4.0), section.getY() + section.getHeight());
	path.lineTo(section.getX() + section.getWidth(), section.getCentreY());

	juce::AudioParameterChoice* parameter;
	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
		parameter = parent->getChoiceParam("oscType" + std::to_string(side));

	if (parameter)
	{
		if (parameter->getCurrentChoiceName() == "triangle")
			g.setColour(juce::Colours::white);
		else
			g.setColour(juce::Colours::black);
	}
	else
		g.setColour(juce::Colours::black);

	g.strokePath(path, juce::PathStrokeType(2.0));
}

void OscillatorSection::resized()
{
	auto area = getLocalBounds();

	const int labelHeight = 24;
	area.removeFromTop(labelHeight);

	const int sliderHeight = 50;
	const int numButtons = 2;
	const int iconWidth = 25;
	const int spacingWidth = (getWidth() - (m_oscButton.getWidth() * numButtons + iconWidth * numButtons + sliderHeight)) / 2;

	area.removeFromLeft(spacingWidth);

	m_icons1 = area.removeFromLeft(iconWidth);

	m_oscButton.setBounds(area.removeFromLeft(m_oscButton.getWidth()));
	m_oscMixSlider.setBounds(area.removeFromLeft(sliderHeight));
	m_oscButton2.setBounds(area.removeFromLeft(m_oscButton2.getWidth()));

	m_icons2 = area.removeFromLeft(iconWidth);
} 

