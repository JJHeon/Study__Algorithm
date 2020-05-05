#include "Test_Control.h"

#if ___QUICK_SORT
#include "Quick_Sort.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int PartitionInAscendingOrder(RecordType_* array, int left, int right) {
    int pivot = array[right].key;
    int i = left - 1;  //왼쪽에서 오른쪽으로 움직이는 포인터, 가르키는 키값이 pivot보다 크면 멈춘다.
    int j = right;
    RecordType_ temp;
    while (true) {
        do {
            i += 1;
        } while (array[i].key < pivot);
        do {
            j -= 1;
        } while (array[j].key > pivot);

        if (i >= j) break;

        SWAP(array[i], array[j], temp);
    }
    SWAP(array[i], array[right], temp);

    return i;
}
void QuickSortInAscendingOrder(RecordType_* array, int left, int right) {
    int i;
    if (right > left) {
        i = PartitionInAscendingOrder(array, left, right);
        QuickSortInAscendingOrder(array, left, i - 1);
        QuickSortInAscendingOrder(array, i + 1, right);
    }
}
#endif