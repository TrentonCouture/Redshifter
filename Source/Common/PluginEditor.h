/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "WholeInterface.h"

//==============================================================================
/**
*/
class RedshifterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    RedshifterAudioProcessorEditor (RedshifterAudioProcessor&);
    ~RedshifterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;


	void updateFloatParameter(std::string name, float val)
	{
		audioProcessor.updateFloatParameter(name, val);
	}
	void updateChoiceParameter(std::string name)
	{
		audioProcessor.updateChoiceParameter(name);
	}
	juce::AudioParameterFloat* getParam(std::string name)
	{
		return audioProcessor.getParam(name);
	}

	juce::AudioParameterFloat* getParamByIndex(int index)
	{
		return audioProcessor.getParamByIndex(index);
	}

	juce::AudioParameterChoice* getChoiceParam(std::string name)
	{
		return audioProcessor.getChoiceParam(name);
	}


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
	WholeInterface m_wholeInterface;
    RedshifterAudioProcessor& audioProcessor;

	RSEngine* getEngine() { return &audioProcessor; }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RedshifterAudioProcessorEditor)
};
