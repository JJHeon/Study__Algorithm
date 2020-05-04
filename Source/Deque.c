#include "Test_Control.h"
#if ___DEQUEUE_USING_DOUBLY_LINKED_LIST

#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool Deque__IsEmpty(Deque_* obj) {
    return (obj->front == NULL && obj->rear == NULL);
}

void Deque__Initialize(Deque_* obj) {
    obj->front = NULL;
    obj->rear = NULL;
}
void Deque__Destructor(Deque_* obj) {
    if (Deque__IsEmpty(obj)) {
        return;
    }

    Deque_Node_* temp1 = obj->front;
    Deque_Node_* temp2;
    while (temp1 != NULL) {
        temp2 = temp1->right_link;
        free(temp1);
        temp1 = temp2;
    }

    obj->front = NULL;
    obj->rear = NULL;
}

void Deque__AddFront(Deque_* obj, Deque_Node_* new_node) {
    if (new_node == NULL) {
        printf("Deque__AddFront/new_node == NULL\n");
        exit(1);
    }

    if (obj->front == NULL && obj->rear == NULL) {
        obj->front = obj->rear = new_node;
    } else {
        obj->front->left_link = new_node;
        new_node->right_link = obj->front;
        obj->front = new_node;
    }
}
void Deque__AddRear(Deque_* obj, Deque_Node_* new_node) {
    if (new_node == NULL) {
        printf("Deque__AddRear/new_node == NULL\n");
        exit(1);
    }
    if (obj->front == NULL && obj->rear == NULL) {
        obj->front = obj->rear = new_node;
    } else {
        obj->rear->right_link = new_node;
        new_node->left_link = obj->rear;
        obj->rear = new_node;
    }
}

Deque_Node_* Deque__CreateNode(int data_1) {
    Deque_Node_* new_node = (Deque_Node_*)malloc(sizeof(Deque_Node_));
    if (new_node == NULL) {
        printf("Deque__CreateNode/Memory Allocate ERROR\n");
        exit(1);
    }
    new_node->data.data1 = data_1;
    new_node->left_link = NULL;
    new_node->right_link = NULL;
    return new_node;
}

Deque_Element Deque__GetFront(Deque_* obj) {
    if (Deque__IsEmpty(obj)) {
        printf("Deque__GetFront/Queue empty\n");
        exit(1);
    }
    Deque_Element temp = obj->front->data;
    return temp;
}
Deque_Element Deque__GetRear(Deque_* obj) {
    if (Deque__IsEmpty(obj)) {
        printf("Deque__GetRear/Queue empty\n");
        exit(1);
    }
    Deque_Element temp = obj->rear->data;
    return temp;
}
Deque_Element Deque__DeleteFront(Deque_* obj) {
    if (Deque__IsEmpty(obj)) {
        printf("Deque__DeleteFront/Queue empty\n");
        exit(1);
    }
    Deque_Element temp;
    Deque_Node_* temp2;
    if (obj->front == obj->rear) {
        temp = obj->front->data;
        free(obj->front);
        obj->front = NULL;
        obj->rear = NULL;
        return temp;
    } else {
        temp = obj->front->data;
        temp2 = obj->front->right_link;
        free(obj->front);
        obj->front = temp2;
        obj->front->left_link = NULL;
        return temp;
    }
}
Deque_Element Deque__DeleteRear(Deque_* obj) {
    if (Deque__IsEmpty(obj)) {
        printf("Deque__DeleteRear/Queue empty\n");
        exit(1);
    }
    Deque_Element temp;
    Deque_Node_* temp2;
    if (obj->front == obj->rear) {
        temp = obj->rear->data;
        free(obj->rear);
        obj->front = NULL;
        obj->rear = NULL;
        return temp;
    } else {
        temp = obj->rear->data;
        temp2 = obj->rear->left_link;
        free(obj->rear);
        obj->rear = temp2;
        obj->rear->right_link = NULL;
        return temp;
    }
}
#endif