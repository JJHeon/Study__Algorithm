#include "Test_Control.h"

#if ___BINARY_SEARCH
#include "Binary_Search.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int SearchBinary(RecordType_* obj, int left, int right, int search_key) {
    int mid = 0;
    while (right >= left) {
        mid = (right + left) / 2;
        if (obj[mid].key == search_key)
            return mid;
        else if (obj[mid].key > search_key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
#endif