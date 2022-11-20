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
    /*dx_slider.reset(new juce::Slider("dx"));
    addAndMakeVisible(dx_slider.get());
    dx_slider->setRange(0, 40, 1);
    dx_slider->setSliderStyle(juce::Slider::LinearHorizontal);
    dx_slider->setTextBoxStyle(juce::Slider::TextBoxLeft, false, 80, 20);
    dx_slider->addListener(this);
    dx_slider->setBounds(40, 40, 300, 24);

    dy_slider.reset(new juce::Slider("dy"));
    dy_slider->setRange(0, 40, 1);
    addAndMakeVisible(dy_slider.get());
    dy_slider->setSliderStyle(juce::Slider::LinearHorizontal);
    dy_slider->setTextBoxStyle(juce::Slider::TextBoxLeft, false, 80, 20);
    dy_slider->addListener(this);
    dy_slider->setBounds(368, 40, 300, 24);

    ax_slider.reset(new juce::Slider("ax"));
    addAndMakeVisible(ax_slider.get());
    ax_slider->setRange(-2.5, 2.5);
    ax_slider->setSliderStyle(juce::Slider::LinearHorizontal);
    ax_slider->setTextBoxStyle(juce::Slider::TextBoxLeft, false, 80, 20);
    ax_slider->addListener(this);
    ax_slider->setBounds(40, 10, 300, 24);

    ay_slider.reset(new juce::Slider("ay"));
    addAndMakeVisible(ay_slider.get());
    ay_slider->setRange(-2.5, 2.5);
    ay_slider->setSliderStyle(juce::Slider::LinearHorizontal);
    ay_slider->setTextBoxStyle(juce::Slider::TextBoxLeft, false, 80, 20);
    ay_slider->addListener(this);
    ay_slider->setBounds(368, 10, 300, 24);

    curve.reset(new AnimatedCurve());
    addAndMakeVisible(curve.get());
    curve->setBounds(0,slider_offset,getWidth(),getHeight()-slider_offset);

    dy_slider->setRange(0, 40, 1);

    Timer::startTimerHz(60);
    setSize(1000, 1000);*/
    log_input.reset(new LogInputs());
    addAndMakeVisible(log_input.get());
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
    log_input->setBounds(0,0,getWidth(),getHeight());
    //curve->setBounds(0, slider_offset, getWidth(), getHeight() - slider_offset);
}


//void AccountWindow::drawing(juce::Graphics& g) {
//    juce::Path p;
//
//    g.strokePath(p, juce::PathStrokeType(5.0f));
//}
//
//void AccountWindow::timerCallback()
//{
//
//    if (curve->x < 0 || curve->x > getWidth()) {
//        curve->xm *= -1;
//    }
//    curve->dx += curve->ax * curve->xm;
//    curve->x += curve->dx * curve->xm;
//    dx_slider->setValue(curve->dx);
//
//    if (curve->y < 0 || curve->y > getHeight()-slider_offset) {
//        curve->ym *= -1;
//    }
//    curve->dy += curve->ay * curve->ym;
//    curve->y += curve->dy*curve->ym;
//    dy_slider->setValue(curve->dy);
//
//    curve->repaint();
//}
//
//void AccountWindow::sliderValueChanged(juce::Slider* sliderThatWasMoved)
//{
//    /*if (sliderThatWasMoved == dx_slider.get()){
//        curve->dx = dx_slider->getValue();
//    }
//    else if (sliderThatWasMoved == dy_slider.get()) {
//        curve->dy = dy_slider->getValue();
//    }
//    else */
//    if (sliderThatWasMoved == ax_slider.get()) {
//        curve->ax = ax_slider->getValue();
//    }
//    else if (sliderThatWasMoved == ay_slider.get()) {
//        curve->ay = ay_slider->getValue();
//    }
//}
