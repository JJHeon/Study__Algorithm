#ifndef __DEQUE_H_
#define __DEQUE_H_

#include <stdbool.h>
/*
Deque = Double-ended queue
전단과 후단 모두에서 삽입과 삭제 가능.
이중 연결 리스트 사용.
*/

typedef struct {
    int data1;
} Deque_Element;
typedef struct Deque_Node_ {
    Deque_Element data;
    struct Deque_Node_* left_link;
    struct Deque_Node_* right_link;
} Deque_Node_;
typedef struct Deque_ {
    Deque_Node_* front;
    Deque_Node_* rear;
} Deque_;

bool Deque__IsEmpty(Deque_* obj);

void Deque__Initialize(Deque_* obj);
void Deque__Destructor(Deque_* obj);

void Deque__AddFront(Deque_* obj, Deque_Node_* new_node);
void Deque__AddRear(Deque_* obj, Deque_Node_* new_node);

Deque_Node_* Deque__CreateNode(int data_1);

Deque_Element Deque__GetFront(Deque_* obj);
Deque_Element Deque__GetRear(Deque_* obj);
Deque_Element Deque__DeleteFront(Deque_* obj);
Deque_Element Deque__DeleteRear(Deque_* obj);
#endif