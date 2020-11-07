/*
  ==============================================================================

    RSEngine.cpp
    Created: 22 Oct 2020 8:17:30pm
    Author:  Trenton

  ==============================================================================
*/

#include "OscillatorEngine.h"


OscillatorEngine::OscillatorEngine(Parameters* params)
{
	addSound(new RSSound);
	for (int i = 0; i < 8; i++)
		addVoice(new Oscillators(params));
}

void OscillatorEngine::initialize(const int sampleRate)
{
	setCurrentPlaybackSampleRate(sampleRate);
	setNoteStealingEnabled(true);
}
