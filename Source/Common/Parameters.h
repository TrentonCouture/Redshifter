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

	juce::AudioParameterFloat* getParamByIndex(int index)
	{
		int count = 0;
		for (auto it = m_floatParams.begin(); it != m_floatParams.end(); it++)
		{
			if (index == count)
				return it->second;
			count++;
		}

		return nullptr;
	}

	juce::AudioParameterChoice* getChoiceParam(std::string name)
	{
		return m_choiceParams.at(name);
	}

	auto getAllParams()
	{
		return m_floatParams;
	}

	auto getAllChoiceParams()
	{
		return m_choiceParams;
	}

private:
	ParamDescriptions m_paramDescs;
	std::map<std::string, juce::AudioParameterFloat*> m_floatParams;
	std::unordered_map<std::string, juce::AudioParameterChoice*> m_choiceParams;
};

