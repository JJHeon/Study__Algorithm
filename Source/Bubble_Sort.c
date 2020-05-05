#include "Test_Control.h"

#if ___BUBBLE_SORT
#include "Bubble_Sort.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void SortBubbleInAscendingOrder(RecordType_* obj, int obj_size) {
    RecordType_ temp;
    for (int i = obj_size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            if (obj[j].key > obj[j + 1].key) SWAP(obj[j], obj[j + 1], temp);
    }
}
#endif