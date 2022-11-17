
#include "UserWindow.h"


UserWindow::UserWindow (const juce::String& name, juce::Colour backgroundColour, int buttonsNeeded) : DocumentWindow(name, backgroundColour, buttonsNeeded)
{
    account_component.reset(new AccountWindow());
    setUsingNativeTitleBar(1);
    setContentOwned(account_component.get(), 1);
    centreWithSize(getWidth(), getHeight());
    //setVisible(true);
    setResizable(true, false);
    setResizeLimits(300, 250, 10000, 10000);
    centreWithSize(getWidth(), getHeight());
}

UserWindow::~UserWindow()
{
    account_component = nullptr;
}

//==============================================================================
void UserWindow::paint (juce::Graphics& g)
{

    g.fillAll (juce::Colour (0xff323e44));

}

void UserWindow::resized()
{
}





