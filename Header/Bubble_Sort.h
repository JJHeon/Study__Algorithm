#ifndef __BUBBLE_SORT_H_
#define __BUBBLE_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct RecordType_ {
    int key;
} RecordType_;
/*
자료 구조가 배열에 대한 버블정렬
*/
void SortBubbleInAscendingOrder(RecordType_* obj, int obj_size);


#endif