#ifndef __234_TREE_H_
#define __234_TREE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RecordType_ {
    int key;
} RecordType_;

typedef struct Tree234_ {
    int num_node;
    struct Tree234* link[4];
    RecordType_ data[3];
} Tree234_Node_;



RecordType_* Tree234__CreateNode(int key);

void Tree234__InsertNode(Tree234_Node_** root, RecordType_* new_node);
void Tree234__DeleteNode(Tree234_Node_** root, int key);
RecordType_* Tree234__SearchKey(Tree234_Node_** root, int corresponding_key);
void Tree234__FreeAll(Tree234_Node_** root);

#endif