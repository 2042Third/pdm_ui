/*
  ==============================================================================

    NotesEditor.cpp
    Created: 13 Nov 2022 4:47:54pm
    Author:  18604

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NotesEditor.h"

//==============================================================================
NotesEditor::NotesEditor()
{
    // Initilization
    editor.reset(new juce::TextEditor());

    // Size
    editor->setBounds(0, 0, getWidth() , getHeight());

    // Visibles 
    addAndMakeVisible(editor.get());

    // Specifications
    editor->setTooltip(TRANS("a small text editor\n"));
    editor->setMultiLine(true);
    editor->setReturnKeyStartsNewLine(true);
    editor->setReadOnly(false);
    editor->setScrollbarsShown(true);
    editor->setCaretVisible(true);
    editor->setPopupMenuEnabled(true);
    editor->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0xbd495358));
    editor->setColour(juce::TextEditor::highlightColourId, juce::Colour(0xbfa0a196));
    editor->setColour(juce::TextEditor::outlineColourId, juce::Colour(0xd1000000));
    editor->setColour(juce::TextEditor::shadowColourId, juce::Colour(0x8f393535));
    editor->setText(juce::String());
}

NotesEditor::~NotesEditor()
{
    editor = nullptr;
}

void NotesEditor::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("NotesEditor", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void NotesEditor::resized()
{
    editor->setBounds(0, 0, getWidth(), getHeight());

}
