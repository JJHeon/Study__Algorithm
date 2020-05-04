#include "Binary_Search_Tree.h"
//BST 중위순회 일반 이진트리의 중위순회와 같음
void BST__Inorder(Binary_Search_Tree_Node_* root) {
    if (root) {
        BST__Inorder(root->left);
        printf("%d - ", root->key);
        BST__Inorder(root->right);
    }
}
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
void BST__InsertNode(Binary_Search_Tree_Node_** root, Binary_Search_Tree_Node_* new_node) {
    if (new_node == NULL) {
        printf("BST__InsertNode/ERROR\n");
        exit(1);
    }
    //빈값 NULL값 찾아가기
    Binary_Search_Tree_Node_* node = *root;
    Binary_Search_Tree_Node_* target = NULL;
    while (node != NULL) {
        target = node;
        if (new_node->key == target->key) {
            printf("BST__InsertNode/ERROR key value duplicated\n");
            return;
        } else if (new_node->key < target->key)
            node = target->left;
        else
            node = target->right;
    }

    //완전 처음, 루트노드조차 비어있는 경우
    if (node == NULL && target == NULL) {
        (*root) = new_node;
    } else if (new_node->key < target->key) {
        target->left = new_node;
    } else {
        target->right = new_node;
    }
}
BST_data_formet BST__DeleteNode(Binary_Search_Tree_Node_** root, int key) {
    Binary_Search_Tree_Node_* node = *root;
    Binary_Search_Tree_Node_* parant_node = NULL;
    Binary_Search_Tree_Node_* child_node = NULL;
    Binary_Search_Tree_Node_* left_successor = NULL;
    Binary_Search_Tree_Node_* right_successor = NULL;
    Binary_Search_Tree_Node_* left_parant_successor = NULL;
    Binary_Search_Tree_Node_* right_parant_successor = NULL;
    BST_data_formet return_deleted_node_data;

    while (node != NULL && key != node->key) {
        parant_node = node;
        node = (key < node->key) ? node->left : node->right;
    }
    //해당 키 탐색 실패
    if (node == NULL) {
        printf("BST__DeleteNode/ERROR the key you find don't exist\n");
        exit(1);
    }

    //case 1: 해당 키 단말노드일 경우
    if (node->right == NULL && node->left == NULL) {
        if (parant_node != NULL) {
            //부모노드에서 해당 노드 지우기
            if (parant_node->left == node) {
                parant_node->left = NULL;
            } else {
                parant_node->right = NULL;
            }
        }
        //삭제하려는게 루트 노드인경우
        else {
        }

    }
    //case 2: 지우려는 노드가 하나의 자식만을 가지는 경우
    else if (node->left == NULL || node->right == NULL) {
        child_node = (node->left != NULL) ? node->left : node->right;
        if (parant_node != NULL) {
            //부모노드에서 해당 노드 바꾸기
            if (parant_node->left == node) {
                parant_node->left = child_node;
            } else {
                parant_node->right = child_node;
            }
        }
        //지우려는 노드가 부모노드인경우
        else {
            *root = child_node;
        }
    }
    //case 3: 지우려는 노드가 2개의 자식을 가지는 경우
    else if (node->left != NULL && node->right != NULL) {
        //왼쪽 서브트리에서 후계자 찾기
        left_parant_successor = node;
        left_successor = node->left;
        //왼쪽 서브트리에서 후계자를 찾기위해 오른쪽 이동
        while (left_successor->right != NULL) {
            left_parant_successor = left_successor;
            left_successor = left_successor->right;
        }

        //오른쪽 서브트리에서 후계자 찾기
        right_parant_successor = node;
        right_successor = node->right;
        //오른쪽 서브트리에서 후계자를 찾기위해 왼쪽 이동
        while (right_successor->left != NULL) {
            right_parant_successor = right_successor;
            right_successor = right_successor->left;
        }

        //어느 트리의 후계자 키값이 가장 삭제하려는 노드와 가까운가?
        //왼쪽이 더 가까울 때 왼쪽후계자 선택
        if ((node->key - left_successor->key) > (right_successor->key - node->key)) {
            if (left_parant_successor->right == left_successor)
                left_parant_successor->right = left_successor->left;
            else
                left_parant_successor->left = left_successor->left;

            //루트 노드가 아닐떄 삭제 노드의 자리로 후계자 in
            if (parant_node != NULL) {
                if (parant_node->left == node) {
                    left_successor->left = node->left;
                    left_successor->right = node->right;
                    parant_node->left = left_successor;
                } else {
                    left_successor->left = node->left;
                    left_successor->right = node->right;
                    parant_node->right = left_successor;
                }
            }
            //루트 노드가 바꿔지는 대상일때
            else {
                left_successor->left = node->left;
                left_successor->right = node->right;
                *root = left_successor;
            }

        }
        //만약 둘다 동등하거나 오른쪽이 더 가깝다면 오른쪽을 노드의 키값을 선택한다.
        else {
            //후계자의 부모와 후계자의 자식간 연결
            if (right_parant_successor->left == right_successor)
                right_parant_successor->left = right_successor->right;
            else
                right_parant_successor->right = right_successor->right;

            //루트 노드가 아닐떄 삭제 노드의 자리로 후계자 in
            if (parant_node != NULL) {
                if (parant_node->left == node) {
                    right_successor->left = node->left;
                    right_successor->right = node->right;
                    parant_node->left = right_successor;
                } else {
                    right_successor->left = node->left;
                    right_successor->right = node->right;
                    parant_node->right = right_successor;
                }
            }
            //루트 노드가 바꿔지는 대상일때
            else {
                right_successor->left = node->left;
                right_successor->right = node->right;
                *root = right_successor;
            }
        }
    }

    return_deleted_node_data = node->data;
    free(node);
    return return_deleted_node_data;
}
//후위순회 방식으로 메모리 할당해제
void BST__FreeMemoryUsingPostorder(Binary_Search_Tree_Node_* root) {
    if (root) {
        BST__FreeMemoryUsingPostorder(root->left);
        BST__FreeMemoryUsingPostorder(root->right);
        free(root);
    }
}
