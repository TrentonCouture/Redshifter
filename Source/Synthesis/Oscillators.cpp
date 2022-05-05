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
	juce::Random random(42);
	for (int i = 0; i < m_numOsc; i++)
	{
		m_sinOsc[i].processor.get<Osc::osc>().initialise([](float x) { return 0.1 * std::sin(x); }, 128);
		m_sawOsc[i].processor.get<Osc::osc>().initialise([](float x) { return 0.1 * x / juce::MathConstants<float>::pi; }, 128);
		m_squareOsc[i].processor.get<Osc::osc>().initialise([](float x) { return x > 0 ? 0.1 : -0.1; }, 128);
		m_triOsc[i].processor.get<Osc::osc>().initialise([](float x) { return std::abs(0.1 * (2 * x / juce::MathConstants<float>::pi - 1)); }, 128);
		//m_addOsc[i].processor.get<Osc::osc>().initialise([](float x) { return (float)(rand() % 100)/100 - 0.5;}, 128);
		m_addOsc[i].processor.get<Osc::osc>().initialise(params);
		m_oscType[i] = OscType::sine;
	}

	m_params->getChoiceParam("oscType1")->addListener(this);
	m_params->getChoiceParam("oscType2")->addListener(this);

	const int numPartials = 42;
	for (int i = 0; i < numPartials; i++)
	{
		m_params->getParam("partialAmp" + std::to_string(i))->addListener(this);
		m_params->getParam("partialFreq" + std::to_string(i))->addListener(this);
	}

	m_sampleRate = 0;
	m_numChannels = 0;
	m_numSamples = 0;
}

void Oscillators::parameterValueChanged(int parameterIndex, float newValue)
{
	// if partial amp
	if (parameterIndex >= 11 && parameterIndex <= 52)
		m_addOsc->processor.get<0>().initialiseOscs();

	// if partial freq
	if (parameterIndex >= 53 && parameterIndex <= 94)
		m_addOsc->processor.get<0>().modulateFrequency();

	// if osc 1
	if (parameterIndex == 104)
	{
		if (newValue < .2)
			m_oscType[0] = OscType::sine;
		else if (newValue < .4)
			m_oscType[0] = OscType::saw;
		else if (newValue < .6)
			m_oscType[0] = OscType::square;
		else if (newValue < .8)
			m_oscType[0] = OscType::triangle;
		else
			m_oscType[0] = OscType::additive;
	}

	// if osc 2
	if (parameterIndex == 103)
	{
		if (newValue < .2)
			m_oscType[1] = OscType::sine;
		else if (newValue < .4)
			m_oscType[1] = OscType::saw;
		else if (newValue < .6)
			m_oscType[1] = OscType::square;
		else if (newValue < .8)
			m_oscType[1] = OscType::triangle;
		else
			m_oscType[1] = OscType::additive;
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

	for (int i = 0; i < m_numOsc; i++)
	{
		m_adsr[i].setParameters(adsrParams);
		m_sinOsc[i].processor.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
		m_sawOsc[i].processor.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
		m_squareOsc[i].processor.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
		m_triOsc[i].processor.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
		m_addOsc[i].processor.get<Osc::osc>().setFrequency(noteToFreq(midiNoteNumber), true);
		m_adsr[i].noteOn();
	}
}

void Oscillators::stopNote(float velocity, bool tailOff)
{
	for (int i = 0; i < m_numOsc; i++)
		m_adsr[i].noteOff();
}

void Oscillators::processOsc(juce::dsp::ProcessorBase& osc, juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples, int oscNum)
{
	juce::AudioBuffer<float> tempBuffer(outputBuffer.getNumChannels(), outputBuffer.getNumSamples());
	tempBuffer.clear();
	auto wholeBlock = juce::dsp::AudioBlock<float>(tempBuffer);
	auto block = wholeBlock.getSubBlock(startSample, (size_t)numSamples);
	juce::dsp::ProcessContextReplacing<float> context(block);

	osc.process(context);

	m_adsr[oscNum].applyEnvelopeToBuffer(tempBuffer, startSample, numSamples);

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
		for (int i = 0; i < m_numOsc; i++)
		{
			m_adsr[i].setSampleRate(newRate);
			m_sinOsc[i].prepare(pSpec);
			m_sawOsc[i].prepare(pSpec);
			m_squareOsc[i].prepare(pSpec);
			m_triOsc[i].prepare(pSpec);
			m_addOsc[i].prepare(pSpec);
		}
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

	m_sinOsc[0].processor.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));
	m_sawOsc[0].processor.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));
	m_squareOsc[0].processor.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));
	m_triOsc[0].processor.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));
	m_addOsc[0].processor.get<Osc::vol>().setGainLinear(*m_params->getParam("oscMix"));

	m_sinOsc[1].processor.get<Osc::vol>().setGainLinear(1 - *m_params->getParam("oscMix"));
	m_sawOsc[1].processor.get<Osc::vol>().setGainLinear(1 - *m_params->getParam("oscMix"));
	m_squareOsc[1].processor.get<Osc::vol>().setGainLinear(1 - *m_params->getParam("oscMix"));
	m_triOsc[1].processor.get<Osc::vol>().setGainLinear(1 - *m_params->getParam("oscMix"));
	m_addOsc[1].processor.get<Osc::vol>().setGainLinear(1 - *m_params->getParam("oscMix"));

	for (int i = 0; i < m_numOsc; i++)
	{
		switch (m_oscType[i]) {
		case OscType::sine:
			processOsc(m_sinOsc[i], outputBuffer, startSample, numSamples, 0);
			break;
		case OscType::saw:
			processOsc(m_sawOsc[i], outputBuffer, startSample, numSamples, 0);
			break;
		case OscType::square:
			processOsc(m_squareOsc[i], outputBuffer, startSample, numSamples, 0);
			break;
		case OscType::triangle:
			processOsc(m_triOsc[i], outputBuffer, startSample, numSamples, 0);
			break;
		case OscType::additive:
			processOsc(m_addOsc[i], outputBuffer, startSample, numSamples, 0);
		}
	}
}
