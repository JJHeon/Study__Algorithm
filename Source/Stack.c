#include "Stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//UAStack
bool UAStack__IsFull(UAStack_* obj) {
    return (obj->top == MAX_UASTACK_SIZE);
}
bool UAStack__IsEmpty(UAStack_* obj) {
    return obj->top == -1;
}

void UAStack__Initialization(UAStack_* obj) {
    memset(obj->array, 0, sizeof(UAStack_Element) * MAX_UASTACK_SIZE);
    obj->top = -1;
}
void UAStack__Push(UAStack_* obj, UAStack_Element item) {
    if (UAStack__IsFull(obj)) {
        printf("FullStack ERROR\n");
        exit(1);
    }
    obj->array[++(obj->top)] = item;
}

UAStack_Element UAStack__CreateElement(int data) {
    UAStack_Element temp = {data};
    return temp;
}
UAStack_Element UAStack__Pop(UAStack_* obj) {
    if (UAStack__IsEmpty(obj)) {
        printf("EmptyStack ERROR\n");
        exit(1);
    }
    return obj->array[obj->top--];
}
UAStack_Element UAStack__Peek(UAStack_* obj) {
    if (UAStack__IsEmpty(obj)) {
        printf("EmptyStack ERROR\n");
        exit(1);
    }
    if (UAStack__IsFull(obj)) {
        printf("FullStack ERROR\n");
        exit(1);
    }
    return obj->array[obj->top];
}

//ULStack

bool ULStack__IsEmpty(ULStack_* obj) {
    if (obj == NULL)
        return true;
    return false;
}

void ULStack__Push(ULStack_** obj, ULStack_Element item) {
    if ((*obj) == NULL) {
        (*obj) = (ULStack_*)malloc(sizeof(ULStack_));
        (*obj)->data = item;
        (*obj)->next = NULL;
    } else {
        ULStack_* temp = (ULStack_*)malloc(sizeof(ULStack_));
        temp->data = item;
        temp->next = (*obj);
        (*obj) = temp;
    }
}

ULStack_Element ULStack__CreateElement(int data) {
    ULStack_Element temp = {data};
    return temp;
}
ULStack_Element ULStack__Pop(ULStack_** obj) {
    if (ULStack__IsEmpty((*obj))) {
        printf("ULStackPop Error\n");
        exit(1);
    }
    ULStack_Element temp1 = (*obj)->data;
    ULStack_* temp2 = (*obj)->next;
    free((*obj));
    (*obj) = temp2;

    return temp1;
}
ULStack_Element ULStack__Peek(ULStack_* obj) {
    if (ULStack__IsEmpty(obj)) {
        printf("ULStackPeak Error\n");
        exit(1);
    }

    return obj->data;
}

void ULStack__MemoryFree(ULStack_* obj) {
    ULStack_* temp1;
    while (obj != NULL) {
        temp1 = obj->next;
        free(obj);
        obj = temp1;
    }
}