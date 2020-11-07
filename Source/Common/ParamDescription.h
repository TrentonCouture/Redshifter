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
	//ParamDescription() : type(floatType), id(""), name(""), lowVal(0), highVal(0), defaultVal(0), defaultIndex(0) {}
	ParamType type;
	std::string id;
	std::string name;

	float lowVal;
	float highVal;
	float defaultVal;

	std::string choices[10];
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

	std::unordered_map<std::string, ParamDescription> getAllParams()
	{
		return m_paramDescs;
	}

private:
	const std::unordered_map<std::string, ParamDescription> m_paramDescs;
};
