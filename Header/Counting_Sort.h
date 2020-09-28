#ifndef __COUNTING_SORT_H_
#define __COUNTING_SORT_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RecordType_ {
    int key;
} RecordType_;
/*
CAUTION: 0번지 이용할 수 없음.

계수정렬의 독특한 방식 때문인데, KEY가 0이면
KEY를 카운트 하는 배열에서 위치도 +1로 잡혀서 1번지나 더 큰 숫자로 0이 들어가지, 0번지에 들어갈 수 없다.
*/
void SortCountingInAscendingOrder(RecordType_* obj, int record_size, int range_of_key);

#endif