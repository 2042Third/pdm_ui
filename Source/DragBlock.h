/**

Created by : Mike Yang
*/
#pragma once

#include <JuceHeader.h>
class DragBlock :
    public juce::Component
{
public:

    DragBlock() {}
    ~DragBlock() override {}

    void paint(juce::Graphics& g) override {

        juce::Rectangle<float > area{ 0,0,sizex,sizey };
        g.setColour(juce::PixelARGB(a,cr,cg,cb));
        g.fillRect(area);
        //g.fillAll(juce::PixelARGB(a, cr, cg, cb));
    }
    void resized() override {
    }

    void mouseEnter(const juce::MouseEvent& event) override {
        cr = 100;
        repaint();
    }
    void mouseExit(const juce::MouseEvent& event) override {
        cr = 255;
        repaint();
    }
    void mouseUp(const juce::MouseEvent& event) override {
        x += x_off;
        y += y_off;
    }
    
    float getH() { return sizey; }
    float getW() { return sizex; }
    float x = 0;
    float x_off = 0;
    float y = 0;
    float y_off = 0;
    float sizex = 150;
    float sizey = 24;

    float da = 0; // Alpha change
    uint8_t a = 255;
    uint8_t cr = 255;
    uint8_t cg = 255;
    uint8_t cb = 255;

    juce::String name = "";
private:

    int slider_offset = 64;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DragBlock)
};