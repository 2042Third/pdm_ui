#pragma once

#include <JuceHeader.h>
#include "NotesList.h"
#include "Ball.h"
#include "NotesEditor.h"
#include "UserWindow.h"
#include "AccountWindow.h"

class MainComponent  : 
    public juce::Component,
    public juce::Timer,
    public juce::ApplicationCommandTarget,
    public juce::MenuBarModel
{
public:

    enum CommandIDs
    {
        newProject = 1,
        menuPositionInsideWindow,
        openProject,
        saveProject,
        importFile,
        exportFile,
        undo,
        redo,
        openAccount,
        option2
    };

    MainComponent();
    ~MainComponent() override;

    void resized() override;
    void timerCallback() override;
    void mouseEnter(const juce::MouseEvent& event) override;
    void mouseExit(const juce::MouseEvent& event) override;


    juce::StringArray getMenuBarNames() override
    {
        return { "File", "Edit", "User" };
    }
    juce::PopupMenu getMenuForIndex(int menuIndex, const juce::String&) override;
    void menuItemSelected(int /*menuItemID*/, int /*topLevelMenuIndex*/) override {}
    juce::ApplicationCommandTarget* getNextCommandTarget() override {return nullptr; }
    void getAllCommands(juce::Array<juce::CommandID>& c) override;
    void getCommandInfo(juce::CommandID commandID, juce::ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    juce::PopupMenu submenu_files();

private:
    // Controler Components
    juce::ApplicationCommandManager commandManager;
    std::unique_ptr<juce::MenuBarComponent> menuComponent;
    
    // Menu Names
    juce::String sect_name_other = "Other";
    juce::String submenu_name_files = "Files";

    // Components
    std::unique_ptr<NotesList> note_list;
    std::unique_ptr<NotesEditor> note_editor;
    Ball ball;
    int top_cord = 20;
    int middle_cord = 300;
    int bar_height = 50;

    // Sub-windows
    std::unique_ptr<UserWindow> account_window = nullptr;


    // Other
    int is_in_tree = 0;
    juce::String mousePosition = "000";
    juce::String currentSizeAsString = "none";
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)

};
