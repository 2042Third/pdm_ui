/*
  ==============================================================================

    NotesEditor.h
    Created: 13 Nov 2022 4:47:54pm
    Author:  18604

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class NotesEditor  : public juce::Component
{
public:
    NotesEditor();
    ~NotesEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;


private:

    std::unique_ptr<juce::TextEditor> editor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NotesEditor)
};
