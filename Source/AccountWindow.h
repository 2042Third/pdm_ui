#pragma once

#include <JuceHeader.h>
class AccountWindow : public juce::Component
{
public:
    //==============================================================================
    AccountWindow();
    ~AccountWindow() override;



    void paint(juce::Graphics& g) override;
    void resized() override;



private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AccountWindow)
};
