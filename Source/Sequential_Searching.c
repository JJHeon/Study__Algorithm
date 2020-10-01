#include "Test_Control.h"

#if ___SEQUENTIAL_SEARCHING
#include "Sequential_Searching.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int SearchSequential(RecordType_* obj, int obj_size, int search_key) {
    for (int i = 0; i < obj_size; i++) {
        if(obj[i].key == search_key){
            return i;
        }
    }
    return -1;
}
#endif