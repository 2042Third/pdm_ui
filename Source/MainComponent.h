#pragma once

#include <JuceHeader.h>
#include "NotesList.h"
#include "Ball.h"
#include "NotesEditor.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component,
    public juce::Timer,
    public juce::ApplicationCommandTarget,
    public juce::MenuBarModel
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    void resized() override;
    void timerCallback() override;
    void mouseEnter(const juce::MouseEvent& event) override;
    void mouseExit(const juce::MouseEvent& event) override;


    Ball ball;
    int top_cord = 20;
    int middle_cord = 300;
    int bar_height = 50;

private:
    juce::ApplicationCommandManager commandManager;
    std::unique_ptr<juce::MenuBarComponent> menuComponent;
    juce::String mousePosition = "000";
    int is_in_tree = 0;

    std::unique_ptr<NotesList> note_list;
    std::unique_ptr<NotesEditor> note_editor;

    juce::String currentSizeAsString = "none";
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
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
        option1,
        option2
    };

    juce::StringArray getMenuBarNames() override
    {
        return { "File", "Edit", "Align" };
    }

    juce::PopupMenu getMenuForIndex(int menuIndex, const juce::String&) override
    {
        juce::PopupMenu menu;

        if (menuIndex == 0)
        {
            menu.addCommandItem(&commandManager, CommandIDs::newProject);
            menu.addCommandItem(&commandManager, CommandIDs::openProject);
            menu.addCommandItem(&commandManager, CommandIDs::saveProject);
            menu.addCommandItem(&commandManager, CommandIDs::importFile);
            menu.addCommandItem(&commandManager, CommandIDs::exportFile);
        }
        else if (menuIndex == 1)
        {
            menu.addCommandItem(&commandManager, CommandIDs::undo);
            menu.addCommandItem(&commandManager, CommandIDs::redo);
        }
        else if (menuIndex == 2)
        {
            menu.addCommandItem(&commandManager, CommandIDs::option1);
            menu.addCommandItem(&commandManager, CommandIDs::option2);
        }

        return menu;
    }

    void menuItemSelected(int /*menuItemID*/, int /*topLevelMenuIndex*/) override {}

    juce::ApplicationCommandTarget* getNextCommandTarget() override
    {
        return this; // findFirstTargetParentComponent()
    }

    void getAllCommands(juce::Array<juce::CommandID>& c) override
    {
        juce::Array<juce::CommandID> commands
        {
            CommandIDs::menuPositionInsideWindow,
            CommandIDs::newProject,
            CommandIDs::openProject,
            CommandIDs::saveProject,
            CommandIDs::importFile,
            CommandIDs::exportFile,
            CommandIDs::undo,
            CommandIDs::redo,
            CommandIDs::option1,
            CommandIDs::option2
        };
        c.addArray(commands);
    }

    void getCommandInfo(juce::CommandID commandID, juce::ApplicationCommandInfo& result) override
    {
        switch (commandID)
        {
        case CommandIDs::menuPositionInsideWindow:
            result.setInfo("Inside Window", "Places the menu bar inside the application window", "Menu", 0);
            result.setTicked(1);
            result.addDefaultKeypress('w', juce::ModifierKeys::shiftModifier);
            break;
        case CommandIDs::newProject:
            result.setInfo("New", "TODO", "File", 0);
            result.addDefaultKeypress('n', juce::ModifierKeys::ctrlModifier);
            break;
        case CommandIDs::openProject:
            result.setInfo("Open", "TODO", "File", 0);
            result.addDefaultKeypress('o', juce::ModifierKeys::ctrlModifier);
            break;
        case CommandIDs::saveProject:
            result.setInfo("Save", "TODO", "File", 0);
            result.addDefaultKeypress('s', juce::ModifierKeys::ctrlModifier);
            break;
        case CommandIDs::importFile:
            result.setInfo("Import", "TODO", "File", 0);
            result.addDefaultKeypress('i', juce::ModifierKeys::ctrlModifier);
            break;
        case CommandIDs::exportFile:
            result.setInfo("Export", "TODO", "File", 0);
            result.addDefaultKeypress('e', juce::ModifierKeys::ctrlModifier);
            break;
        case CommandIDs::undo:
            result.setInfo("Undo", "TODO", "Edit", 0);
            result.addDefaultKeypress('z', juce::ModifierKeys::ctrlModifier);
            break;
        case CommandIDs::redo:
            result.setInfo("Redo", "TODO", "Edit", 0);
            result.addDefaultKeypress('y', juce::ModifierKeys::ctrlModifier);
            break;
        case CommandIDs::option1:
            result.setInfo("Option 1", "TODO", "Align", 0);
            result.addDefaultKeypress('g', juce::ModifierKeys::ctrlModifier);
            break;
        /*case CommandIDs::option2:
            result.setInfo("Option 2", "TODO", "Align", 0);
            result.addDefaultKeypress('w', juce::ModifierKeys::ctrlModifier);
            break;*/
        }
    }

    bool perform(const InvocationInfo& info) override
    {
        switch (info.commandID)
        {
        case CommandIDs::menuPositionInsideWindow:
            menuComponent->setVisible(1);
            menuItemsChanged();
            resized();
            break;
        }
        return true;
    }
};
