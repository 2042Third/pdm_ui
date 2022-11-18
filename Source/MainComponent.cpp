#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Initializations
    note_list.reset(new NotesList());
    menuComponent.reset(new juce::MenuBarComponent(this));
    note_editor.reset(new NotesEditor( ));

    // Visibles
    addAndMakeVisible(ball);
    addAndMakeVisible(note_list.get());
    addAndMakeVisible(note_editor.get());
    addAndMakeVisible(menuComponent.get());
    // Sizes
    top_cord = 20;

    
    // Settingss
    setApplicationCommandManagerToWatch(&commandManager);
    commandManager.registerAllCommandsForTarget(this);
    commandManager.setFirstCommandTarget(this);
    addKeyListener(commandManager.getKeyMappings());
    setWantsKeyboardFocus(true);



    menuComponent->setVisible(1);
    menuItemsChanged();


    // Timer
    Timer::startTimerHz(60);
    setSize(600, 400);
}

MainComponent::~MainComponent()
{
    note_list = nullptr;
    note_editor = nullptr;
    menuComponent = nullptr;
    account_window = nullptr;
    commandManager.setFirstCommandTarget(nullptr);
}


void MainComponent::resized()
{

    top_cord = juce::LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight();
    auto b = getLocalBounds();
    ball.setBounds(0, top_cord + (0.9 * getHeight()), middle_cord, (0.1 * getHeight()));
    note_list->setBounds(0, top_cord, middle_cord, getHeight() - (0.1 * getHeight()));
    note_editor->setBounds(middle_cord, top_cord, getWidth() - middle_cord, getHeight());
    menuComponent->setBounds(0,0,getWidth(), juce::LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight());
}

void MainComponent::timerCallback() {
    ball.pos_x += ball.speed_x;
    ball.pos_y += ball.speed_y;

    if (ball.pos_x <= 0 || ball.pos_x >= middle_cord) {
        ball.speed_x *= -1;
    }
    if (ball.pos_y <= 0 || ball.pos_y >= (0.1 * getHeight())) {
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

/**
Menu Settings

*/ 

juce::PopupMenu MainComponent::getMenuForIndex(int menuIndex, const juce::String&) 
{
    juce::PopupMenu menu;

    if (menuIndex == 0)
    {
        menu.addSubMenu(submenu_name_files, submenu_files());
        menu.addSectionHeader(sect_name_other);
        menu.addSeparator();
        menu.addCommandItem(&commandManager, CommandIDs::menuPositionInsideWindow);
    }
    else if (menuIndex == 1)
    {
        menu.addCommandItem(&commandManager, CommandIDs::undo);
        menu.addCommandItem(&commandManager, CommandIDs::redo);
    }
    else if (menuIndex == 2)
    {
        menu.addCommandItem(&commandManager, CommandIDs::openAccount);
        menu.addCommandItem(&commandManager, CommandIDs::option2);
    }

    return menu;
}


juce::PopupMenu MainComponent::submenu_files()
{
    juce::PopupMenu menu;
    menu.addCommandItem(&commandManager, CommandIDs::newProject);
    menu.addCommandItem(&commandManager, CommandIDs::openProject);
    menu.addCommandItem(&commandManager, CommandIDs::saveProject);
    menu.addCommandItem(&commandManager, CommandIDs::importFile);
    menu.addCommandItem(&commandManager, CommandIDs::exportFile);
    
    return menu;
}

void MainComponent::getCommandInfo(juce::CommandID commandID, juce::ApplicationCommandInfo& result) 
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
    case CommandIDs::openAccount:
        result.setInfo("Open Account", "TODO", "User", 0);
        result.addDefaultKeypress('g', juce::ModifierKeys::ctrlModifier);
        break;
    case CommandIDs::option2:
        result.setInfo("Option 2", "TODO", "User", 0);
        break;
    }
}


bool MainComponent::perform(const InvocationInfo& info) 
{
    switch (info.commandID)
    {
    case CommandIDs::menuPositionInsideWindow:
        menuComponent->setVisible(1);
        DBG("Got action\n");
        menuItemsChanged();
        resized();
        break;
    case CommandIDs::openAccount:
        if(!account_window )
            account_window.reset(new UserWindow("Information", juce::Colours::grey, juce::DocumentWindow::allButtons));
        account_window->setVisible(1);
        break;
    }
    return true;
}


void MainComponent::getAllCommands(juce::Array<juce::CommandID>& c)
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
        CommandIDs::openAccount,
        CommandIDs::option2
    };
    c.addArray(commands);
}