#pragma once

#include <JuceHeader.h>
class AnimatedCurve :
    public juce::Component
{
public:

    AnimatedCurve() {}
    ~AnimatedCurve() override {}

    void paint(juce::Graphics& g) override {

        juce::Rectangle<float > area{ x,y,size,size };
        g.setColour(juce::Colours::lightgoldenrodyellow);
        g.fillEllipse(area);
    }
    void resized() override {
    }

    float x = 0;
    float y = 0;
    float dx = 1;
    float dy = 1;
    float odx = 5;
    float ody = 5;
    float xm = 1;
    float ym = 1;

    float ax = 0;
    float ay = 0;
    float da = 0; // Alpha change
    float a = 255;
    float size = 13;

private:

    int slider_offset = 64;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AnimatedCurve)



};