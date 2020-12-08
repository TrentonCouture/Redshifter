#include "pch.h"
#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED
#include "../Source/GUI/AdditiveSection.h"
#include "../Source/Synthesis/AdditiveOscillator.h"
#include "../Source/Synthesis/StandardOscillator.h"

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(AdditiveGUI, getsAdded)
{
	class TestSection : public juce::Component
	{
	public:
		TestSection()
		{
			addAndMakeVisible(testAddSection);
			auto myComponent = getChildComponent(0);
			auto addComponent = dynamic_cast<AdditiveSection*>(myComponent);

			EXPECT_NE(addComponent, nullptr);
		}
	private:
		AdditiveSection testAddSection;
	};

}

TEST(AdditiveDSP, getsAdded)
{
	EXPECT_NO_THROW
	(
		juce::AudioBuffer<float> tempBuffer(2, 256);
		tempBuffer.clear();
		auto wholeBlock = juce::dsp::AudioBlock<float>(tempBuffer);
		auto block = wholeBlock.getSubBlock(0, (size_t)256);
		juce::dsp::ProcessContextReplacing<float> context(block);

		juce::dsp::ProcessorChain<AdditiveOscillator> chain;
		chain.process(context);
	);
}

TEST(AdditiveDSP, processorBase)
{
	juce::dsp::ProcessorBase* base;
	AdditiveWrapper addOsc;
	base = &addOsc;

	EXPECT_NE(base, nullptr);

	StandardOscillator stdOsc;

	base = &stdOsc;

	EXPECT_NE(base, nullptr);
}
