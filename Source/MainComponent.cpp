#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Initializations
    note_list.reset(new NotesList());
    menuComponent.reset(new juce::MenuBarComponent());
    note_editor.reset(new NotesEditor( ));

    // Sizes
    top_cord = 20;
    //note_list->setBounds(0, top_cord, middle_cord, getHeight() - top_cord);
    //note_editor->setBounds(middle_cord,top_cord,getWidth()-middle_cord, getHeight()-top_cord);
    //menuComponent->setBounds(getLocalBounds().removeFromTop(juce::LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));

    
    // Settingss
    setApplicationCommandManagerToWatch(&commandManager);
    commandManager.registerAllCommandsForTarget(this);
    commandManager.setFirstCommandTarget(this);
    addKeyListener(commandManager.getKeyMappings());
    setWantsKeyboardFocus(true);


    // Visibles
    addAndMakeVisible(ball);
    addAndMakeVisible(note_list.get());
    addAndMakeVisible(note_editor.get());
    addAndMakeVisible(menuComponent.get());

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
    commandManager.setFirstCommandTarget(nullptr);
}


void MainComponent::resized()
{

    top_cord = juce::LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight();
    auto b = getLocalBounds();
    ball.setBounds(0, top_cord + (0.9 * getHeight()), middle_cord, (0.1 * getHeight()));
    note_list->setBounds(0, top_cord, middle_cord, getHeight() - (0.1 * getHeight()));
    note_editor->setBounds(middle_cord, top_cord, getWidth() - middle_cord, getHeight());
    //menuComponent->setBounds(b.removeFromTop(juce::LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
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
    //menuComponent->repaint();
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
