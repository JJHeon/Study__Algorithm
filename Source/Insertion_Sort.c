#include "Test_Control.h"
#if ___INSERTION_SORT

#include "Insertion_Sort.h"

void SortInsertionInAscendingOrder(RecordType_* obj, int obj_size){
    RecordType_ key_pointer;
    int j = 0;
    for (int i = 1; i < obj_size; i++){
        key_pointer = obj[i];
        for (j = i - 1; (j >= 0) && (obj[j].key > key_pointer.key); j--){
            obj[j + 1] = obj[j];
        }
        obj[j + 1] = key_pointer;
    }
}


#endif