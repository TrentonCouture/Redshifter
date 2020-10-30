/*
  ==============================================================================

    Oscillators.h
    Created: 23 Oct 2020 12:58:56pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Parameters.h"

enum Osc
{
	osc,
	vol
};

class Oscillators : public juce::SynthesiserVoice
{
public:
	Oscillators(const int sampleRate, const int numSamples, const int numChannels);
	bool canPlaySound(juce::SynthesiserSound*) override { return true; }
	void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
	void controllerMoved(int, int) override {}
	void pitchWheelMoved(int) override {}
	void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
	void stopNote(float velocity, bool tailOff) override;
	float noteToFreq(const int note);
private:
	juce::dsp::ProcessorChain<juce::dsp::Oscillator<float>, juce::dsp::Gain<float>> m_sinOsc;
	juce::dsp::ProcessorChain<juce::dsp::Oscillator<float>, juce::dsp::Gain<float>> m_sawOsc;
	juce::ADSR m_adsr;
	Parameters m_params;
};
