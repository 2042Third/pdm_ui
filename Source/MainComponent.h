#pragma once

#include <JuceHeader.h>
#include "NotesList.h"
#include "Ball.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component, public juce::Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;
    void mouseEnter(const juce::MouseEvent& event) override;
    void mouseExit(const juce::MouseEvent& event) override;


    Ball ball;


private:
    //==============================================================================
    // Your private member variables go here...
    

    juce::String mousePosition = "000";
    int is_in_tree = 0;

    std::unique_ptr<NotesList> note_list_obj;
    juce::String currentSizeAsString = "none";
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
