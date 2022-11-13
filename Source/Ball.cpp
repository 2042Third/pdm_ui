/*
  ==============================================================================

    Ball.cpp
    Created: 13 Nov 2022 12:56:25pm
    Author:  18604

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Ball.h"

//==============================================================================
Ball::Ball()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Ball::~Ball()
{
}

void Ball::paint (juce::Graphics& g)
{
    juce::Rectangle<float > area{ pos_x,pos_y,size,size };

    if (is_in_tree) {
        g.fillAll(juce::Colours::aqua);
    }
    else {
        g.fillAll(juce::Colours::black);
    }

    g.setColour(juce::Colours::lightgoldenrodyellow);

    //g.drawEllipse(area, 2.0);
    g.fillEllipse(area);
}

void Ball::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void Ball::mouseEnter(const juce::MouseEvent& event)
{
    mousePosition = juce::String(event.getScreenPosition().getX())
        + " x " + juce::String(event.getScreenPosition().getX());
    this->is_in_tree = 1;
}
void Ball::mouseExit(const juce::MouseEvent& event)
{
    this->is_in_tree = 0;
}
