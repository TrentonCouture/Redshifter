/*
  ==============================================================================

    RSEngine.cpp
    Created: 27 Oct 2020 2:58:55pm
    Author:  Trenton

  ==============================================================================
*/

#include "RSEngine.h"

void RSEngine::initialize(const int sampleRate, const int numSamples, const int numChannels)
{
	m_oscEng.initialize(sampleRate, numSamples, numChannels);

}
void RSEngine::process(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiBuffer)
{
	m_oscEng.renderNextBlock(buffer, midiBuffer, 0, buffer.getNumSamples());
}
