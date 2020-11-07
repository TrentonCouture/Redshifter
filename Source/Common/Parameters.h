/*
  ==============================================================================

    Parameters.h
    Created: 27 Oct 2020 6:31:52pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <unordered_map>

#include "ParamDescription.h"


class Parameters
{
public:
	Parameters();
	juce::AudioParameterFloat* getParam(std::string name)
	{
		return m_floatParams.at(name);
	}

	juce::AudioParameterChoice* getChoiceParam(std::string name)
	{
		return m_choiceParams.at(name);
	}

	std::unordered_map<std::string, juce::AudioParameterFloat*> getAllParams()
	{
		return m_floatParams;
	}

	std::unordered_map<std::string, juce::AudioParameterChoice*> getAllChoiceParams()
	{
		return m_choiceParams;
	}

private:
	ParamDescriptions m_paramDescs;
	std::unordered_map<std::string, juce::AudioParameterFloat*> m_floatParams;
	std::unordered_map<std::string, juce::AudioParameterChoice*> m_choiceParams;
};

