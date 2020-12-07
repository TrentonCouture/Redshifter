/*
  ==============================================================================

    AdditiveSection.h
    Created: 5 Dec 2020 8:49:31pm
    Author:  Trent

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "GUISection.h""

class AdditiveSection : public GUISection
{
public:
    AdditiveSection();
    void resized() override;
	void buttonClicked(juce::Button* button) override;
private:
    void setPartialAmps();
    juce::ShapeButton m_testButton;
};
