#ifndef __HEAP_EXAMPLE_H_
#define __HEAP_EXAMPLE_H_
/*
NOTE:
시물레이션 치고 허접하지만, 대충 키값에 따라 우선순위가 바뀌기 때문에 정해진 순서로 실행되지 않음을 보이고 싶은 예제 같다.
우선순위는 랜덤값으로 부여되기 때문에 우리가 예측할 수 없다.


CAUTION:
배열에 index 0은 사용하지 않는다.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Heap_Example.h"
#include "Power.h"



/*
Heap
*/
#define MAX_HEEP_SIZE 200
typedef struct {
    int key;
    int type;
    int number;
} Node_;
typedef struct {
    Node_ heap[MAX_HEEP_SIZE];
    int heap_point;
} Heap_;
void InitHeap(Heap_* obj);
Node_ CreateNode(int key);
void InsertMinHeap(Heap_* obj, Node_ item);
Node_ DeleteMinHeap(Heap_* obj);
bool IsEmptyHeap(Heap_* obj);
void PrintHeap(Heap_* obj);


/*
아이스크림 가게 시물레이터
*/
#define ARRIVAL 1
#define ORDER 2
#define LEAVE 3

extern int free_seats;
extern double profit;

int random(int n);
bool is_seat_available(int num);
void order(int scoops);
void leave(int number);
void process_event(Heap_* heap, Node_ e);
#endif