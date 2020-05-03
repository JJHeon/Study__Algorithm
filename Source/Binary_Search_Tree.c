#include "Binary_Search_Tree.h"
//순환적인 탐색 방법
Binary_Search_Tree_Node_* BST__Search_C(Binary_Search_Tree_Node_* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key)
        return node;
    else if (key < node->key)
        return BST__Search_C(node->left, key);
    else
        return BST__Search_C(node->right, key);
}
//반복적인 탐색 방법
Binary_Search_Tree_Node_* BST__Search_R(Binary_Search_Tree_Node_* node, int key) {
    while (node != NULL) {
        if (key == node->key)
            return node;
        else if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

Binary_Search_Tree_Node_* BST__CreateNode(int key, BST_data_formet data) {
    Binary_Search_Tree_Node_* new_node = (Binary_Search_Tree_Node_*)malloc(sizeof(Binary_Search_Tree_Node_));
    if (new_node == NULL) {
        printf("BST__CreateNode/Create Node ERROR\n");
        exit(1);
    }
    new_node->data = data;
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void BST__InsertNode(Binary_Search_Tree_Node_** const root, Binary_Search_Tree_Node_* new_node) {
}
void BST__DeleteNode(Binary_Search_Tree_Node_** const root, int key);
void BST__FreeMemory(Binary_Search_Tree_Node_* root);
