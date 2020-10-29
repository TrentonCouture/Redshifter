/*
  ==============================================================================

    WholeInterface.h
    Created: 27 Oct 2020 9:10:29pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "GUISection.h"
#include "EnvSection.h"
#include "ReverbSection.h"
#include "ChorusSection.h"
#include "FilterSection.h"
#include "PhaserSection.h"
#include "GainSection.h"

class WholeInterface : public GUISection
{
public:
	WholeInterface();
	void resized() override;
private:
	EnvSection m_envSection;
	ReverbSection m_reverbSection;
	ChorusSection m_chorusSection;
	FilterSection m_filterSection;
	PhaserSection m_phaserSection;
	GainSection m_gainSection;
};
