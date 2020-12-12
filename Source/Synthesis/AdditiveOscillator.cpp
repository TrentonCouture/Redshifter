/*
  ==============================================================================

    AdditiveOscillator.cpp
    Created: 6 Dec 2020 5:54:29pm
    Author:  Trent

  ==============================================================================
*/

#include "AdditiveOscillator.h"

void AdditiveProcessor::initialise(Parameters* params)
{
    m_params = params;
	m_osc.initialise([](float x) { return 0.1 * std::sin(x); }, 128);
}

void AdditiveProcessor::setFrequency(float newFreq, bool force)
{
    m_osc.setFrequency(newFreq, force);
}

void AdditiveProcessor::prepare(const juce::dsp::ProcessSpec& spec)
{
    m_osc.prepare(spec);
}

void AdditiveProcessor::process(const juce::dsp::ProcessContextReplacing<float>& context)
{
    m_osc.process(context);
}

void AdditiveProcessor::reset()
{
    m_osc.reset();
}
