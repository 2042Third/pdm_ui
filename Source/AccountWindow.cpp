/*
  ==============================================================================

    AccountWindow.cpp
    Created: 17 Nov 2022 1:42:33pm
    Author:  Yi Yang

  ==============================================================================
*/

#include "AccountWindow.h"


AccountWindow::AccountWindow()
{
    setSize(600, 400);
}

AccountWindow::~AccountWindow()
{
}

void AccountWindow::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff323e44));

}

void AccountWindow::resized()
{

}
