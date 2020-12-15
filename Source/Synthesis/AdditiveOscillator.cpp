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

    for (int i = 0; i < m_numPartials; i++)
    {
        m_oscs.add(new juce::dsp::ProcessorChain<juce::dsp::Oscillator<float>, juce::dsp::Gain<float>>());
        m_oscs[i]->get<0>().initialise([this](float x) { return (0.4 / m_numPartials) * std::sin(x); }, 128);
        m_oscs[i]->get<1>().setGainLinear(1.0);
    }
}

void AdditiveProcessor::initialiseOscs()
{
    for (int i = 0; i < m_numPartials; i++)
        m_oscs[i]->get<1>().setGainLinear(m_params->getParam("partialAmp" + std::to_string(i))->get());
}

void AdditiveProcessor::modulateFrequency()
{
    for (int i = 0; i < m_numPartials; i++)
        m_oscs[i]->get<0>().setFrequency(m_currentFreq * (i + 1) + 100 * (-0.5 + m_params->getParam("partialFreq" + std::to_string(i))->get()));
        //m_oscs[i]->get<0>().setFrequency(m_currentFreq);
}

void AdditiveProcessor::setFrequency(float newFreq, bool force)
{
    m_currentFreq = newFreq;
    for (int i = 0; i < m_numPartials; i++)
        m_oscs[i]->get<0>().setFrequency(newFreq * (i + 1), force);
}

void AdditiveProcessor::prepare(const juce::dsp::ProcessSpec& spec)
{
    for (int i = 0; i < m_numPartials; i++)
        m_oscs[i]->prepare(spec);
}

void AdditiveProcessor::process(const juce::dsp::ProcessContextReplacing<float>& context)
{
    for (int i = 0; i < m_numPartials; i++)
    {
	    juce::AudioBuffer<float> tempBuffer(context.getInputBlock().getNumChannels(), context.getInputBlock().getNumSamples());
	    tempBuffer.clear();
	    auto wholeBlock = juce::dsp::AudioBlock<float>(tempBuffer);
	    auto block = wholeBlock.getSubBlock(0, (size_t)context.getInputBlock().getNumSamples());
	    juce::dsp::ProcessContextReplacing<float> tempContext(block);
        m_oscs[i]->process(tempContext);

        context.getOutputBlock().add(tempContext.getOutputBlock());
    }
}

void AdditiveProcessor::reset()
{
    for (int i = 0; i < m_numPartials; i++)
        m_oscs[i]->reset();
}
