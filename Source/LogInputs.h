/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class LogInputs  : public juce::Component,
                   public juce::Button::Listener
{
public:
    //==============================================================================
    LogInputs ();
    ~LogInputs() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    juce::Path path_pass_visible;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextEditor> email_input;
    std::unique_ptr<juce::GroupComponent> email_group;
    std::unique_ptr<juce::ShapeButton> button_pass_visible;
    std::unique_ptr<juce::TextEditor> pass_input;
    std::unique_ptr<juce::TextButton> login_button;
    std::unique_ptr<juce::GroupComponent> pass_group;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LogInputs)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

