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
	{ "roomSize", new juce::AudioParameterFloat("roomSize", "Room", 0.0f, 1.0f, 0.5f) },
	{ "wet", new juce::AudioParameterFloat("wet", "Reverb", 0.0f, 1.0f, 0.5f) },
	{ "chorusRate", new juce::AudioParameterFloat("chorusRate", "Rate", 0.0f, 1.0f, 0.5f) },
	{ "chorusDepth", new juce::AudioParameterFloat("chorusDepth", "Depth", 0.0f, 1.0f, 0.5f) },
	{ "chorusMix", new juce::AudioParameterFloat("chorusMix", "Chorus", 0.0f, 1.0f, 0.5f) },
	{ "cutoff", new juce::AudioParameterFloat("cutoff", "Cutoff", 0.001f, 1.0f, 0.5f) },
	{ "resonance", new juce::AudioParameterFloat("resonance", "ResLvl", 0.0f, 1.0f, 0.5f) },
	{ "filterDrive", new juce::AudioParameterFloat("filterDrive", "Drive", 0.0f, 1.0f, 0.5f) },
	{ "phaserRate", new juce::AudioParameterFloat("phaserRate", "Rate", 0.0f, 1.0f, 0.5f) },
	{ "phaserDepth", new juce::AudioParameterFloat("phaserDepth", "Depth", 0.0f, 1.0f, 0.5f) },
	{ "phaserMix", new juce::AudioParameterFloat("phaserMix", "Phaser", 0.0f, 1.0f, 0.5f) },
	{ "gain", new juce::AudioParameterFloat("gain", "GainLvl", 0.0f, 1.0f, 0.5f) },
	{ "oscMix", new juce::AudioParameterFloat("oscMix", "OscMix", 0.0f, 1.0f, 0.5f) },
	{ "lfoFilterFreq", new juce::AudioParameterFloat("lfoFilterFreq", "LfoRate", 0.0f, 1.0f, 0.5f) },
	{ "lfoFilterAmp", new juce::AudioParameterFloat("lfoFilterAmp", "LfoAmp", 0.1f, 1.0f, 0.5f) }
	});
