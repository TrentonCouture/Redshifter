/*
  ==============================================================================

    GUISection.cpp
    Created: 27 Oct 2020 9:02:40pm
    Author:  Trenton

  ==============================================================================
*/

#include "GUISection.h"
#include "PluginEditor.h"

GUISection::GUISection()
{
	m_isInitialized = false;
	m_parameterIsSet = false;
}

void GUISection::addSlider(juce::Slider& slider)
{
	//addAndMakeVisible(slider);
	addChildAndSetID(&slider, slider.getName());

	m_labels.add(new juce::Label());

	addAndMakeVisible(*m_labels.getLast());

	m_sliderNames.push_back(slider.getName().toStdString());

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
	if (parent && !m_parameterIsSet)
	{
		parent->getEngine()->updateFloatParameter(name, slider->getValue());
	}
	m_parameterIsSet = false;
}

void GUISection::buttonClicked(juce::Button* button)
{
	auto name = button->getName().toStdString();

	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
		parent->getEngine()->updateChoiceParameter(name);
}

void GUISection::setSlider(std::string name, float value)
{
	auto slider = dynamic_cast<juce::Slider*>(findChildWithID(name));
	if (slider)
	{
		slider->setValue(value);
		m_parameterIsSet = true;
	}
}

void GUISection::parameterValueChanged(int parameterIndex, float newValue)
{
	auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
	if (parent)
	{
	    auto param = parent->getEngine()->getParamByIndex(parameterIndex);
	    if (param)
	    {
			auto slider = dynamic_cast<juce::Slider*>(findChildWithID(param->paramID));
			if (slider)
			{
				slider->setValue(newValue);
				m_parameterIsSet = true;
			}
	    }
	  
	}
	//switch (parameterIndex) 
	//{
	//case 0:
	//	setSlider("attack", newValue);
	//	break;
	//case 1:
	//	setSlider("decay", newValue);
	//	break;
	//case 2:
	//	setSlider("sustain", newValue);
	//	break;
	//case 3:
	//	setSlider("release", newValue);
	//	break;
	//case 4:
	//	setSlider("roomSize", newValue);
	//	break;
	//case 5:
	//	setSlider("wet", newValue);
	//	break;
	//case 6:
	//	setSlider("chorusRate", newValue);
	//	break;
	//case 7:
	//	setSlider("chorusDepth", newValue);
	//	break;
	//case 8:
	//	setSlider("chorusMix", newValue);
	//	break;
	//case 9:
	//	setSlider("cutoff", newValue);
	//	break;
	//case 10:
	//	setSlider("resonance", newValue);
	//	break;
	//case 11:
	//	setSlider("filterDrive", newValue);
	//	break;
	//case 12:
	//	setSlider("phaserRate", newValue);
	//	break;
	//case 13:
	//	setSlider("phaserDepth", newValue);
	//	break;
	//case 14:
	//	setSlider("phaserMix", newValue);
	//	break;
	//case 15:
	//	setSlider("gain", newValue);
	//	break;
	//case 16:
	//	setSlider("oscMix", newValue);
	//	break;
	//case 17:
	//	setSlider("lfoFilterFreq", newValue);
	//	break;
	//case 18:
	//	setSlider("lfoFilterAmp", newValue);
	//	break;
	//}
}

void GUISection::paint(juce::Graphics& g)
{
	if (!m_isInitialized)
	{
		auto parent = findParentComponentOfClass<RedshifterAudioProcessorEditor>();
		if (parent)
		{
			for (auto& name : m_sliderNames)
			{
				auto param = parent->getEngine()->getParam(name);
				if (param)
				{
					param->addListener(this);
					m_isInitialized = true;
				}
			}
		}
	}

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
