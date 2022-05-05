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
#include "StandardOscillator.h"
#include "AdditiveOscillator.h"

enum Osc
{
	osc,
	vol
};

enum OscType
{
	sine,
	saw,
	square,
	triangle,
	additive
};

class Oscillators : public juce::SynthesiserVoice, public juce::AudioProcessorParameter::Listener
{
public:
	Oscillators(Parameters* params);
	bool canPlaySound(juce::SynthesiserSound*) override { return true; }
	void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
	void controllerMoved(int, int) override {}
	void pitchWheelMoved(int) override {}
	void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
	void stopNote(float velocity, bool tailOff) override;
	float noteToFreq(const int note);
	void parameterValueChanged(int parameterIndex, float newValue) override;
	void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override {};
	void setCurrentPlaybackSampleRate(double newRate) override;

private:
	void processOsc(juce::dsp::ProcessorBase& osc, juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples, int oscNum);
	void checkIfNewBufferParams(int numChannels, int numSamples);

	StandardOscillator m_sinOsc[2];
	StandardOscillator m_sawOsc[2];
	StandardOscillator m_squareOsc[2];
	StandardOscillator m_triOsc[2];

	AdditiveOscillator m_addOsc[2];

	const int m_numOsc = 2;
	juce::ADSR m_adsr[2];
	Parameters* m_params;

	OscType m_oscType[2];

	int m_sampleRate;
	int m_numChannels;
	int m_numSamples;
};

