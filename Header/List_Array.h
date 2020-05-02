#ifndef __LIST_ARRAY_H_
#define __LIST_ARRAY_H_
#include <stdbool.h>
/*
List made by Array
LsitArray => LA
용량에 제한이 있고 연산이 비효율적이지만 메모리 정적인 방법 
*/
#define LIST_ARRAY_MAX_SIZE 50
typedef int LA_Element;
typedef struct
{
    LA_Element list_array[LIST_ARRAY_MAX_SIZE];
    int length;
} LA_;

void LA__Initialize(LA_ *A);
bool LA__IsEmpty(LA_ *A);
bool LA__IsFull(LA_ *A);
void LA__Add(LA_ *A, int position, LA_Element item);
LA_Element LA__Delete(LA_ *A, int position);
void LA__Display(LA_ *A);
#endif