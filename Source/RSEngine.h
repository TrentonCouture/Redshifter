/*
  ==============================================================================

    RSEngine.h
    Created: 27 Oct 2020 2:58:55pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "OscillatorEngine.h"
#include "Parameters.h"
#include "LFOs.h"

enum Effect
{
	reverb,
	chorus,
	filter,
	phaser,
	gain
};

class RSEngine
{
public:
	void initialize(const int sampleRate, const int numSamples, const int numChannels);
	void process(juce::AudioBuffer<float>& buffer, const juce::MidiBuffer& midiBuffer);
private:
	OscillatorEngine m_oscEng;
	juce::dsp::ProcessorChain < juce::dsp::Reverb, juce::dsp::Chorus<float>, juce::dsp::LadderFilter<float>, juce::dsp::Phaser<float>, juce::dsp::Gain<float>> m_effects;

	juce::dsp::Oscillator<float> m_lfo;

	Parameters m_params;
};
