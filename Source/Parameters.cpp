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
}

std::unordered_map<std::string, juce::AudioParameterFloat*> Parameters::m_floatParams({ 
	{ "attack", new juce::AudioParameterFloat("attack", "Attack", 0.1f, 1.0f, 0.2f) }
	});
