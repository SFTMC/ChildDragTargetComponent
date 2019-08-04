# ChildDragTargetComponent
Pretty simple Component which uses the DragAndDropContainer::findParentDragContainerFor to allow Dragging and Dropping between Child Classes. First iteration only has Text Dropping, but will improve to add File Dropping aswell.

Steps for implementation:

1. Ensure that Parent Class inherits the DragAndDropContainer class. Within a plugin the Plugin Editor would inherit this method, whereas in a standalone app it would be the MainComponent.
2. Call the DragAndDropContainer::findParentDragContainerFor (this) within the mouseDrag(const MouseEvent& e) method within the component you want to drag items to.
