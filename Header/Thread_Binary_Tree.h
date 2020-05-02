#ifndef __THREAD_BINARY_TREE_H_
#define __THREAD_BINARY_TREE_H_

#include <stdbool.h>
/*

Thread_Binary_Tree => TBT

FIXME: 아직 완전하게 작성된 코드가 아님, 오직 제한된 형태로만 사용 가능

1. 노드는 Thread = true or false, 후속자의 노드 가르킴, NULL이 모두 정의되어있는 완전한 트리에서만
제한적으로 사용 가능.

2. 중위선행자 구현 X
3. 오직 순회만 가능.

*/

typedef struct Thread_Binary_Tree_Node_ {
    int data;
    bool is_thread;
    struct Thread_Binary_Tree_Node_ *left, *right;
} Thread_Binary_Tree_Node_;

Thread_Binary_Tree_Node_* TBT__Findsuccessor(Thread_Binary_Tree_Node_* obj);
void TBT__InorderThread(Thread_Binary_Tree_Node_* obj);

#endif