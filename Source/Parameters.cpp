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
	{ "attack", new juce::AudioParameterFloat("attack", "Attack", 0.1f, 1.0f, 0.5f) },
	{ "decay", new juce::AudioParameterFloat("decay", "Decay", 0.1f, 1.0f, 0.5f) },
	{ "sustain", new juce::AudioParameterFloat("sustain", "Sustain", 0.1f, 1.0f, 0.5f) },
	{ "release", new juce::AudioParameterFloat("release", "Release", 0.1f, 1.0f, 0.5f) },
	{ "roomSize", new juce::AudioParameterFloat("roomSize", "RoomSize", 0.0f, 1.0f, 0.5f) },
	{ "wet", new juce::AudioParameterFloat("wet", "Wet", 0.0f, 1.0f, 0.5f) },
	{ "chorusRate", new juce::AudioParameterFloat("chorusRate", "ChorusRate", 0.0f, 1.0f, 0.5f) },
	{ "chorusDepth", new juce::AudioParameterFloat("chorusDepth", "ChorusDepth", 0.0f, 1.0f, 0.5f) },
	{ "chorusMix", new juce::AudioParameterFloat("chorusMix", "ChorusMix", 0.0f, 1.0f, 0.5f) },
	{ "cutoff", new juce::AudioParameterFloat("cutoff", "Cutoff", 0.001f, 1.0f, 0.5f) },
	{ "resonance", new juce::AudioParameterFloat("resonance", "Resonance", 0.0f, 1.0f, 0.5f) },
	{ "filterDrive", new juce::AudioParameterFloat("filterDrive", "FilterDrive", 0.0f, 1.0f, 0.5f) },
	{ "phaserRate", new juce::AudioParameterFloat("phaserRate", "PhaserRate", 0.0f, 1.0f, 0.5f) },
	{ "phaserDepth", new juce::AudioParameterFloat("phaserDepth", "PhaserDepth", 0.0f, 1.0f, 0.5f) },
	{ "phaserMix", new juce::AudioParameterFloat("phaserMix", "PhaserMix", 0.0f, 1.0f, 0.5f) },
	{ "gain", new juce::AudioParameterFloat("gain", "Gain", 0.0f, 1.0f, 0.5f) }
	});
