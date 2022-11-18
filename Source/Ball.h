/*
  ==============================================================================

    Ball.h
    Created: 13 Nov 2022 12:56:25pm
    Author:  18604

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Ball  : public juce::Component
{
public:
    Ball();
    ~Ball() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void mouseEnter(const juce::MouseEvent& event) override;
    void mouseExit(const juce::MouseEvent& event) override;
    float pos_x{ 10 };
    float pos_y{ 20 };
    float speed_x{ 2 };
    float speed_y{ 0 };
    float size{ 20 };


private:

    int is_in_tree = 0;
    juce::String mousePosition = "000";
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Ball)
};
