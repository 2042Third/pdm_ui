

#pragma once

#include <JuceHeader.h>
#include "AccountWindow.h"

class UserWindow  : public juce::DocumentWindow
{
public:
    ~UserWindow() override;
    void paint (juce::Graphics& g) override;
    void resized() override;

    UserWindow(const juce::String& name, juce::Colour backgroundColour, int buttonsNeeded);

    void closeButtonPressed() override
    {
        
        setVisible(0);
    }

private:

    std::unique_ptr<AccountWindow> account_component = nullptr;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UserWindow)
};


