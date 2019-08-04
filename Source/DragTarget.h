//
//  DragTarget.h
//  DragDrop
//
//  Created by Mark Barbaric on 28/07/2019.
//

#ifndef DragTarget_h
#define DragTarget_h

struct DragTarget : public Component,
                    public DragAndDropTarget
{
    DragTarget()
    {
        
    }
    
    ~DragTarget() = default;
    
    void setItemDragEnterPaintState()
    {
        message = "Drag Enter";
        fileWasLoaded = false;
        somethingIsBeingDraggedOver = true;
        dragOver = false;
    }
    
    void setItemDragExitPaintState()
    {
        message = "Drag Exit";
        fileWasLoaded = false;
        somethingIsBeingDraggedOver = false;
        dragOver = true;
    }
    
    void setItemDroppedPaintState(const String& dragText)
    {
        message = dragText + " Dropped";
        fileWasLoaded = true;
        somethingIsBeingDraggedOver = false;
        dragOver = true;
    }
    
    void itemDragEnter (const SourceDetails& dragSourceDetails) override
    {
        setItemDragEnterPaintState();
        repaint();
    }
    
    void itemDragExit (const SourceDetails &dragSourceDetails) override
    {
        setItemDragExitPaintState();
        repaint();
    }
    
    void itemDropped (const SourceDetails &dragSourceDetails) override
    {
        auto dragDetails = dragSourceDetails.description.toString();
        setItemDroppedPaintState(dragDetails);
        repaint();
    }
    
    bool isInterestedInDragSource (const SourceDetails& dragSourceDetails) override
    {return true;}
    
    void paint(Graphics& g) override
    {
        g.fillAll (Colours::green.withAlpha (0.2f));
        
        if(dragOver)
        {
            g.setColour(Colours::white);
            g.drawRect (getLocalBounds(), 1);
        }
        else if (somethingIsBeingDraggedOver)
        {
            g.setColour (Colours::red);
            g.drawRect (getLocalBounds(), 1);
        }
        
        else if(fileWasLoaded)
        {
            g.setColour (Colours::green);
            g.drawRect (getLocalBounds(), 1);
        }

        g.setColour (getLookAndFeel().findColour (Label::textColourId));
        auto font = getLookAndFeel().getPopupMenuFont();
        auto fontHeight = floor((double) getHeight() * 0.125);
        font.setHeight(fontHeight);
        g.setFont (font);
        auto y = floor(((double) getHeight() - fontHeight) / 2.0);
        g.drawFittedText (message, 0, y, getWidth(), fontHeight, Justification::centred, 1);
    }
    
    String message;
    bool somethingIsBeingDraggedOver {false};
    bool fileWasLoaded {false};
    bool dragOver {true};
};


#endif /* DragTarget_h */
