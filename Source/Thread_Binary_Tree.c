#include "Test_Control.h"
#if ___THREAD_BINARY_TREE

#include "Thread_Binary_Tree.h"
#include <stdio.h>


Thread_Binary_Tree_Node_* TBT__Findsuccessor(Thread_Binary_Tree_Node_* obj){
    Thread_Binary_Tree_Node_* obj_right = obj->right;
    //오른쪽 포인터가 NULL이거나 스레드면 오른쪽 포인트 반환
    if(obj_right == NULL || obj->is_thread)
        return obj_right;

    //만약 오른쪽 자식이면 다시 가장 왼쪽노드로 이동
    while (obj_right->left != NULL) obj_right = obj_right->left;
    return obj_right;
}
void TBT__InorderThread(Thread_Binary_Tree_Node_* obj){
    Thread_Binary_Tree_Node_* temp = obj;
    while (temp->left)
        temp = temp->left;

    do{
        printf("%d ", temp->data); //데이터 출력
        temp = TBT__Findsuccessor(temp); //후속자 함수 호출
    } while (temp);
}
#endif