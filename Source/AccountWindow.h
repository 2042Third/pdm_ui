#pragma once

#include <JuceHeader.h>
class AccountWindow : 
    public juce::Component, 
    public juce::Timer,
    public juce::Slider::Listener
{
public:
    struct point {
        float x;
        float y;
        float dx;
        float dy;
        float ax;
        float ay;
        float da; // Alpha change
    };

    AccountWindow();
    ~AccountWindow() override;

    void paint(juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* sliderThatWasMoved) override;

    void drawing(juce::Graphics& g);
    void timerCallback() override;

private:
    point curve;

    std::unique_ptr<juce::Slider> dx_slider;
    std::unique_ptr<juce::Slider> dy_slider;

    int slider_offset = 64;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AccountWindow)
};
