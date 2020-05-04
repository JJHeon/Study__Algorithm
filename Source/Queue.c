#include "Test_Control.h"
#if ___QUEUE_USING_ARRAY

#include "Queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool UAQueue__IsEmpty(UAQueue_* obj) {
    return obj->front == obj->rear;
}
bool UAQueue__IsFull(UAQueue_* obj) {
    return ((obj->rear + 1) % QUEUE_ARRAY_MAX_SIZE) == obj->front;
}

void UAQueue__Initialize(UAQueue_* obj) {
    memset(obj->array, 0, sizeof(obj->array));
    obj->front = 0;
    obj->rear = 0;
}
void UAQueue__Enqueue(UAQueue_* obj, UAQeue_Element item) {
    if (UAQueue__IsFull(obj)) {
        printf("UAQueue__Enqueue/UAQueue__IsFull\n");
        return;
    }
    obj->rear = (obj->rear + 1) % QUEUE_ARRAY_MAX_SIZE;
    obj->array[obj->rear] = item;
}

UAQeue_Element UAQueue__Dequeue(UAQueue_* obj) {
    if (UAQueue__IsEmpty(obj)) {
        printf("UAQueue__Dequeue/UAQueue__IsEmpty\n");
        exit(1);
    }
    obj->front = (obj->front + 1) % QUEUE_ARRAY_MAX_SIZE;
    return obj->array[obj->front];
}
UAQeue_Element UAQueue__Peek(UAQueue_* obj) {
    if (UAQueue__IsEmpty(obj)) {
        printf("UAQueue__Peek/UAQueue__IsEmpty\n");
        exit(1);
    }
    return obj->array[(obj->front + 1) % QUEUE_ARRAY_MAX_SIZE];
}
UAQeue_Element UAQueue__CreateElement(int data_1) {
    UAQeue_Element temp = {data_1};
    return temp;
}

#endif


#if ___QUEUE_USING_LIST
#include "Queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool ULQueue__IsEmpty(ULQueue_* obj) {
    return (obj->front == NULL && obj->rear == NULL);
}

void ULQueue__Initialize(ULQueue_* obj) {
    obj->front = NULL;
    obj->rear = NULL;
}
void ULQueue__Enqueue(ULQueue_* obj, ULQueue_Node_* new_node) {
    if (new_node == NULL) {
        printf("ULQueue__Enqueue/new_node == NULL\n");
        exit(1);
    }
    if (obj->front == NULL && obj->rear == NULL) {
        obj->front = obj->rear = new_node;
    } else {
        obj->rear->link = new_node;
        obj->rear = new_node;
    }
}
void ULQueue__Destructor(ULQueue_* obj) {
    if (ULQueue__IsEmpty(obj)) {
        return;
    }

    ULQueue_Node_* temp1 = obj->front;
    ULQueue_Node_* temp2;
    while (temp1 != NULL) {
        temp2 = temp1->link;
        free(temp1);
        temp1 = temp2;
    }

    obj->front = NULL;
    obj->rear = NULL;
}

ULQueue_Element ULQueue__Dequeue(ULQueue_* obj) {
    if (ULQueue__IsEmpty(obj)) {
        printf("ULQueue__Dequeue/Queue empty\n");
        exit(1);
    }
    ULQueue_Element temp;
    ULQueue_Node_* temp2;
    if (obj->front == obj->rear) {
        temp = obj->front->data;
        free(obj->front);
        obj->front = NULL;
        obj->rear = NULL;
        return temp;
    } else {
        temp = obj->front->data;
        temp2 = obj->front->link;
        free(obj->front);
        obj->front = temp2;
        return temp;
    }
}
ULQueue_Element ULQueue__Peek(ULQueue_* obj) {
    if (ULQueue__IsEmpty(obj)) {
        printf("ULQueue__Peek/Queue empty\n");
        exit(1);
    }
    ULQueue_Element temp = obj->front->data;
    return temp;
}
ULQueue_Node_* ULQueue__CreateNode(int data_1) {
    ULQueue_Node_* obj = (ULQueue_Node_*)malloc(sizeof(ULQueue_Node_));
    if (obj == NULL) {
        printf("ULQueue__CreateNode/Memory Allocate ERROR\n");
        exit(1);
    }

    obj->data.data1 = data_1;
    obj->link = NULL;
    return obj;
}
#endif