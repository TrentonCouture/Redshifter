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
	addSound(new RSSound);
}

void OscillatorEngine::initialize(const int sampleRate, const int numSamples, const int numChannels)
{
	setCurrentPlaybackSampleRate(sampleRate);
	setNoteStealingEnabled(true);

	if (getNumVoices() > 0)
	{
		for (int i = 0; i < 5; i++)
			removeVoice(0);
	}
	for (int i = 0; i < 5; i++)
		addVoice(new Oscillators(sampleRate, numSamples, numChannels));
}
