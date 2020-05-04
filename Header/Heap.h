#ifndef __HEAP_H_
#define __HEAP_H_

/*
CAUTION:
배열에 index 0은 사용하지 않는다.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEEP_SIZE 200
typedef struct {
    int key;
} Node_;
typedef struct {
    Node_ heap[MAX_HEEP_SIZE];
    int heap_point;
} Heap_;

void InitHeap(Heap_* obj);
Node_ CreateNode(int key);
void InsertMaxHeap(Heap_* obj, Node_ item);
Node_ DeleteMaxHeap(Heap_* obj);

void PrintHeap(Heap_* obj);

void SortHeap(Node_ obj[], int obj_size);
#endif