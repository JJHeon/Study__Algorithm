#ifndef __INSERTION_SORT_H_
#define __INSERTION_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct RecordType_ {
    int key;
} RecordType_;
/*
자료 구조가 배열에 대한 삽입정렬
*/
void SortInsertionInAscendingOrder(RecordType_* obj, int obj_size);

#endif