#ifndef __QUICK_SORT_H_
#define __QUICK_SORT_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct RecordType_ {
    int key;
} RecordType_;
/*
자료 구조가 배열에 대한 퀵정렬
CAUTION:
반드시 array[0].key는 -1 이여야 함.
이러한 규칙을 제외하는 방법 중 하나는 
int Partition2InAscendingOrder(RecordType_* array, int left, int right){
    int pivot = array[right].key;
    int i = left - 1;  //왼쪽에서 오른쪽으로 움직이는 포인터, 가르키는 키값이 pivot보다 크면 멈춘다.
    int j = right;
    RecordType_ temp;
    while (true) {
        do {
            i += 1;
        } while (array[i].key < pivot && i<=right); //NOTE:
        do {
            j -= 1;
        } while (array[j].key > pivot && j>=left); //NOTE:

        if (i >= j) break;

        SWAP(array[i], array[j], temp);
    }
    SWAP(array[i], array[right], temp);

    return i;
}
다음과 같은 조건이 추가로 필요하지만, 더 많은 연산을 요구하기 떄문에 array[0] 을 QuickSorting만을 위한 공간으로 두는 편이 더 낫다고 판단됨.

만약 위 코드를 사용하고 싶다면 QuickSortInAscendingOrder() 내부에 호출되는 Partition 함수를 바꿔 사용하면 된다.
*/
//int Partition2InAscendingOrder(RecordType_* array, int left, int right);
int PartitionInAscendingOrder(RecordType_* array, int left, int right);
void QuickSortInAscendingOrder(RecordType_* array, int left, int right);

#endif