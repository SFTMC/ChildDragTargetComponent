/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DragContainer.h"
#include "DragTarget.h"
#include "Component.h"

#define NUM_CHILD_DRAG_CONTAINERS (4)
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
                        public DragAndDropContainer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void createWidgets();
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    DragTarget dragTarget;
    OwnedArray<ChildDragContainer> childDragContainers;
    ChildDragContainer childDragContainer {1};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
