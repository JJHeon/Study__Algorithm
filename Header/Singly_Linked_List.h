#ifndef __SINGLY_LINKED_LIST_H_
#define __SINGLY_LINKED_LIST_H_
/*
Singly Linked List
List_Singly_Linked => LS
여기서 소개하는 리스트는 실제로 써먹기 어려움, 차라리 노드 개수를 가지고 headnode를 관리하는 구조체포인터를 추가로 정의해서 쓰는게 낫다.  
*/
typedef int LS_Element;
typedef struct LS_Node {
    LS_Element data;
    struct LS_Node *link;
} LS_Node;

void LS__Insert(LS_Node **phead, LS_Node *p, LS_Node *new_node);
void LS__Remove(LS_Node **phead, LS_Node *p, LS_Node *removing_node);
void LS__Display(LS_Node *head);
LS_Node *LS__Search(LS_Node *head, int data);
LS_Node *LS__Concat(LS_Node *head1, LS_Node *head2);
LS_Node *LS__Reverse(LS_Node *head);
LS_Node *LS__CreateNode(LS_Element data, LS_Node *link);
void LS__MemoryFree(LS_Node *head);

#endif
