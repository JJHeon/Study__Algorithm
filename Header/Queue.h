#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Using Array Queue => UAQueue
*/
#define QUEUE_ARRAY_MAX_SIZE 50
typedef struct {
    int data;
} UAQeue_Element;
typedef struct {
    UAQeue_Element array[QUEUE_ARRAY_MAX_SIZE];
    int front;
    int rear;
} UAQueue_;

bool UAQueue__IsEmpty(UAQueue_* obj);
bool UAQueue__IsFull(UAQueue_* obj);

void UAQueue__Initialize(UAQueue_* obj);
void UAQueue__Enqueue(UAQueue_* obj, UAQeue_Element item);

UAQeue_Element UAQueue__Dequeue(UAQueue_* obj);
UAQeue_Element UAQueue__Peek(UAQueue_* obj);
UAQeue_Element UAQueue__CreateElement(int data_1);

/*
Using List Queue => ULQueue
*/
typedef struct {
    int data1;
} ULQueue_Element;
typedef struct ULQueue_Node_ {
    ULQueue_Element data;
    struct ULQueue_Node_* link;
} ULQueue_Node_;

typedef struct ULQueue_ {
    ULQueue_Node_* front;
    ULQueue_Node_* rear;
} ULQueue_;

bool ULQueue__IsEmpty(ULQueue_* obj);

void ULQueue__Initialize(ULQueue_* obj);
void ULQueue__Enqueue(ULQueue_* obj, ULQueue_Node_* new_node);
void ULQueue__Destructor(ULQueue_* obj);

ULQueue_Element ULQueue__Dequeue(ULQueue_* obj);
ULQueue_Element ULQueue__Peek(ULQueue_* obj);

ULQueue_Node_* ULQueue__CreateNode(int data_1);

#endif