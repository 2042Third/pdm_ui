/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "LogInputs.h"
#include "Icons.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LogInputs::LogInputs ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    email_input.reset (new juce::TextEditor ("email_input"));
    addAndMakeVisible (email_input.get());
    email_input->setMultiLine (false);
    email_input->setReturnKeyStartsNewLine (false);
    email_input->setReadOnly (false);
    email_input->setScrollbarsShown (false);
    email_input->setCaretVisible (true);
    email_input->setPopupMenuEnabled (true);
    email_input->setText (juce::String());

    email_input->setBounds (32, 40, 176, 24);

    email_group.reset (new juce::GroupComponent ("email_group",
                                                 TRANS("Email")));
    addAndMakeVisible (email_group.get());
    email_group->setTextLabelPosition (juce::Justification::centredLeft);

    email_group->setBounds (24, 16, 192, 64);

    button_pass_visible.reset (new juce::ShapeButton ("button_pass_visible",
        juce::Colours::grey,   
        juce::Colours::white,
        juce::Colours::lawngreen
        ));
    addAndMakeVisible (button_pass_visible.get());
    button_pass_visible->addListener (this);

    button_pass_visible->setBounds (224, 120, 24, 24);

    pass_input.reset (new juce::TextEditor ("pass_input"));
    addAndMakeVisible (pass_input.get());
    pass_input->setMultiLine (false);
    pass_input->setReturnKeyStartsNewLine (false);
    pass_input->setReadOnly (false);
    pass_input->setScrollbarsShown (false);
    pass_input->setCaretVisible (true);
    pass_input->setPopupMenuEnabled (true);
    pass_input->setText (juce::String());

    pass_input->setBounds (30, 118, 176, 24);

    login_button.reset (new juce::TextButton ("login_button"));
    addAndMakeVisible (login_button.get());
    login_button->setButtonText (TRANS("Login"));
    login_button->addListener (this);

    login_button->setBounds (48, 184, 150, 24);

    pass_group.reset (new juce::GroupComponent ("pass_group",
                                                TRANS("Password")));
    addAndMakeVisible (pass_group.get());
    pass_group->setTextLabelPosition (juce::Justification::centredLeft);

    pass_group->setBounds (22, 94, 192, 64);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    // 
    pass_input->setPasswordCharacter((juce::juce_wchar)0x2022);

    path_pass_visible.loadPathFromData(eye, sizeof(eye));
    button_pass_visible->setShape(path_pass_visible,
        false,
        true,
        false);
    button_pass_visible->shouldUseOnColours(true);
    //[/Constructor]
}

LogInputs::~LogInputs()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    email_input = nullptr;
    email_group = nullptr;
    button_pass_visible = nullptr;
    pass_input = nullptr;
    login_button = nullptr;
    pass_group = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LogInputs::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

   // g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LogInputs::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void LogInputs::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == button_pass_visible.get())
    {
        //[UserButtonCode_button_pass_visible] -- add your button handler code here..
        //[/UserButtonCode_button_pass_visible]
    }
    else if (buttonThatWasClicked == login_button.get())
    {
        //[UserButtonCode_login_button] -- add your button handler code here..
        //[/UserButtonCode_login_button]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LogInputs" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="email_input" id="3041e3dccb504348" memberName="email_input"
              virtualName="" explicitFocusOrder="0" pos="32 40 176 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <GROUPCOMPONENT name="email_group" id="50bbe1745a3e1412" memberName="email_group"
                  virtualName="" explicitFocusOrder="0" pos="24 16 192 64" title="Email"
                  textpos="33"/>
  <IMAGEBUTTON name="button_pass_visible" id="40d790d34936e17a" memberName="button_pass_visible"
               virtualName="" explicitFocusOrder="0" pos="224 120 24 24" buttonText="button_pass_visible"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="" opacityNormal="1.0" colourNormal="0" resourceOver=""
               opacityOver="1.0" colourOver="0" resourceDown="" opacityDown="1.0"
               colourDown="0"/>
  <TEXTEDITOR name="pass_input" id="70c7c3fb933b8b6c" memberName="pass_input"
              virtualName="" explicitFocusOrder="0" pos="30 118 176 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="login_button" id="a542ca3732c033ae" memberName="login_button"
              virtualName="" explicitFocusOrder="0" pos="48 184 150 24" buttonText="Login"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GROUPCOMPONENT name="pass_group" id="8a4c841ad0e6da17" memberName="pass_group"
                  virtualName="" explicitFocusOrder="0" pos="22 94 192 64" title="Password"
                  textpos="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

