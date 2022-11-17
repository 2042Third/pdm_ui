/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MainComponent.h"

////==============================================================================
//class PDMNotesApplication  : public juce::JUCEApplication
//{
//public:
//    //==============================================================================
//    PDMNotesApplication() = default;
//
//    const juce::String getApplicationName() override       { return ProjectInfo::projectName; }
//    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
//    bool moreThanOneInstanceAllowed() override             { return true; }
//
//    //==============================================================================
//    void initialise (const juce::String& commandLine) override
//    {
//        mainWindow.reset (new MainWindow (getApplicationName(), new MainComponent(), *this));
//    }
//
//    void shutdown() override
//    {
//        mainWindow = nullptr; // (deletes our window)
//    }
//
//
//    class MainWindow    : public juce::DocumentWindow
//    {
//    public:
//        MainWindow (const juce::String& name, juce::Component* c, JUCEApplication& a)
//            : DocumentWindow (name,
//                              juce::Desktop::getInstance().getDefaultLookAndFeel()
//                                                          .findColour (juce::ResizableWindow::backgroundColourId),
//                              DocumentWindow::allButtons),
//            app(a)
//        {
//            setUsingNativeTitleBar (true);
//            
//            setContentOwned (c, true);
//            setBoundsRelative(1.0f, 1.0f, 0.45f, 0.8f);
//
//           #if JUCE_IOS || JUCE_ANDROID
//            setFullScreen (true);
//           #else
//            setResizable (true, true);
//            setResizeLimits(300, 250, 10000, 10000);
//            centreWithSize (getWidth(), getHeight());
//           #endif
//            
//            setVisible (true);
//        }
//
//        void closeButtonPressed() override
//        {
//            app.systemRequestedQuit();
//        }
//
//    private:
//        JUCEApplication& app;
//        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
//    };
//
//private:
//    std::unique_ptr<MainWindow> mainWindow;
//};
//
////==============================================================================
//// This macro generates the main() routine that launches the app.
//START_JUCE_APPLICATION (PDMNotesApplication)

class PDMNotesApplication : public juce::JUCEApplication
{
public:
    //==============================================================================
    PDMNotesApplication() = default;

    const juce::String getApplicationName() override { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override { return true; }

    void initialise(const juce::String&) override
    {
        mainWindow.reset(new MainWindow(getApplicationName(), new MainComponent, *this));
    }

    void shutdown() override { mainWindow = nullptr; }

private:
    class MainWindow : public juce::DocumentWindow
    {
    public:
        MainWindow(const juce::String& name, juce::Component* c, JUCEApplication& a)
            : DocumentWindow(name, juce::Desktop::getInstance().getDefaultLookAndFeel()
                .findColour(ResizableWindow::backgroundColourId),
                juce::DocumentWindow::allButtons),
            app(a)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(c, true);
            setBoundsRelative(1.0f, 1.0f, 0.45f, 0.8f);

            #if JUCE_ANDROID || JUCE_IOS
            setFullScreen(true);
            #else
            setResizable(true, false);
            setResizeLimits(300, 250, 10000, 10000);
            centreWithSize(getWidth(), getHeight());
            #endif

            setVisible(true);
        }

        void closeButtonPressed() override
        {
            app.systemRequestedQuit();
        }

    private:
        JUCEApplication& app;

        //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
    };

    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
START_JUCE_APPLICATION(PDMNotesApplication)