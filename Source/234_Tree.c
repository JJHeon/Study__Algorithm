#include "Test_Control.h"

#if ___234_TREE
#include "234_Tree.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

static enum _KeyStatus { InsertFail,
                         SearchFail,
                         Success };
typedef enum _KeyStatus _KeyStatus;

static _KeyStatus InnerOperator(Tree234_Node_* target, Tree234_Node_* root_target, RecordType_* new_node);
static void InsertionSort(Tree234_Node_* obj, RecordType_* new_node);
/* ======================================================================== */

RecordType_* Tree234__CreateNode(int key) {
    RecordType_* subject = (RecordType_*)calloc(sizeof(RecordType_), 1);
    subject->key = key;
    return subject;
}

static void InsertData(Tree234_Node_* obj, RecordType_ new_node) {
    int i;
    for (i = obj->num_node - 1; i > 0; i--) {
        if (obj->data[i].key > new_node.key) {
            obj->data[i + 1] = obj->data[i];
        }
    }
    obj->data[++i] = new_node;
    obj->num_node++;
}

static _KeyStatus InnerOperator(Tree234_Node_* target, Tree234_Node_* root_target, RecordType_ new_node) {
    if (target->num_node == 3) {
        if (root_target == NULL) {
        } else {
            InsertData(root_target, target->data[1]);
            //NOTE:여기 수정중
        }
    }

    //마지막 노드인 경우
    if (target->link[0] == NULL && target->link[1] == NULL && target->link[2] == NULL && target->link[3] == NULL) {
        if (target->num_node < 3) {
            InsertData(target, new_node);
        }
    }
    //깊이가 있을 경우
    else {
        for (int i = 0; i < target->num_node; i++) {
            if (target->link[i] != NULL) {
                if (target->data[i].key > new_node.key) {
                    InnerOperator(target->link[i], target, new_node);
                } else {
                    InnerOperator(target->link[i + 1], target, new_node);
                }

                break;
            }
        }
    }
}

void Tree234__InsertNode(Tree234_Node_** target, RecordType_ new_node) {
    //노드가 없을때,
    if ((*target) == NULL) {
        (*target) = (Tree234_Node_*)calloc(sizeof(Tree234_Node_), 1);
        if ((*target) != NULL) {
            (*target)->data[0] = new_node;
            (*target)->num_node = 1;
            for (int i = 0; i < 4; i++) (*target)->link[i] = NULL;

            return;
        }
    }
    //노드가 있을 경우
    else {
        _KeyStatus status = InnerOperator(*target, NULL, new_node);

        if (status == InsertFail) {
            printf("InsertFail\n");
        } else if (status == SearchFail) {
            printf("SearchFail\n");
        } else {
            return;
        }
    }
}
void Tree234__DeleteNode(Tree234_Node_** root, int key);
RecordType_* Tree234__SearchKey(Tree234_Node_** root, int corresponding_key);
void Tree234__FreeAll(Tree234_Node_** root);

#endif