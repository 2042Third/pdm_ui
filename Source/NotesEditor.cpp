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
    block.reset(new DragBlock());
    


    // Size
    editor->setBounds(0, 0, getWidth() , getHeight());

    // Visibles 
    addAndMakeVisible(editor.get());
    addAndMakeVisible(block.get());

    block->addMouseListener(this,1);


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
    block = nullptr;
}

void NotesEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("NotesEditor", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text

    block->repaint();

}

void NotesEditor::resized()
{
    editor->setBounds(0, 0, getWidth(), getHeight());
    block->setBounds(block->x, block->y, block->getW(), block->getH());
}

void NotesEditor::mouseDrag(const juce::MouseEvent& event) {
    block->x_off = event.getDistanceFromDragStartX();
    block->y_off = event.getDistanceFromDragStartY();
    block->setBounds(block->x+ block->x_off, block->y+ block->y_off, block->getW(), block->getH());
    block->repaint();
}
