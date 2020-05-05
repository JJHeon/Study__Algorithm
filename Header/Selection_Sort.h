#ifndef __SELECTION_SORT_H_
#define __SELECTION_SORT_H_

typedef struct RecordType_ {
    int key;
} RecordType_;
/*
자료 구조가 배열에 대한 선택정렬
*/
void SortSelectionInAscendingOrder(RecordType_* obj, int obj_size);
#endif