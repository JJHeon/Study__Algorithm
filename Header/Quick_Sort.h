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
void QuickSortInAscendingOrder(RecordType_* array, int left, int right);
//int Partition2InAscendingOrder(RecordType_* array, int left, int right);

/*
NOTE: 개선방법1-순환 제거

스택 자료구조를 사용한 순환 제거 방법은 여기서 사용하지 않겠음
*/

/*
NOTE: 개선방법2-작은 부분 화일
부분파일의 크기가 일정 크기 이하로 작아지면 삽입정렬 수행

M : 5 ~ 25 - 많은 응용에서 약 20% 정도 시간 절감 효과가 있음
*/
void QuickSortInAscendingOrder__ImproveUsingInsertion(RecordType_* array, int left, int right, int M_Param);

/*
NOTE: 개선방법3-중간 값 분할
pivot 선택할때 정렬하려는 Array의 가장 중간값을 사용하면 최악의 경우를 피할 수 있게됨을 이용
최악의 경우 발생 확률을 낮추는 것.

CAUTION: 사용금지

본래 의도대로 짜여지지 않음, 공부한 PPT대로 구성하면 정렬이 제대로 이루어지지 않는다. 따라서 문제가 됨
추후 더 공부해 보충이 필요

*/
void QuickSortInAscendingOrder__ImproveUsingSplitInMiddleValue(RecordType_* array, int left, int right);
#endif