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
	//addSound(&m_sound);
	//addVoice(&m_oscs);
	addSound(new RSSound);

}

void OscillatorEngine::initialize(const int sampleRate, const int numSamples, const int numChannels)
{
	setCurrentPlaybackSampleRate(sampleRate);

	if (getNumVoices() > 0)
		removeVoice(0);
	addVoice(new Oscillators(sampleRate, numSamples, numChannels));
}
