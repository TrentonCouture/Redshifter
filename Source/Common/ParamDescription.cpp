/*
  ==============================================================================

    ParamDescription.cpp
    Created: 6 Nov 2020 10:14:29pm
    Author:  Trenton

  ==============================================================================
*/

#include "ParamDescription.h"

ParamDescriptions::ParamDescriptions() :
	m_paramDescs({
	{ "attack", { ParamType::floatType, "attack", "Attack", 0.003f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "decay", { ParamType::floatType, "decay", "Decay", 0.05f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "sustain", { ParamType::floatType, "sustain", "Sustain", 0.01f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "release", { ParamType::floatType, "release", "Release", 0.01f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "roomSize", { ParamType::floatType, "roomSize", "Room", 0.0f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "wet", { ParamType::floatType, "wet", "Reverb", 0.0f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "chorusRate", { ParamType::floatType, "chorusRate", "Rate", 0.0f, 1.0f, 0.2f, {""}, 0, 0} },
	{ "chorusDepth", { ParamType::floatType, "chorusDepth", "Depth", 0.0f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "chorusMix", { ParamType::floatType, "chorusMix", "Chorus", 0.0f, 1.0f, 0.0f, {""}, 0, 0} },
	{ "cutoff", { ParamType::floatType, "cutoff", "Cutoff", 0.001f, 1.0f, 0.1f, {""}, 0, 0} },
	{ "resonance", { ParamType::floatType, "resonance", "ResLvl", 0.0f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "filterDrive", { ParamType::floatType, "filterDrive", "Drive", 0.0f, 1.0f, 0.0f, {""}, 0, 0} },
	{ "phaserRate", { ParamType::floatType, "phaserRate", "Rate", 0.0f, 1.0f, 0.2f, {""}, 0, 0} },
	{ "phaserDepth", { ParamType::floatType, "phaserDepth", "Depth", 0.0f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "phaserMix", { ParamType::floatType, "phaserMix", "Phaser", 0.0f, 1.0f, 0.0f, {""}, 0, 0} },
	{ "gain", { ParamType::floatType, "gain", "GainLvl", 0.0f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "oscMix", { ParamType::floatType, "oscMix", "OscMix", 0.0f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "lfoFilterFreq", { ParamType::floatType, "lfoFilterFreq", "LfoRate", 0.0f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "lfoFilterAmp", { ParamType::floatType, "lfoFilterAmp", "LfoAmp", 0.1f, 1.0f, 0.5f, {""}, 0, 0} },
	{ "oscType1", { ParamType::choiceType, "oscType1", "OscType1", 0, 0, 0, {"sine", "saw", "square", "triangle", "additive"}, 5, 0 }},
	{ "oscType2", { ParamType::choiceType, "oscType2", "OscType2", 0, 0, 0, {"sine", "saw", "square", "triangle", "additive"}, 5, 0 }}
	})
{
	const int numPartials = 42;

	for (int i = 0; i < numPartials; i++)
	{
		m_paramDescs.insert({ "partialAmp" + std::to_string(i), { ParamType::floatType, "partialAmp" + std::to_string(i), "PartialAmp" + std::to_string(i), 0.0f, 1.0f, 0.5f, {""}, 0, 0} });
		m_paramDescs.insert({ "partialFreq" + std::to_string(i), { ParamType::floatType, "partialFreq" + std::to_string(i), "PartialFreq" + std::to_string(i), 0.0f, 1.0f, 0.5f, {""}, 0, 0} });
	}
}
