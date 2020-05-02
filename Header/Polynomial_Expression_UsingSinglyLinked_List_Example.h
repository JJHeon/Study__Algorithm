#ifndef __POLYNOMIAL_EXPRESSION_USINGSIGNLYLINKED_LIST_EXAMPLE_H_
#define __POLYNOMIAL_EXPRESSION_USINGSIGNLYLINKED_LIST_EXAMPLE_H_
/*
싱글 리스트의 구조를 가지는 다항식 표현
Polynomial_Expression_UsingSinglyLinked_List_Example
=> PELSE
*/
typedef struct PELSE_Element {
    int coef;
    int expon;
} PELSE_Element;
typedef struct PELSE_Node {
    PELSE_Element data;
    struct PELSE_Node* link;
} PELSE_Node;

typedef struct PELSE_Node_Adminster {
    int length;
    PELSE_Node* head;
    PELSE_Node* tail;
} PELSE_Node_Adminster;

PELSE_Element PELSE__CreateElement(int coef, int expon);

void PELSE__NodeAdminInit(PELSE_Node_Adminster* obj);
void PELSE__InsertFirst(PELSE_Node_Adminster* obj, PELSE_Node* new_node);
void PELSE__InsertLast(PELSE_Node_Adminster* obj, PELSE_Node* new_node);

void PELSE__Print(PELSE_Node_Adminster obj);
void PELSE__MemoryFree(PELSE_Node_Adminster* obj);

PELSE_Node* PELSE__CreateNode(PELSE_Element data);

PELSE_Node_Adminster PELSE__Add(PELSE_Node_Adminster list1, PELSE_Node_Adminster list2);

#endif
