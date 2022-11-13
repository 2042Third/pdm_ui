/*
  ==============================================================================

    NotesList.cpp
    Created: 13 Nov 2022 12:01:57am
    Author:  18604

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NotesList.h"

//==============================================================================
NotesList::NotesList()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    //subtree.reset(new NotesSubtree());
    //addAndMakeVisible(subtree);

}

NotesList::~NotesList()
{
    //subtree = nullptr;
}

void NotesList::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    if (is_in_tree) {
        g.fillAll(juce::Colour(0xff7fff00));
    }
    else {
        g.fillAll(juce::Colour(0xff008000));
    }
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    
    g.drawText (mousePosition, getLocalBounds(),
                juce::Justification::centred, true);  


    //g.drawText(currentSizeAsString, getLocalBounds(), juce::Justification::bottomLeft, true);
}

void NotesList::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    currentSizeAsString = juce::String(getWidth()) + " x " + juce::String(getHeight());
    //subtree.setBounds (0, 0, getWidth(), getHeight());
}

void NotesList::mouseEnter(const juce::MouseEvent& event)
{
    mousePosition = juce::String(event.getScreenPosition().getX()) 
        + " x " + juce::String(event.getScreenPosition().getX());
    this->is_in_tree = 1;
    repaint();
    //setColour(juce::ResizableWindow::backgroundColourId,juce::Colour(0xff7fff00));
}
void NotesList::mouseExit(const juce::MouseEvent& event)
{
    //setColour(juce::ResizableWindow::backgroundColourId, juce::Colour(0xff008000));
    this->is_in_tree = 0;
    repaint();
}
