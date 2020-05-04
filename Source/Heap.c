#include "Test_Control.h"
#if ___HEAP

#include <string.h>
#include "Power.h"
#include "Heap.h"

void InitHeap(Heap_* obj) {
    memset(obj, 0, sizeof(Heap_));
}
Node_ CreateNode(int key) {
    Node_ new_node;
    new_node.key = key;
    return new_node;
}
void InsertMaxHeap(Heap_* obj, Node_ item) {
    int i = ++obj->heap_point;
    for (; ((i != 1) && (item.key > obj->heap[i / 2].key)); i /= 2) {
        obj->heap[i] = obj->heap[i / 2];
    }
    obj->heap[i] = item;
}
Node_ DeleteMaxHeap(Heap_* obj) {
    Node_ item = obj->heap[1];
    Node_ temp = obj->heap[obj->heap_point--];
    int parent = 1, child = 2;
    while (child <= obj->heap_point) {
        if ((child < obj->heap_point) && (obj->heap[child].key < obj->heap[child + 1].key))
            child++;
        if (temp.key >= obj->heap[child].key)
            break;
        obj->heap[parent] = obj->heap[child];
        parent = child;
        child *= 2;
    }
    obj->heap[parent] = temp;
    return item;
}
void PrintHeap(Heap_* obj) {
    int j = 1, space_gap = 0;
    int rate = 2, per = 2;
    int l = 0;
    while (j < obj->heap_point) {
        j += rate;
        rate *= 2;
    }
    space_gap = (j + 1) * 2;
    rate = 2;
    j = 1;

    for (int i = 1; i <= obj->heap_point; i++) {
        //공백 추가
        for (int k = 0; k < space_gap/per; k++) {
            printf(" ");
        }
        printf("%d",obj->heap[i].key);

        if (i == j) {
            printf("\n");
            j += rate;
            rate *= 2;
            per += Power_R(2, l++);
        }
    }
    printf("\n");
}

void SortHeap(Node_ obj[], int obj_size){
    Heap_ temp_storage;
    InitHeap(&temp_storage);

    for (int i = 0; i < obj_size; i++){
        InsertMaxHeap(&temp_storage, obj[i]);
    }

    for (int i = (obj_size - 1); i >= 0; i--){
        obj[i] = DeleteMaxHeap(&temp_storage);
    }
}
#endif
