/*
  ==============================================================================

    OscillatorSection.cpp
    Created: 28 Oct 2020 11:40:01pm
    Author:  Trenton

  ==============================================================================
*/

#include "OscillatorSection.h"

OscillatorSection::OscillatorSection() : 
	m_oscButton("oscType1", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey),
	m_oscButton2("oscType2", juce::Colours::black, juce::Colours::grey, juce::Colours::darkgrey)

{
	m_oscMixSlider.setName("oscMix");
	addSlider(m_oscMixSlider);
	addButton(m_oscButton);
	addButton(m_oscButton2);

	m_isLeft = true;
}

void OscillatorSection::paint(juce::Graphics& g)
{
	GUISection::paint(g);

	drawSineWave(m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() / 4), g, 1);
	drawSineWave(m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() / 4), g, 2);
	drawSawWave(m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() / 2 - 2).withTop(m_icons1.getY() + m_icons1.getHeight() / 4), g, 1);
	drawSawWave(m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() / 2 - 2).withTop(m_icons2.getY() + m_icons2.getHeight() / 4), g, 2);
	drawSquareWave(m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() * (3.0 / 4.0)).withTop(m_icons1.getY() + m_icons1.getHeight() / 2 + 2), g, 1);
	drawSquareWave(m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() * (3.0 / 4.0)).withTop(m_icons2.getY() + m_icons2.getHeight() / 2 + 2), g, 2);
	drawTriangleWave(m_icons1.withBottom(m_icons1.getY() + m_icons1.getHeight() - 2).withTop(m_icons1.getY() + m_icons1.getHeight() * (3.0 / 4.0)), g, 1);
	drawTriangleWave(m_icons2.withBottom(m_icons2.getY() + m_icons2.getHeight() - 2).withTop(m_icons2.getY() + m_icons2.getHeight() * (3.0 / 4.0)), g, 2);
}

void OscillatorSection::drawSineWave(juce::Rectangle<int> section, juce::Graphics& g, int side)
{
	juce::Path path;
	path.startNewSubPath((float)section.getX(), (float)section.getCentreY());
	path.quadraticTo(section.getX() + section.getWidth() / 4, section.getY(), section.getCentreX(), section.getCentreY());
	path.quadraticTo(section.getX() + section.getWidth() * (3.0 / 4.0), section.getBottom(), section.getRight(), section.getCentreY());

	if (m_params.getChoiceParam("oscType" + std::to_string(side))->getCurrentChoiceName() == "sine")
		g.setColour(juce::Colours::white);
	else
		g.setColour(juce::Colours::black);

	g.strokePath(path, juce::PathStrokeType(2.0));
	repaint();
}

void OscillatorSection::drawSawWave(juce::Rectangle<int> section, juce::Graphics& g, int side)
{
	juce::Path path;
	path.startNewSubPath((float)section.getX(), (float)section.getCentreY());
	path.lineTo(section.getCentreX(), section.getY());
	path.lineTo(section.getCentreX(), section.getY() + section.getHeight());
	path.lineTo(section.getX() + section.getWidth(), section.getCentreY());

	if (m_params.getChoiceParam("oscType" + std::to_string(side))->getCurrentChoiceName() == "saw")
		g.setColour(juce::Colours::white);
	else
		g.setColour(juce::Colours::black);

	g.strokePath(path, juce::PathStrokeType(2.0));
	repaint();
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

	if (m_params.getChoiceParam("oscType" + std::to_string(side))->getCurrentChoiceName() == "square")
		g.setColour(juce::Colours::white);
	else
		g.setColour(juce::Colours::black);

	g.strokePath(path, juce::PathStrokeType(2.0));
	repaint();
}

void OscillatorSection::drawTriangleWave(juce::Rectangle<int> section, juce::Graphics& g, int side)
{
	juce::Path path;
	path.startNewSubPath((float)section.getX(), (float)section.getCentreY());
	path.lineTo(section.getX() + section.getWidth() / 4, section.getY());
	path.lineTo(section.getX() + section.getWidth() * (3.0 / 4.0), section.getY() + section.getHeight());
	path.lineTo(section.getX() + section.getWidth(), section.getCentreY());

	if (m_params.getChoiceParam("oscType" + std::to_string(side))->getCurrentChoiceName() == "triangle")
		g.setColour(juce::Colours::white);
	else
		g.setColour(juce::Colours::black);

	g.strokePath(path, juce::PathStrokeType(2.0));
	repaint();
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

