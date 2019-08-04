/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(&dragTarget);
    createWidgets();
    setSize (400, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::createWidgets()
{
    for(int i = 0; i < NUM_CHILD_DRAG_CONTAINERS; ++i)
    {
        auto* childDragContainer = new ChildDragContainer(i);
        addAndMakeVisible(childDragContainer);
        childDragContainers.add(childDragContainer);
    }
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    auto width1 = floor((double) getWidth()  / (double) NUM_CHILD_DRAG_CONTAINERS);
    auto i = 0;
    
    for(auto& c : childDragContainers)
    {
        c->setBounds(i * width1, 0, width1, width1);
        i++;
    }
    
    auto width2 = floor((double) getWidth() * 0.5);
    auto x = floor(((double) getWidth() - (double) width2)/ 2.0);
    dragTarget.setBounds(x, width1, width2, width2);
}
