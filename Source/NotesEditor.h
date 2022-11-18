/*
  ==============================================================================

    NotesEditor.h
    Created: 13 Nov 2022 4:47:54pm
    Author:  Mike Yang

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DragBlock.h"

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
    void mouseDrag(const juce::MouseEvent& event) override;

private:

    std::unique_ptr<juce::TextEditor> editor;
    std::unique_ptr<DragBlock> block;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NotesEditor)
};
