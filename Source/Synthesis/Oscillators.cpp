/*
  ==============================================================================

    Oscillators.cpp
    Created: 23 Oct 2020 12:58:56pm
    Author:  Trenton

  ==============================================================================
*/

#include "Oscillators.h"

Oscillators::Oscillators(Parameters* params) : m_params(params)
{
	m_sinOsc1.get<Osc::osc>().initialise([](float x) { return 0.1 * std::sin(x); }, 128);
	m_sawOsc1.get<Osc::osc>().initialise([](float x) { return 0.1 * x / juce::MathConstants<float>::pi; }, 128);
	m_squareOsc1.get<Osc::osc>().initialise([](float x) { return x > 0 ? 0.1 : -0.1; }, 128);
	m_triOsc1.get<Osc::osc>().initialise([](float x) { return std::abs(0.1 * (2 * x / juce::MathConstants<float>::pi - 1)); }, 128);


	m_sinOsc2.get<Osc::osc>().initialise([](float x) { return 0.1 * std::sin(x); }, 128);
	m_sawOsc2.get<Osc::osc>().initialise([](float x) { return 0.1 * x / juce::MathConstants<float>::pi; }, 128);
	m_squareOsc2.get<Osc::osc>().initialise([](float x) { return x > 0 ? 0.1 : -0.1; }, 128);
	m_triOsc2.get<Osc::osc>().initialise([](float x) { return std::abs(0.1 * (2 * x / juce::MathConstants<float>::pi - 1)); }, 128);

	//DBG("\n");
	//DBG(m_params->getAllChoiceParams().size());
	//DBG(m_params.getChoiceParam("oscType1")->getCurrentValueAsText());
	m_params->getChoiceParam("oscType1")->addListener(this);
	m_params->getChoiceParam("oscType2")->addListener(this);

	m_oscType1 = OscType::sine;
	m_oscType2 = OscType::sine;

	m_sampleRate = 0;
	m_numChannels = 0;
	m_numSamples = 0;
}

void Oscillators::parameterValueChanged(int parameterIndex, float newValue)
{
	// if osc 1
	if (parameterIndex == 20)
	{
		if (newValue < .3)
			m_oscType1 = OscType::sine;
		else if (newValue < .6)
			m_oscType1 = OscType::saw;
		else if (newValue < .9)
			m_oscType1 = OscType::square;
		else
			m_oscType1 = OscType::triangle;
	}

	// if osc 2
	if (parameterIndex == 19)
	{
		if (newValue < .3)
			m_oscType2 = OscType::sine;
		else if (newValue < .6)
			m_oscType2 = OscType::saw;
		else if (newValue < .9)
			m_oscType2 = OscType::square;
		else
			m_oscType2 = OscType::triangle;
	}
}


float Oscillators::noteToFreq(const int note) {
    const int a = 440; 
    return (a) * std::pow(2.0, ((note - 69) / 12.0));
}

void Oscillators::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
	juce::ADSR::Parameters adsrParams;
	adsrParams.attack = *m_params->getParam("attack");
	adsrParams.decay = *m_params->getParam("decay");
	adsrParams.sustain = *m_params->getParam("sustain");
	adsrParams.release = *m_params->getParam("release");
	m_adsr.setParameters(adsrParams);

	m_sinOsc1.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_sawOsc1.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_squareOsc1.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_triOsc1.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);

	m_sinOsc2.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_sawOsc2.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_squareOsc2.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_triOsc2.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
	m_adsr.noteOn();
}

void Oscillators::stopNote(float velocity, bool tailOff)
{
	m_adsr.noteOff();
}

void Oscillators::processOsc(OscWithGain& osc, juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	juce::AudioBuffer<float> tempBuffer(outputBuffer.getNumChannels(), outputBuffer.getNumSamples());
	tempBuffer.clear();
	auto wholeBlock = juce::dsp::AudioBlock<float>(tempBuffer);
	auto block = wholeBlock.getSubBlock(startSample, (size_t)numSamples);
	juce::dsp::ProcessContextReplacing<float> context(block);

	osc.process(context);

	m_adsr.applyEnvelopeToBuffer(tempBuffer, startSample, numSamples);

	for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
		outputBuffer.addFrom(channel, startSample, tempBuffer, channel, startSample, numSamples);
}

void Oscillators::setCurrentPlaybackSampleRate(double newRate)
{
	m_sampleRate = newRate;
	juce::dsp::ProcessSpec pSpec;
	pSpec.maximumBlockSize = m_numSamples;
	pSpec.sampleRate = newRate;
	pSpec.numChannels = m_numChannels;

	if (newRate > 0.0 && m_numSamples > 0 && m_numChannels > 0)
	{
		m_adsr.setSampleRate(newRate);
		m_sinOsc1.prepare(pSpec);
		m_sawOsc1.prepare(pSpec);
		m_squareOsc1.prepare(pSpec);
		m_triOsc1.prepare(pSpec);

		m_sinOsc2.prepare(pSpec);
		m_sawOsc2.prepare(pSpec);
		m_squareOsc2.prepare(pSpec);
		m_triOsc2.prepare(pSpec);
	}
}
void Oscillators::checkIfNewBufferParams(int numChannels, int numSamples)
{
	if (m_numChannels != numChannels || m_numSamples != numSamples)
	{
		m_numChannels = numChannels;
		m_numSamples = numSamples;
		setCurrentPlaybackSampleRate(m_sampleRate);
	}

}

void Oscillators::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	checkIfNewBufferParams(outputBuffer.getNumChannels(), outputBuffer.getNumSamples());

	m_sinOsc1.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));
	m_sawOsc1.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));
	m_squareOsc1.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));
	m_triOsc1.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));

	m_sinOsc2.get<Osc::vol>().setGainLinear(1.0 - *m_params->getParam("oscMix"));
	m_sawOsc2.get<Osc::vol>().setGainLinear(1.0 - *m_params->getParam("oscMix"));
	m_squareOsc2.get<Osc::vol>().setGainLinear(1.0 - *m_params->getParam("oscMix"));
	m_triOsc2.get<Osc::vol>().setGainLinear(1.0 - *m_params->getParam("oscMix"));

	switch (m_oscType1) {
	case OscType::sine:
		processOsc(m_sinOsc1, outputBuffer, startSample, numSamples);
		break;
	case OscType::saw:
		processOsc(m_sawOsc1, outputBuffer, startSample, numSamples);
		break;
	case OscType::square:
		processOsc(m_squareOsc1, outputBuffer, startSample, numSamples);
		break;
	case OscType::triangle:
		processOsc(m_triOsc1, outputBuffer, startSample, numSamples);
		break;
	}

	switch (m_oscType2) {
	case OscType::sine:
		processOsc(m_sinOsc2, outputBuffer, startSample, numSamples);
		break;
	case OscType::saw:
		processOsc(m_sawOsc2, outputBuffer, startSample, numSamples);
		break;
	case OscType::square:
		processOsc(m_squareOsc2, outputBuffer, startSample, numSamples);
		break;
	case OscType::triangle:
		processOsc(m_triOsc2, outputBuffer, startSample, numSamples);
		break;
	}

}
