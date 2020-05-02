#ifndef __CIRCULAR_LINKED_LIST_H_
#define __CIRCULAR_LINKED_LIST_H_

/*
Circular Linked List
Circular Linked List => LC
책에 있는건 구져서 내가 구현 
*/

typedef int LC_Element;
typedef struct LC_Node {
    LC_Element data;
    struct LC_Node* link;
} LC_Node;
LC_Node* LC__CreateNode(LC_Element data);
LC_Node* LC__Search_JH(LC_Node* head, LC_Element data);

void LC__MemoryFree(LC_Node* temp);
void LC__Display(LC_Node* head);
void LC__Insert(LC_Node** phead, LC_Node* pre, LC_Node* new_node);

#endif
