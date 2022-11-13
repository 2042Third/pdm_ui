/*
  ==============================================================================

    NotesList.h
    Created: 13 Nov 2022 12:01:57am
    Author:  18604

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "NotesSubtree.h"

//==============================================================================
/*
*/
class NotesList  : public juce::Component
{
public:
    NotesList();
    ~NotesList() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void mouseEnter(const juce::MouseEvent& event) override;
    void mouseExit(const juce::MouseEvent& event) override;
    int is_in_tree = 0;
private:
    //std::unique_ptr<NotesSubtree> subtree;
    //NotesSubtree subtree;
    juce::String currentSizeAsString = "000";
    juce::String mousePosition = "000";
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NotesList)
};
