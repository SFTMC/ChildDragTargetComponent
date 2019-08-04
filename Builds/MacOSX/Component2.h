//
//  Component2.h
//  DragDrop
//
//  Created by Mark Barbaric on 28/07/2019.
//

#ifndef Component2_h
#define Component2_h

#include "DragTarget.h"

struct Component2 : public Component
{
    Component2()
    {
        addAndMakeVisible(&dragTarget);
    }
    
    ~Component2() = default;
    
    void paint(Graphics& g) override
    {
        g.fillAll(Colours::black);
    }
    
    void resized()
    {
        dragTarget.setBounds(5, 5, 60, 60);
    }
    
    DragTarget dragTarget;
};


#endif /* Component2_h */
