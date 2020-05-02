#ifndef __STACK_H_
#define __STACK_H_
#include <stdbool.h>

/*
Stack_Using_Array => UAStack
*/
#define MAX_UASTACK_SIZE 50
typedef struct UAStack_Element {
    int data;
} UAStack_Element;
typedef struct UAStack_ {
    UAStack_Element array[MAX_UASTACK_SIZE];
    int top;
} UAStack_;


bool UAStack__IsFull(UAStack_* obj);
bool UAStack__IsEmpty(UAStack_* obj);

void UAStack__Initialization(UAStack_* obj);
void UAStack__Push(UAStack_* obj, UAStack_Element item);


UAStack_Element UAStack__CreateElement(int data);
UAStack_Element UAStack__Pop(UAStack_* obj);
UAStack_Element UAStack__Peek(UAStack_* obj);

/*
Stack_Using_List => ULStack
*/

typedef struct ULStack_Element{
    int data;
} ULStack_Element;
typedef struct ULStack_{
    ULStack_Element data;
    struct ULStack_* next;
} ULStack_;

bool ULStack__IsEmpty(ULStack_* obj);

void ULStack__Push(ULStack_** obj, ULStack_Element item);

ULStack_Element ULStack__CreateElement(int data);
ULStack_Element ULStack__Pop(ULStack_** obj);
ULStack_Element ULStack__Peek(ULStack_* obj);

void ULStack__MemoryFree(ULStack_* obj);

#endif