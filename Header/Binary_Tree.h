#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_
#include <stdbool.h>

/*

Binary_Tree_Node => BTN_

*/
typedef struct Binary_Tree_Node_ {
    int data;
    struct Binary_Tree_Node_ *left, *right;
} Binary_Tree_Node_;

//중위순회
void BTN__Inorder(Binary_Tree_Node_* root);
//전위순회
void BTN__Preorder(Binary_Tree_Node_* root);
//후위순회
void BTN__Postorder(Binary_Tree_Node_* root);
/*
BTN_A_ BTN_Arange, Binary tree용으로 어레인지 한 큐
*/
typedef struct {
    Binary_Tree_Node_* data1;
} BTN_A_ULQueue_Element;
typedef struct BTN_A_ULQueue_Node_ {
    BTN_A_ULQueue_Element data;
    struct BTN_A_ULQueue_Node_* link;
} BTN_A_ULQueue_Node_;

typedef struct BTN_A_ULQueue_ {
    BTN_A_ULQueue_Node_* front;
    BTN_A_ULQueue_Node_* rear;
} BTN_A_ULQueue_;

bool BTN_A_ULQueue__IsEmpty(BTN_A_ULQueue_* obj);

void BTN_A_ULQueue__Initialize(BTN_A_ULQueue_* obj);
void BTN_A_ULQueue__Enqueue(BTN_A_ULQueue_* obj, BTN_A_ULQueue_Node_* new_node);
void BTN_A_ULQueue__Destructor(BTN_A_ULQueue_* obj);
BTN_A_ULQueue_Node_* BTN_A_ULQueue__CreateNode(Binary_Tree_Node_* data_1);

BTN_A_ULQueue_Element BTN_A_ULQueue__Dequeue(BTN_A_ULQueue_* obj);
BTN_A_ULQueue_Element BTN_A_ULQueue__Peek(BTN_A_ULQueue_* obj);

//레벨순회
void BTN__Levelorder(Binary_Tree_Node_* root);
//노드개수 구하기
int BTN__GetNodeCount(Binary_Tree_Node_* node);
//leaf 노드 개수 구하기
int BTN__GetLeafNodeCount(Binary_Tree_Node_* node);
//Height
int BTN__GetHeight(Binary_Tree_Node_* node);
#endif