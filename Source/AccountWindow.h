#pragma once

#include <JuceHeader.h>
#include "AnimatedCurve.h"
#include "LogInputs.h"

class AccountWindow : 
    public juce::Component
    /*public juce::Timer,
    public juce::Slider::Listener*/
{
public:

    AccountWindow();
    ~AccountWindow() override;

    void paint(juce::Graphics& g) override;
    void resized() override;
    /*
    void sliderValueChanged(juce::Slider* sliderThatWasMoved) override;

    void drawing(juce::Graphics& g);
    void timerCallback() override;*/

private:
    std::unique_ptr<LogInputs> log_input;
    int show_pass = 0;
    /*std::unique_ptr<AnimatedCurve> curve;

    std::unique_ptr<juce::Slider> dx_slider;
    std::unique_ptr<juce::Slider> dy_slider;
    std::unique_ptr<juce::Slider> ax_slider;
    std::unique_ptr<juce::Slider> ay_slider;*/

    int slider_offset = 64;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AccountWindow)


    
};
