#ifndef __SHELL_SORT_H_
#define __SHELL_SORT_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct RecordType_ {
    int key;
} RecordType_;

void Sort__ShellInAscendingOrder__V1(RecordType_* obj, int obj_size);
void Sort__ShellInAscendingOrder__V2(RecordType_* obj, int obj_size);

#endif