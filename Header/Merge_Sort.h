#ifndef __MERGE_SORT_H_
#define __MERGE_SORT_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct RecordType_ {
    int key;
} RecordType_;
/*

*/
void SortMergeInAscendingOrder(RecordType_* obj, int left, int right);

#endif