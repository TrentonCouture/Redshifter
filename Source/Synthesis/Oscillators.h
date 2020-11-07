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

enum OscType
{
	sine,
	saw,
	square,
	triangle
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
	typedef juce::dsp::ProcessorChain<juce::dsp::Oscillator<float>, juce::dsp::Gain<float>> OscWithGain;

	void processOsc(OscWithGain& osc, juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);
	void checkIfNewBufferParams(int numChannels, int numSamples);


	OscWithGain m_sinOsc1;
	OscWithGain m_sawOsc1;
	OscWithGain m_squareOsc1;
	OscWithGain m_triOsc1;

	OscWithGain m_sinOsc2;
	OscWithGain m_sawOsc2;
	OscWithGain m_squareOsc2;
	OscWithGain m_triOsc2;

	juce::ADSR m_adsr;
	Parameters* m_params;

	OscType m_oscType1;
	OscType m_oscType2;

	int m_sampleRate;
	int m_numChannels;
	int m_numSamples;
};

