## Singly Linked List

It is a sequence of nodes with objects (data) of the same type. A list is defined by a pointer that points to the first no of a sequence. If a list (pointer) is empty, then that pointer points to **NULL**. The list's prox field points to the next element in the sequence or to **NULL**, when the node is the last in the sequence.

## Doubly Linked List

It is a sequence of nodes with objects (data) of the same type. A list is defined by a pointer that points to the first no of a sequence. If a list (pointer) is empty, then that pointer points to **NULL**. The list's prox field points to the next element in the sequence or to **NULL**, when the node is the last in the sequence. The ant field points to the previous element in the sequence or to **NULL**, when it is the first in the sequence.

## Circular Singly/Doubly Linked List

The lists mentioned above can also be implemented in a circular way. Thus, when ***simply chained***, their last element will have the next pointer pointing to the first, while ***doubly linked*** lists will have the last with the next pointer pointing to the first element, and the first with the previous pointer pointing to the last.
