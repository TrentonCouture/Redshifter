/*
  ==============================================================================

    AdditiveOscillator.h
    Created: 6 Dec 2020 5:54:29pm
    Author:  Trent

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <algorithm>

#include "Parameters.h"

class AdditiveProcessor
{
public:
    void initialise(Parameters* params);
    void initialiseOscs();
    void modulateFrequency();
    void setFrequency(float newFreq, bool force);

    void prepare(const juce::dsp::ProcessSpec& spec);
    void process(const juce::dsp::ProcessContextReplacing<float>& context);
    void reset();

private:
    Parameters* m_params;
    const float m_numPartials = 42;
    juce::OwnedArray<juce::dsp::ProcessorChain<juce::dsp::Oscillator<float>, juce::dsp::Gain<float>>> m_oscs;

    float m_currentFreq = 0.0;
};

class AdditiveOscillator : public juce::dsp::ProcessorWrapper<juce::dsp::ProcessorChain<AdditiveProcessor, juce::dsp::Gain<float>>>
{

};

