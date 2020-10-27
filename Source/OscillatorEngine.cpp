/*
  ==============================================================================

    RSEngine.cpp
    Created: 22 Oct 2020 8:17:30pm
    Author:  Trenton

  ==============================================================================
*/

#include "OscillatorEngine.h"


OscillatorEngine::OscillatorEngine()
{
	addSound(m_sound);
	addVoice(&m_oscs);
}

void OscillatorEngine::initialize(const int sampleRate, const int numSamples, const int numChannels)
{
	m_oscs.initialize(sampleRate, numSamples, numChannels);
	setCurrentPlaybackSampleRate(sampleRate);
}
