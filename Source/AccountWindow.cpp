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
    dx_slider.reset(new juce::Slider("dx"));
    dy_slider.reset(new juce::Slider("dy"));

    addAndMakeVisible(dx_slider.get());
    addAndMakeVisible(dy_slider.get());

    dx_slider->setRange(0, 40, 1);
    dx_slider->setSliderStyle(juce::Slider::LinearHorizontal);
    dx_slider->setTextBoxStyle(juce::Slider::TextBoxLeft, false, 80, 20);
    dx_slider->addListener(this);
    dx_slider->setBounds(40, 40, 300, 24);

    dy_slider->setRange(0, 40, 1);
    dy_slider->setSliderStyle(juce::Slider::LinearHorizontal);
    dy_slider->setTextBoxStyle(juce::Slider::TextBoxLeft, false, 80, 20);
    dy_slider->addListener(this);
    dy_slider->setBounds(368, 40, 300, 24);

    Timer::startTimerHz(60);
    setSize(1000, 1000);
}

AccountWindow::~AccountWindow()
{
}

void AccountWindow::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff323e44));
    juce::Path myPath;

    myPath.startNewSubPath(10.0f, 10.0f);          // move the current position to (10, 10)
    myPath.lineTo(100.0f, 200.0f);                 // draw a line from here to (100, 200)
    myPath.quadraticTo(0.0f, 150.0f, 5.0f, 50.0f); // draw a curve that ends at (5, 50)
    myPath.closeSubPath();                          // close the subpath with a line back to (10, 10)

    // add an ellipse as well, which will form a second sub-path within the path..
    myPath.addEllipse(50.0f, 50.0f, 40.0f, 30.0f);

    // double the width of the whole thing..
    myPath.applyTransform(juce::AffineTransform::scale(2.0f, 1.0f));

    g.setColour(juce::PixelARGB(250,173, 255, 47));
    // and draw it to a graphics context with a 5-pixel thick outline.
    g.strokePath(myPath, juce::PathStrokeType(5.0f));
}

void AccountWindow::resized()
{

}


void AccountWindow::drawing(juce::Graphics& g) {
    juce::Path p;

    g.strokePath(p, juce::PathStrokeType(5.0f));
}

void AccountWindow::timerCallback()
{
}

void AccountWindow::sliderValueChanged(juce::Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == dx_slider.get()){
        curve.dx = dx_slider->getValue();
    }
    else if (sliderThatWasMoved == dy_slider.get()){
        curve.dx = dx_slider->getValue();
    }
}
