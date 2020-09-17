#include "Test_Control.h"

#if ___QUICK_SORT
#include "Quick_Sort.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

static void SortInsertionInAscendingOrder(RecordType_* obj, int left, int right);
static int PartitionInAscendingOrder(RecordType_* array, int left, int right);

static int PartitionInAscendingOrder(RecordType_* array, int left, int right) {
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

void QuickSortInAscendingOrder__ImproveUsingInsertion(RecordType_* array, int left, int right, int M_Param) {
    int i, j;
    
    RecordType_ temp;

    if (right - left <= M_Param)
        SortInsertionInAscendingOrder(array, left, right);
    else {
        int pivot = array[right].key;
        i = left - 1;
        j = right;

        while (true) {
            while (array[++i].key < pivot)
                ;

            while (array[--j].key > pivot)
                ;

            if (i >= j) break;

            SWAP(array[i], array[j], temp);
        }

        SWAP(array[i], array[right], temp);
        QuickSortInAscendingOrder__ImproveUsingInsertion(array, left, i - 1, M_Param);
        QuickSortInAscendingOrder__ImproveUsingInsertion(array, i + 1, right, M_Param);
    } 
}

void QuickSortInAscendingOrder__ImproveUsingSplitInMiddleValue(RecordType_* array, int left, int right) {
    int i, j, middle_value;

    RecordType_ temp;

    if (right - left > 0){
        middle_value = (left + right) / 2;
        if (array[left].key > array[middle_value].key) SWAP(array[left], array[middle_value], temp);
        if (array[left].key > array[right].key) SWAP(array[left], array[right], temp);
        if (array[middle_value].key > array[right].key) SWAP(array[middle_value], array[right], temp);
        SWAP(array[middle_value], array[right], temp);
    

        int pivot = array[right].key;
        
        i = left-1;
        j = right;

        while (true) {
            while (array[++i].key < pivot)
                ;

            while (array[--j].key > pivot)
                ;

            if (i >= j) break;

            SWAP(array[i], array[j], temp);
        }

        SWAP(array[i], array[right], temp);
        QuickSortInAscendingOrder__ImproveUsingSplitInMiddleValue(array, left, i - 1);
        QuickSortInAscendingOrder__ImproveUsingSplitInMiddleValue(array, i + 1, right);
    }
}

/*==========================================================================*/

static void SortInsertionInAscendingOrder(RecordType_* obj, int left, int right) {
    RecordType_ key_pointer;
    int j = 0;
    for (int i = left + 1; i <= right; i++) {
        key_pointer = obj[i];
        for (j = i - 1; (j >= left) && (obj[j].key > key_pointer.key); j--) {
            obj[j + 1] = obj[j];
        }
        obj[j + 1] = key_pointer;

    }

}

#endif