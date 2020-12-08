/*
  ==============================================================================

    StandardOscillator.h
    Created: 7 Dec 2020 8:43:08pm
    Author:  Trent

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class StandardOscillator : public juce::dsp::ProcessorWrapper<juce::dsp::ProcessorChain<juce::dsp::Oscillator<float>, juce::dsp::Gain<float>>>
{

};
