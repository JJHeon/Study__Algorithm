#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_
#include <stdio.h>
#include <stdlib.h>
/*
Binary Search Tree => BST

저장방식 O, 삽입,삭제 연산 O, 탐색 O,순환 또는 반복 구분 O
*/
typedef int BST_data_formet;
typedef struct Binary_Search_Tree_Node_ {
    int key;
    BST_data_formet data;
    struct Binary_Search_Tree_Node_ *left, *right;
} Binary_Search_Tree_Node_;

Binary_Search_Tree_Node_* BST__CreateNode(int key, BST_data_formet data);
void BST__InsertNode(Binary_Search_Tree_Node_** root, Binary_Search_Tree_Node_* new_node);
BST_data_formet BST__DeleteNode(Binary_Search_Tree_Node_** root, int key);
//후위순회 방식으로 메모리 할당해제
void BST__FreeMemoryUsingPostorder(Binary_Search_Tree_Node_* root);

//BST 중위순회 일반 이진트리의 중위순회와 같음
void BST__Inorder(Binary_Search_Tree_Node_* root);

//순환적인 탐색 방법
Binary_Search_Tree_Node_* BST__Search_C(Binary_Search_Tree_Node_* node, int key);
Binary_Search_Tree_Node_* BST__Search_R(Binary_Search_Tree_Node_* node, int key);

#endif