#include "Test_Control.h"

#if ___RADIX_SORT
#include "Radix_Sort.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

static int ReturnDigit(int key, int key_digit);

/* ==================================================================================================== */
/*
Internal Queue
*/
typedef struct ULQueue_Node_ {
    RecordType_ data;
    struct ULQueue_Node_* link;
} ULQueue_Node_;

typedef struct ULQueue_ {
    ULQueue_Node_* front;
    ULQueue_Node_* rear;
} ULQueue_;

static bool ULQueue__IsEmpty(ULQueue_* obj);

static void ULQueue__Initialize(ULQueue_* obj);
static void ULQueue__Enqueue(ULQueue_* obj, RecordType_* new_node);
static void ULQueue__Destructor(ULQueue_* obj);

static RecordType_ ULQueue__Dequeue(ULQueue_* obj);
static RecordType_ ULQueue__Peek(ULQueue_* obj);

/* ==================================================================================================== */

void SortRadixInAscendingOrder(RecordType_* obj, int obj_size, int key_max_digit) {
    ULQueue_ queue[10];
    int k = 0;
    memset(&queue, 0, sizeof(ULQueue_) * 10);

    for (int i = 1; i <= key_max_digit; i++) {  //Digit
        for (int j = 0; j < obj_size; j++) {    //배열 돌기
            ULQueue__Enqueue(&queue[ReturnDigit(obj[j].key, i)], &obj[j]);
        }

        k = 0;
        for (int i = 0; i <= 9; i++) {
            while (!ULQueue__IsEmpty(&queue[i])) {
                obj[k++] = ULQueue__Dequeue(&queue[i]);
            }
        }
    }
}

/* ==================================================================================================== */

static int ReturnDigit(int key, int key_digit) {
    if (key_digit == 1) {
        return key % 10;
    } else {
        return (key % ((int)pow((double)10, (double)(key_digit)))) / ((int)pow((double)10, (double)(key_digit - 1)));
    }
}

/* ==================================================================================================== */
static bool ULQueue__IsEmpty(ULQueue_* obj) {
    return (obj->front == NULL);
}
static void ULQueue__Initialize(ULQueue_* obj) {
    obj->front = NULL;
    obj->rear = NULL;
}
static void ULQueue__Enqueue(ULQueue_* obj, RecordType_* new_node) {
    if (new_node != NULL) {
        if (obj->front == NULL && obj->rear == NULL) {
            obj->front = (ULQueue_Node_*)malloc(sizeof(ULQueue_Node_));
            obj->rear = obj->front;

            obj->front->data = (*new_node);
            obj->front->link = NULL;
        } else {
            obj->rear->link = (ULQueue_Node_*)malloc(sizeof(ULQueue_Node_));
            obj->rear = obj->rear->link;

            obj->rear->data = (*new_node);
            obj->rear->link = NULL;
        }
    }
}
static void ULQueue__Destructor(ULQueue_* obj) {
    ULQueue_Node_* temp;

    while (obj->front != NULL) {
        temp = obj->front->link;
        free(obj->front);
        obj->front = temp;
    }

    obj->front = NULL;
    obj->rear = NULL;
}

static RecordType_ ULQueue__Dequeue(ULQueue_* obj) {
    if (!ULQueue__IsEmpty(obj)) {
        RecordType_ temp;
        ULQueue_Node_* temp2;
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
}
static RecordType_ ULQueue__Peek(ULQueue_* obj) {
    if (!ULQueue__IsEmpty(obj)) {
        return obj->front->data;
    }
}

#endif