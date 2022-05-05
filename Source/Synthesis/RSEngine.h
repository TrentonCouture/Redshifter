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
	RSEngine();
	void initialize(const int sampleRate, const int numSamples, const int numChannels);
	void process(juce::AudioBuffer<float>& buffer, const juce::MidiBuffer& midiBuffer);
	void updateFloatParameter(std::string name, float val);
	void updateChoiceParameter(std::string name);
	juce::AudioParameterFloat* getParam(std::string name)
	{
		return m_params.getParam(name);
	}

	juce::AudioParameterFloat* getParamByIndex(int index)
	{
		return m_params.getParamByIndex(index);
	}

	juce::AudioParameterChoice* getChoiceParam(std::string name)
	{
		return m_params.getChoiceParam(name);
	}

protected:
	Parameters m_params;
private:
	OscillatorEngine m_oscEng;
	juce::dsp::ProcessorChain < juce::dsp::Reverb, juce::dsp::Chorus<float>, juce::dsp::LadderFilter<float>, juce::dsp::Phaser<float>, juce::dsp::Gain<float>> m_effects;
	juce::dsp::Oscillator<float> m_lfo;
};
