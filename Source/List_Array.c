#include "List_Array.h"
#include <stdio.h>
#include <stdlib.h>
/*
List made by Array
용량에 제한이 있고 연산이 비효율적이지만 메모리 정적인 방법 
*/
void LA__Initialize(LA_ *A) {
    A->length = 0;
}
bool LA__IsEmpty(LA_ *A) {
    return A->length == 0;
}
bool LA__IsFull(LA_ *A) {
    return A->length == LIST_ARRAY_MAX_SIZE;
}
void LA__Add(LA_ *A, int position, LA_Element item) {
    if (!LA__IsFull(A) && (position >= 0) && (position <= A->length)) {
        for (int i = (A->length - 1); i >= position; i--) {
            A->list_array[i + 1] = A->list_array[i];
        }
        A->list_array[position] = item;
        A->length++;
    }
}
LA_Element LA__Delete(LA_ *A, int position) {
    LA_Element item;
    if (position < 0 || position >= A->length) {
        printf("ListArrayDelete ERROR/position\n");
        exit(1);
    }
    item = A->list_array[position];
    for (int i = position; i < A->length - 1; i++)
        A->list_array[i] = A->list_array[i + 1];
    A->length--;
    return item;
}

void LA__Display(LA_ *A) {
    for (int i = 0; i < A->length; i++) {
        printf("%d ", A->list_array[i]);
    }
    printf("\n");
}
