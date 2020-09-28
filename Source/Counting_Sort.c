#include "Test_Control.h"

#if ___COUNTING_SORT
#include "Counting_Sort.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void SortCountingInAscendingOrder(RecordType_* obj, int record_size, int range_of_key) {
    int temp_counting_key[range_of_key + 1];
    RecordType_* temp_obj = (RecordType_*)calloc(record_size + 1, sizeof(RecordType_));

    memset(temp_counting_key, 0, sizeof(int) * (range_of_key + 1));
    memcpy(temp_obj, obj, sizeof(RecordType_) * (record_size + 1));

    //원소 개수 세어 count[]에저장
    for (int i = 1; i <= record_size; i++) temp_counting_key[obj[i].key]++;

    //원소가 들어갈 위치 계산
    for (int i = 2; i <= range_of_key; i++) temp_counting_key[i] = temp_counting_key[i] + temp_counting_key[i - 1];

    for (int i = record_size; i >= 1; i--) {
        obj[temp_counting_key[temp_obj[i].key]--] = temp_obj[i];
    }

    free(temp_obj);
}

#endif