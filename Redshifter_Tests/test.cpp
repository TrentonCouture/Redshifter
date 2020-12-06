#include "pch.h"
#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED
#include "../Source/GUI/AdditiveSection.h"

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



