/*
  ==============================================================================

    Parameters.cpp
    Created: 27 Oct 2020 6:31:53pm
    Author:  Trenton

  ==============================================================================
*/

#include "Parameters.h"

Parameters::Parameters()
{
	for (auto& param : m_paramDescs.getAllParams())
	{
		switch (param.second.type) {
		case ParamType::floatType:
			m_floatParams[param.first] = new juce::AudioParameterFloat(param.second.id, param.second.name, param.second.lowVal, param.second.highVal, param.second.defaultVal);
			break;
		case ParamType::choiceType:
			juce::StringArray strArray;
			for (int i = 0; i < param.second.numChoices; i++)
				strArray.add(param.second.choices[i]);
			m_choiceParams[param.first] = new juce::AudioParameterChoice(param.second.id, param.second.name, strArray, param.second.defaultIndex);
			break;
		}
	}
}
