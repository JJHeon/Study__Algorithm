#include "Test_Control.h"
#if ___POLYNOMIAL_EXPRESSION_EXAMPLE

#include "Polynomial_Expression_UsingSinglyLinked_List_Example.h"
#include <stdio.h>
#include <stdlib.h>

PELSE_Element PELSE__CreateElement(int coef, int expon) {
    PELSE_Element obj = {coef, expon};
    return obj;
}

void PELSE__NodeAdminInit(PELSE_Node_Adminster* obj) {
    obj->length = 0;
    obj->head = NULL;
    obj->tail = NULL;
}
void PELSE__InsertFirst(PELSE_Node_Adminster* obj, PELSE_Node* new_node) {
    if (obj->length == 0 && obj->head == NULL) {
        obj->length++;
        obj->head = new_node;
        obj->tail = new_node;
    } else {
        obj->length++;
        new_node->link = obj->head;
        obj->head = new_node;
    }
}
void PELSE__InsertLast(PELSE_Node_Adminster* obj, PELSE_Node* new_node) {
    if (obj->length == 0 && obj->tail == NULL) {
        obj->length++;
        obj->head = new_node;
        obj->tail = new_node;
    } else {
        obj->length++;
        obj->tail->link = new_node;
        obj->tail = new_node;
    }
}
void PELSE__Print(PELSE_Node_Adminster obj) {
    PELSE_Node* temp = obj.head;
    if (temp == NULL) {
        printf("PELSEPrint/Error\n");
        return;
    }
    for (int i = 0; i < obj.length; i++) {
        if (temp == NULL)
            break;
        printf("(%d,%d) ", temp->data.coef, temp->data.expon);
        temp = temp->link;
    }
    printf("\n");
}
void PELSE__MemoryFree(PELSE_Node_Adminster* obj) {
    PELSE_Node* temp1 = obj->head;
    PELSE_Node* temp2;
    if (temp1 == NULL) {
        printf("PELSEMemoryFree/Error\n");
        return;
    }
    for (int i = 0; i < obj->length; i++) {
        if (temp1 == NULL)
            break;
        temp2 = temp1->link;
        free(temp1);
        temp1 = temp2;
    }
}

PELSE_Node* PELSE__CreateNode(PELSE_Element data) {
    PELSE_Node* new_node = (PELSE_Node*)malloc(sizeof(PELSE_Node));
    if (new_node == NULL) {
        printf("PELSE Create Node/Error\n");
        exit(1);
    }

    new_node->data = data;
    new_node->link = NULL;

    return new_node;
}

PELSE_Node_Adminster PELSE__Add(PELSE_Node_Adminster list1, PELSE_Node_Adminster list2) {
    PELSE_Node* temp1 = list1.head;
    PELSE_Node* temp2 = list2.head;

    PELSE_Node_Adminster result;
    PELSE__NodeAdminInit(&result);

    
    int sum = 0;
    while (temp1&&temp2) {
        if(temp1->data.expon > temp2->data.expon){
            PELSE__InsertLast(&result, PELSE__CreateNode(PELSE__CreateElement(temp1->data.coef, temp1->data.expon)));
            temp1 = temp1->link;
        }else if(temp1->data.expon == temp2->data.expon){
            sum = temp1->data.coef + temp2->data.coef;
            if(sum!=0)
                PELSE__InsertLast(&result, PELSE__CreateNode(PELSE__CreateElement(sum, temp1->data.expon)));
            temp1 = temp1->link;
            temp2 = temp2->link;
        }else{
            PELSE__InsertLast(&result, PELSE__CreateNode(PELSE__CreateElement(temp2->data.coef, temp2->data.expon)));
            temp2 = temp2->link;
        }
    }
    for (; temp1 != NULL; temp1=temp1->link){
        PELSE__InsertLast(&result, PELSE__CreateNode(PELSE__CreateElement(temp1->data.coef, temp1->data.expon)));
    }
    for (; temp2 != NULL; temp2=temp2->link){
        PELSE__InsertLast(&result, PELSE__CreateNode(PELSE__CreateElement(temp2->data.coef, temp2->data.expon)));
    }

    return result;
}
#endif