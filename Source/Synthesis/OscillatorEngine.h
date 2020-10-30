/*
  ==============================================================================

    RSEngine.h
    Created: 22 Oct 2020 8:17:30pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "RSSound.h"
#include "Oscillators.h"

class OscillatorEngine : public juce::Synthesiser
{
public:
	OscillatorEngine();
	void initialize(const int sampleRate, const int numSamples, const int numChannels);
private:
};
