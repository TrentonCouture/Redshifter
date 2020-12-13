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
	//m_osc.initialise([](float x) { return 0.1 * std::sin(x); }, 128);

    for (int i = 0; i < 1; i++)
    for (int i = 0; i < m_numPartials; i++)
    {
        //m_oscs.add(new juce::dsp::Oscillator<float>());
        //m_oscs[i]->initialise([this](float x) { return (0.4 / m_numPartials) * std::sin(x); }, 128);
        m_oscs.add(new juce::dsp::ProcessorChain<juce::dsp::Oscillator<float>, juce::dsp::Gain<float>>());
        m_oscs[i]->get<0>().initialise([this](float x) { return (0.4 / m_numPartials) * std::sin(x); }, 128);
        m_oscs[i]->get<1>().setGainLinear(1.0);
        //m_testGain = m_oscs[i]->get<1>().getGainLinear();
    }
}

void AdditiveProcessor::initialiseOscs()
{
    DBG("called");
    for (int i = 0; i < m_numPartials; i++)
    {
        m_oscs[i]->get<1>().setGainLinear(m_params->getParam("partialAmp" + std::to_string(i))->get());
        //auto val = m_oscs[i]->get<1>().getGainLinear();
        //m_numPartials += val;
    }
        //m_oscs[i]->initialise([&i, this](float x) { return (0.4 * m_params->getParam("partialAmp" + std::to_string(i))->get() / m_numPartials) * std::sin(x); }, 128);
}

void AdditiveProcessor::setFrequency(float newFreq, bool force)
{
    //m_osc.setFrequency(newFreq, force);

    for (int i = 0; i < m_numPartials; i++)
        //m_oscs[i]->setFrequency(newFreq * (i + 1), force);
        m_oscs[i]->get<0>().setFrequency(newFreq * (i + 1), force);
}

void AdditiveProcessor::prepare(const juce::dsp::ProcessSpec& spec)
{
    //m_osc.prepare(spec);
    for (int i = 0; i < m_numPartials; i++)
        //m_oscs[i]->prepare(spec);
        m_oscs[i]->prepare(spec);
}

void AdditiveProcessor::process(const juce::dsp::ProcessContextReplacing<float>& context)
{
    //m_osc.process(context);
    //for (int i = 0; i < m_numPartials; i++)
    //    m_oscs[i]->process(context);

	//juce::AudioBuffer<float> tempBuffer(outputBuffer.getNumChannels(), outputBuffer.getNumSamples());
	//tempBuffer.clear();
	//auto wholeBlock = juce::dsp::AudioBlock<float>(tempBuffer);
	//auto block = wholeBlock.getSubBlock(startSample, (size_t)numSamples);
	//juce::dsp::ProcessContextReplacing<float> context(block);

	//osc.process(context);

	//m_adsr[oscNum].applyEnvelopeToBuffer(tempBuffer, startSample, numSamples);

	//for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
	//	outputBuffer.addFrom(channel, startSample, tempBuffer, channel, startSample, numSamples);
}

void AdditiveProcessor::reset()
{
    //m_osc.reset();
    for (int i = 0; i < m_numPartials; i++)
        m_oscs[i]->reset();
}
