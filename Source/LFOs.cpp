/*
  ==============================================================================

    LFOs.cpp
    Created: 29 Oct 2020 11:30:58am
    Author:  Trenton

  ==============================================================================
*/

#include "LFOs.h"

void LFOs::initialize(const int sampleRate, const int numSamples, const int numChannels)
{
	juce::dsp::ProcessSpec pSpec;
	pSpec.maximumBlockSize = numSamples;
	pSpec.sampleRate = sampleRate;
	pSpec.numChannels = numChannels;

	m_lfo.prepare(pSpec);

	m_lfo.initialise([](float x) {return 1 + 0.5 * std::sin(x); });

	m_lfo.setFrequency(500);
}

void LFOs::process(juce::dsp::LadderFilter<float>& filter)
{
	auto lfoGain = m_lfo.processSample(0.0);

	const float maxCutoff = 20000;
	filter.setCutoffFrequencyHz(lfoGain * *m_params.getParam("cutoff") * maxCutoff);
	filter.setResonance(*m_params.getParam("resonance"));
	filter.setDrive(*m_params.getParam("filterDrive") * 10 + 1);
}
