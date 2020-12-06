/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RedshifterAudioProcessorEditor::RedshifterAudioProcessorEditor (RedshifterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 550);
	addAndMakeVisible(m_wholeInterface);
}

RedshifterAudioProcessorEditor::~RedshifterAudioProcessorEditor()
{
}

//==============================================================================
void RedshifterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.setColour(juce::Colours::black);
	//g.beginTransparencyLayer(0.5);
	g.fillAll();
	//g.endTransparencyLayer();
}

void RedshifterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	m_wholeInterface.setBounds(getLocalBounds());
}
