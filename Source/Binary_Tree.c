#include "Binary_Tree.h"
#include "Math.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//중위순회
void BTN__Inorder(Binary_Tree_Node_* root) {
    if (root) {
        BTN__Inorder(root->left);
        printf("%d - ", root->data);
        BTN__Inorder(root->right);
    }
}
//전위순회
void BTN__Preorder(Binary_Tree_Node_* root) {
    if (root) {
        printf("%d - ", root->data);
        BTN__Preorder(root->left);
        BTN__Preorder(root->right);
    }
}
//후위순회
void BTN__Postorder(Binary_Tree_Node_* root) {
    if (root) {
        BTN__Postorder(root->left);
        BTN__Postorder(root->right);
        printf("%d - ", root->data);
    }
}
//레벨순회 Queue 이용

bool BTN_A_ULQueue__IsEmpty(BTN_A_ULQueue_* obj) {
    return (obj->front == NULL && obj->rear == NULL);
}

void BTN_A_ULQueue__Initialize(BTN_A_ULQueue_* obj) {
    obj->front = NULL;
    obj->rear = NULL;
}
void BTN_A_ULQueue__Enqueue(BTN_A_ULQueue_* obj, BTN_A_ULQueue_Node_* new_node) {
    if (new_node == NULL) {
        printf("ULQueue__Enqueue/new_node == NULL\n");
        exit(1);
    }
    if (obj->front == NULL && obj->rear == NULL) {
        obj->front = obj->rear = new_node;
    } else {
        obj->rear->link = new_node;
        obj->rear = new_node;
    }
}
void BTN_A_ULQueue__Destructor(BTN_A_ULQueue_* obj) {
    if (BTN_A_ULQueue__IsEmpty(obj)) {
        return;
    }

    BTN_A_ULQueue_Node_* temp1 = obj->front;
    BTN_A_ULQueue_Node_* temp2;
    while (temp1 != NULL) {
        temp2 = temp1->link;
        free(temp1);
        temp1 = temp2;
    }

    obj->front = NULL;
    obj->rear = NULL;
}

BTN_A_ULQueue_Element BTN_A_ULQueue__Dequeue(BTN_A_ULQueue_* obj) {
    if (BTN_A_ULQueue__IsEmpty(obj)) {
        printf("ULQueue__Dequeue/Queue empty\n");
        exit(1);
    }
    BTN_A_ULQueue_Element temp;
    BTN_A_ULQueue_Node_* temp2;
    if (obj->front == obj->rear) {
        temp = obj->front->data;
        free(obj->front);
        obj->front = NULL;
        obj->rear = NULL;
        return temp;
    } else {
        temp = obj->front->data;
        temp2 = obj->front->link;
        free(obj->front);
        obj->front = temp2;
        return temp;
    }
}
BTN_A_ULQueue_Element BTN_A_ULQueue__Peek(BTN_A_ULQueue_* obj) {
    if (BTN_A_ULQueue__IsEmpty(obj)) {
        printf("ULQueue__Peek/Queue empty\n");
        exit(1);
    }
    BTN_A_ULQueue_Element temp = obj->front->data;
    return temp;
}
BTN_A_ULQueue_Node_* BTN_A_ULQueue__CreateNode(Binary_Tree_Node_* data_1) {
    BTN_A_ULQueue_Node_* obj = (BTN_A_ULQueue_Node_*)malloc(sizeof(BTN_A_ULQueue_Node_));
    if (obj == NULL) {
        printf("ULQueue__CreateNode/Memory Allocate ERROR\n");
        exit(1);
    }

    obj->data.data1 = data_1;
    obj->link = NULL;
    return obj;
}

void BTN__Levelorder(Binary_Tree_Node_* root) {

    BTN_A_ULQueue_ queue;
    BTN_A_ULQueue_Element data;
    BTN_A_ULQueue__Initialize(&queue);
    if (root == NULL) {
        return;
    }
    BTN_A_ULQueue__Enqueue(&queue, BTN_A_ULQueue__CreateNode(root));
    while (!BTN_A_ULQueue__IsEmpty(&queue)) {
        data = BTN_A_ULQueue__Dequeue(&queue);
        printf("%d - ", data.data1->data);
        if (data.data1->left) {
            BTN_A_ULQueue__Enqueue(&queue, BTN_A_ULQueue__CreateNode(data.data1->left));
        }
        if (data.data1->right) {
            BTN_A_ULQueue__Enqueue(&queue, BTN_A_ULQueue__CreateNode(data.data1->right));
        }
    }
    BTN_A_ULQueue__Destructor(&queue);
}

//노드개수 구하기
int BTN__GetNodeCount(Binary_Tree_Node_* node){
    int count = 0;
    if(node != NULL){
        count = 1 + BTN__GetNodeCount(node->left) + BTN__GetNodeCount(node->right);
    }
    return count;
}
//leaf 노드 개수 구하기
int BTN__GetLeafNodeCount(Binary_Tree_Node_* node){
    int count = 0;
    if(node != NULL){
        if(node->left == NULL && node->right == NULL)
            return 1;
        else{
            count = BTN__GetLeafNodeCount(node->left) + BTN__GetLeafNodeCount(node->right);
        }
    }
    return count;
}

int BTN__GetHeight(Binary_Tree_Node_* node){
    int height = 0;
    if(node != NULL){
        height = 1 + Max(BTN__GetHeight(node->left), BTN__GetHeight(node->right));
    }
    return height;
}