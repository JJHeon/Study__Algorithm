#include "Test_Control.h"
#if ___SINGLY_LINKED_LIST

#include "Singly_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>
/*
Singly Linked List
List_Singly_Linked => LS
*/
void LS__Insert(LS_Node **phead, LS_Node *p, LS_Node *new_node) {
    if (*phead == NULL) {  //공백 리스트인 경우
        new_node->link = NULL;
        (*phead) = new_node;
    } else if (p == NULL) {  //p가 NULL이면 첫번째 노드로 삽입
        new_node->link = (*phead);
        (*phead) = new_node;
    } else {  //p 다음 삽입
        new_node->link = p->link;
        p->link = new_node;
    }
}
void LS__Remove(LS_Node **phead, LS_Node *p, LS_Node *removing_node) {
    //p 삭제될 노드의 선행 노드
    if (p == NULL) {
        *phead = (*phead)->link;
    }
    p->link = removing_node->link;
    free(removing_node);
}
void LS__Display(LS_Node *head) {
    LS_Node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
LS_Node *LS__Search(LS_Node *head, int data) {
    LS_Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->link;
    }
    return temp;  //탐색 실패인 경우 NULL 반환
}
LS_Node *LS__Concat(LS_Node *head1, LS_Node *head2) {
    LS_Node *temp = head1;
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    else {
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = head2;
        return head1;
    }
}
LS_Node *LS__Reverse(LS_Node *head) {
    LS_Node *target = head;
    LS_Node *result = NULL;
    LS_Node *temp;
    while (target != NULL) {
        temp = result;
        result = target;
        target = target->link;
        result->link = temp;
    }
    return result;
}
LS_Node *LS__CreateNode(LS_Element data, LS_Node *link) {
    LS_Node *new_node;
    new_node = (LS_Node *)malloc(sizeof(LS_Node));
    if (new_node == NULL) {
        printf("ListSigleyLinkedListCreateNode/Create Node ERROR\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = link;
    return new_node;
}
void LS__MemoryFree(LS_Node *head) {
    LS_Node *temp1;
    LS_Node *temp2 = head;
    
    while (temp2 != NULL) {
        temp1 = temp2->link;
        free(temp2);
        temp2 = temp1;
    }
}
#endif