/*
  ==============================================================================

    GUISection.h
    Created: 27 Oct 2020 9:02:40pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "ParamDescription.h"
#include <vector>

class GUISection : public juce::Component,
	public juce::Slider::Listener,
	public juce::Button::Listener,
	public juce::AudioProcessorParameter::Listener
{
public:
	GUISection();
	void addSlider(juce::Slider& slider);
	void addButton(juce::ShapeButton& button);
	void paint(juce::Graphics& g) override;
	void resized() override;
	void sliderValueChanged(juce::Slider* slider) override;
	void buttonClicked(juce::Button* button) override;
	void parameterValueChanged(int parameterIndex, float newValue) override;
	void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override {};

protected:
	bool m_isLeft;

private:
	juce::OwnedArray<juce::Label> m_labels;
	ParamDescriptions m_paramDescs;

	bool m_isInitialized;
	bool m_parameterIsSet;
	std::vector<std::string> m_sliderNames;

};
