#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_
#include <stdio.h>
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
void BST__InsertNode(Binary_Search_Tree_Node_** const root, Binary_Search_Tree_Node_* new_node);
void BST__DeleteNode(Binary_Search_Tree_Node_** const root, int key);
void BST__FreeMemory(Binary_Search_Tree_Node_* root);


//순환적인 탐색 방법
Binary_Search_Tree_Node_* BST__Search_C(Binary_Search_Tree_Node_* node, int key);
Binary_Search_Tree_Node_* BST__Search_R(Binary_Search_Tree_Node_* node, int key);


#endif