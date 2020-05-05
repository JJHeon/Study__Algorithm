#include "Test_Control.h"

#if ___SELECTION_SORT
#include "Selection_Sort.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void SortSelectionInAscendingOrder(RecordType_* obj, int obj_size) {
    int min;
    RecordType_ temp;
    for (int current_pointer = 0; current_pointer < obj_size - 1; current_pointer++) {
        min = current_pointer;
        for (int i = current_pointer + 1; i < obj_size; i++) {
            if (obj[min].key > obj[i].key) min = i;
        }
        SWAP(obj[min], obj[current_pointer], temp);
    }
}
#endif