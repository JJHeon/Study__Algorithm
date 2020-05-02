#include "Doubly_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

LD_Node* LD__CreateNode(LD_Element data) {
    LD_Node* new_node = (LD_Node*)malloc(sizeof(LD_Node));
    if (new_node == NULL) {
        printf("ListDoublyCreateNode/Create Node ERROR\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
LD_Node* LD__Search(LD_Node* object, LD_Element data) {
    while (object != NULL) {
        if (object->data == data)
            return object;
        object = object->next;
    }
    return object;  //탐색 실패시 NULL
}

void LD__MemoryFree(LD_Node* object) {
    LD_Node* temp;
    while (object != NULL) {
        temp = object->next;
        free(object);
        object = temp;
    }
}
void LD__Display(LD_Node* object) {
    while (object != NULL) {
        printf("%d->", object->data);
        object = object->next;
    }
    printf("\n");
}
void LD__Insert(LD_Node** phead, LD_Node* pre, LD_Node* new_node) {
    if (*phead == NULL) {  //공백 리스트인 경우
        new_node->next = NULL;
        (*phead) = new_node;
    } else if (pre == NULL) {
        new_node->next = (*phead);
        (*phead)->prev = new_node;
        (*phead) = new_node;
    } else {
        new_node->next = pre->next;
        new_node->prev = pre;
        pre->next = new_node;
    }
}
