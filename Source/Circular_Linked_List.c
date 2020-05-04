#include "Test_Control.h"
#if ___CIRCULAR_LINKED_LIST

#include "Circular_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

LC_Node* LC__CreateNode(LC_Element data) {
    LC_Node* new_node = (LC_Node*)malloc(sizeof(LC_Node));
    if (new_node == NULL) {
        printf("ListCircularCreateNode_JH/Create Node Error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

LC_Node* LC__Search_JH(LC_Node* head, LC_Element data) {
    LC_Node* temp1 = head->link;

    if (head->data == data) {
        return head;
    }
    while (temp1 != head) {
        if (temp1->data == data)
            return temp1;
        temp1 = temp1->link;
    }
    return NULL;
}
void LC__MemoryFree(LC_Node* temp) {
    LC_Node* temp1 = temp->link;
    LC_Node* temp2;
    if (temp1 == temp) {  //list 1개일 경우
        free(temp);
        return;
    }
    while (temp1 != temp) {
        temp2 = temp1->link;
        free(temp1);
        temp1 = temp2;
    }
    free(temp);
    return;
}
void LC__Display(LC_Node* head) {
    LC_Node* temp = head->link;
    if (temp == head) {  //list 1개인 경우
        printf("%d ->", temp->data);
        return;
    }

    printf("%d ->", head->data);
    while (temp != head) {
        printf("%d ->", temp->data);
        temp = temp->link;
    }
    return;
}
void LC__Insert(LC_Node** phead, LC_Node* pre, LC_Node* new_node) {
    if (*phead == NULL) {
        (*phead) = new_node;
        (*phead)->link = (*phead);
    } else if (pre == NULL) {
        new_node->link = (*phead);
        LC_Node* temp = (*phead)->link;
        while (temp->link != (*phead)) {
            temp = temp->link;
        }
        temp->link = new_node;
        (*phead) = new_node;
    } else {
        new_node->link = pre->link;
        pre->link = new_node;
    }
}
#endif