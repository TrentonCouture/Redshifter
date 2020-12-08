/*
  ==============================================================================

    ParamDescription.h
    Created: 6 Nov 2020 10:14:29pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <unordered_map>

enum ParamType
{
	floatType,
	choiceType
};

struct ParamDescription
{
	ParamType type;
	std::string id;
	std::string name;

	float lowVal;
	float highVal;
	float defaultVal;

	std::string choices[10];
	int numChoices;
	int defaultIndex;
};

class ParamDescriptions
{
public:
	ParamDescriptions();
	ParamDescription getParam(std::string name)
	{
		return m_paramDescs.at(name);
	}

	std::map<std::string, ParamDescription> getAllParams()
	{
		return m_paramDescs;
	}

private:
	std::map<std::string, ParamDescription> m_paramDescs;
};
