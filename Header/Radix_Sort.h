#ifndef __RADIX_SORT_H_
#define __RADIX_SORT_H_
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RecordType_ {
    int key;
} RecordType_;

/*
NOTE: key가 몇자리인지, key_max_digit에 넣어야됨
*/
void SortRadixInAscendingOrder(RecordType_* obj, int obj_size, int key_max_digit);

#endif