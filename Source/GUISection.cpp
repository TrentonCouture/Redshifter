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
	auto range = m_params.getParam(slider.getName().toStdString())->getNormalisableRange();
	slider.setRange(range.start, range.end);
	slider.addListener(this);
}

void GUISection::sliderValueChanged(juce::Slider* slider)
{
	auto name = slider->getName().toStdString();
	//auto editorPtr = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	//if (editorPtr)
	//	editorPtr->getEngine()->

	m_params.getParam(name)->setValueNotifyingHost(slider->getValue());
}
