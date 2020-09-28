#include "Test_Control.h"

#if ___MERGE_SORT
#include "Merge_Sort.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

static void MergeInAscendingOrder(RecordType_* obj, int left, int middle, int right);

void SortMergeInAscendingOrder(RecordType_* obj, int left, int right) {
    if (right > left) {
        int middle = (right + left) / 2;
        SortMergeInAscendingOrder(obj, left, middle);
        SortMergeInAscendingOrder(obj, middle + 1, right);
        MergeInAscendingOrder(obj, left, middle, right);
    }
}

static void MergeInAscendingOrder(RecordType_* obj, int left, int middle, int right) {
    int i = left;
    int j = middle + 1;
    int k = 0;

    RecordType_* temp = (RecordType_*)malloc((right - left + 1) * sizeof(RecordType_*));
    while (i <= middle && j <= right) {
        if (obj[i].key < obj[j].key)
            temp[k++] = obj[i++];

        else
            temp[k++] = obj[j++];
    }
    if (i > middle)
        for (int p = j; p <= right; p++) temp[k++] = obj[p];
    else
        for (int p = i; p <= middle; p++) temp[k++] = obj[p];

    for (int p = left; p <= right; p++) {
        obj[p] = temp[p - left];
    }

    free(temp);
}

#endif