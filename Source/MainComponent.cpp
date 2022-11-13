#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    note_list_obj.reset(new NotesList());
    note_list_obj->setSize(300, 700);
    setSize (600, 400);
    addAndMakeVisible(note_list_obj.get());

    note_list_obj->setBounds(0, 0, 0.2 * getWidth(), getHeight() - (0.1 * getHeight()));
    setInterceptsMouseClicks(true, true);

    setSize(600, 400);
    addAndMakeVisible(ball);

    Timer::startTimerHz(60);
}

MainComponent::~MainComponent()
{
    note_list_obj = nullptr;
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    /*g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    if (is_in_tree) {
        g.fillAll(juce::Colour(0xff7fff00));
    }
    else {
        g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    }
    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText (currentSizeAsString, getLocalBounds(), juce::Justification::centred, true);*/

    
}

void MainComponent::resized()
{
    ball.setBounds(getWidth()/2, getHeight() / 2, 300, 300);
    //currentSizeAsString = juce::String(getWidth()) + " x " + juce::String(getHeight());
    note_list_obj->setBounds(0, 0, 0.2 * getWidth(), getHeight() - (0.1 * getHeight()));
}

void MainComponent::timerCallback() {
    ball.pos_x += ball.speed_x;
    ball.pos_y += ball.speed_y;

    if (ball.pos_x <= 0 || ball.pos_x >= 300) {
        ball.speed_x *= -1;
    }
    if (ball.pos_y <= 0 || ball.pos_y >= 300) {
        ball.speed_y *= -1;
    }

    ball.repaint();
}


void MainComponent::mouseEnter(const juce::MouseEvent& event)
{
    mousePosition = juce::String(event.getScreenPosition().getX())
        + " x " + juce::String(event.getScreenPosition().getX());
    this->is_in_tree = 1;
}
void MainComponent::mouseExit(const juce::MouseEvent& event)
{
    this->is_in_tree = 0;
}
