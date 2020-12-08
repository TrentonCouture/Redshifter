/*
  ==============================================================================

    AdditiveOscillator.h
    Created: 6 Dec 2020 5:54:29pm
    Author:  Trent

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdditiveOscillator
{
public:
    void prepare(const juce::dsp::ProcessSpec& spec);
    void process(const juce::dsp::ProcessContextReplacing<float>& context);
    void reset();
};

class AdditiveWrapper : public juce::dsp::ProcessorWrapper<AdditiveOscillator>
{

};

