/*
  ==============================================================================

    SourceCode.h
    Created: 27 Jul 2019 11:49:07pm
    Author:  Mark Barbaric

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"

struct ChildDragContainer : public Component
{
    ChildDragContainer(const int childNumber_)
    :childNumber(childNumber_)
    {
        childText = "Child #" + String(childNumber);
        setNormalPaintState();
    }
    
    ~ChildDragContainer() = default;
    
    void setNormalPaintState()
    {
        message = childText;
        isMouseOver = false;
        isDragging = false;
    }
    
    void setDraggingPaintState()
    {
        isMouseOver = false;
        isDragging = true;
    }
    
    void setMouseOverPaintState()
    {
        message = "Click To Drag";
        isMouseOver = true;
        isDragging = false;
    }
    
    void mouseEnter(const MouseEvent& e) override
    {
        setMouseOverPaintState();
        repaint();
    }
    
    void mouseExit(const MouseEvent& e) override
    {
        setNormalPaintState();
        repaint();
    }

    void mouseDown(const MouseEvent& e) override
    {
        mouseDownPosition = e.getMouseDownPosition();
    }
    
    void mouseDrag(const MouseEvent& e) override
    {
        if (auto* dragContainer = DragAndDropContainer::findParentDragContainerFor (this))
        {
            setDraggingPaintState();
            dragContainer->startDragging (childText, this);
            dragDelta = e.getEventRelativeTo (this).getPosition() - mouseDownPosition;
        }
    }
    
    void mouseUp(const MouseEvent& e) override
    {
        if(dragDelta.x > 0 || dragDelta.y  > 0)
        {
            setNormalPaintState();
            repaint();
            dragDelta = {0,0};
        }
    }
    
    void paint(Graphics& g) override
    {
        g.fillAll (Colours::blue.withAlpha (0.2f));
        
        if(!isDragging && !isMouseOver)
        {
            g.setColour(Colours::white);
            g.drawRect (getLocalBounds(), 1);
        }
        
        else if (isDragging && !isMouseOver)
        {
            g.setColour (Colours::red);
            g.drawRect (getLocalBounds(), 1);
        }
        
        else if(!isDragging && isMouseOver)
        {
            g.setColour (Colours::green);
            g.drawRect (getLocalBounds(), 1);
        }
        
        auto font = getLookAndFeel().getPopupMenuFont();
        auto fontHeight = floor((double) getHeight() * 0.125);
        font.setHeight(fontHeight);
        g.setColour(Colours::white);
        g.setFont(font);
        auto y = floor(((double) getHeight() - fontHeight) / 2.0);
        g.drawFittedText(message,0, y, getWidth(), fontHeight, Justification::centred, 1);
    }
    
    const int childNumber;
    bool isMouseOver {false};
    bool isDragging {false};
    Point<int> dragDelta {0,0};
    Point<int> mouseDownPosition {0,0};
    String message {""};
    String childText {""};
    
};
