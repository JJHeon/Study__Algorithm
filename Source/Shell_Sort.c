#include "Test_Control.h"

#if ___SHELL_SORT
#include "Shell_Sort.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

static void Sort__InsertionInAscendingOrder(RecordType_* list, int first, int last, int gap);

/*
Version 1 : GAP 이 h 인 쉘 정렬
GAP의 증가 순서를 3*h+1 인 h-정렬 화일 : 모든 h번째 원소를 정렬한 화일
증가 순서의 예 : ....1093, 364, 121, 40, 13, 4, 1

- 순열 h가 위와 같을 경우, 쉘 정렬의 비교 횟수는 N^(3/2)를 넘지 않는다. 라는 것이 주 목표
- 안정적인 제자리 정렬

CAUTION:
배열 1부터 시작, 0 X
*/
void Sort__ShellInAscendingOrder__V1(RecordType_* obj, int obj_size) {
    int j = 0, h = 0;

    for (h = 1; h < obj_size; h = 3 * h + 1) {
    }
    for (; h > 0; h = h / 3) {
        for (int i = h + 1; i <= obj_size; i++) {
            RecordType_ v = obj[i];
            j = i;

            while (j > h && obj[j - h].key > v.key) {
                obj[j] = obj[j - h];
                j = j - h;
            }

            obj[j] = v;
        }
    }
}
/*
Version 2 : 간격이 정렬할 값의 수 (size)/2 인 홀수(짝수가 나오면 +1을 해서 홀수로 만든다.)

범위 first ~ last

CAUTION:
배열0부터 시작.
*/
static void Sort__InsertionInAscendingOrder(RecordType_* list, int first, int last, int gap) {
    int j;
    RecordType_ key_pointer;

    for (int i = first + gap; i <= last; i = i + gap) {
        key_pointer = list[i];

        for (j = i - gap; j >= first && list[j].key > key_pointer.key; j = j - gap) {
            list[j + gap] = list[j];
        }

        list[j + gap] = key_pointer;
    }
}
void Sort__ShellInAscendingOrder__V2(RecordType_* obj, int obj_size) {
    int gap;

    for (gap = obj_size / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;  //gap 홀수로

        //부분 리스트의 개수는 gap과 같다.
        for (int i = 0; i < gap; i++) {
            //부분 리스트에 대한 삽입 정렬 수행
            Sort__InsertionInAscendingOrder(obj, i, obj_size - 1, gap);
        }
    }
}

#endif