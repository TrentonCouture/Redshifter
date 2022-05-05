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

class AdditiveSection : public GUISection,
                        public juce::Thread
{
public:
    AdditiveSection();
    ~AdditiveSection();
    void resized() override;
	void buttonClicked(juce::Button* button) override;

    // thread
    void run();
private:
    void setPartialAmps();
    juce::ShapeButton m_testButton;
};
