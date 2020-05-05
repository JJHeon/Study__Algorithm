#include "Test_Control.h"
//std
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
다음은 함수 사용의 예제 
*/

void LineMaker(void) {
    printf("\n");
    printf("=================================================================================\n");
}

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
#if ___ERATOSTENES
#include "Eratos.h"
    //Eratostenes
    LineMaker();
    printf("Eratostenes\n");
    {
        bool *eratostenes_ptr = Eratos(100);
        for (int i = 1; i <= 100; i++) {
            if (eratostenes_ptr[i])
                printf("%3d ", i);
            else
                printf("%3s ", "X");
            if (i % 20 == 0)
                printf("\n");
        }

        free(eratostenes_ptr);
    }
#endif
#if ___FACTORIAL
#include "Factorial.h"
    //Factorial
    LineMaker();
    printf("Factorial\n");
    {
        int factorial_int = 7;
        printf("Factorial_C : %d\n", Factorial_C(factorial_int));
        printf("Factorial_R : %d\n", Factorial_R(factorial_int));
    }
#endif
#if ___INVOLUTION_OR_POWER
#include "Power.h"
    //Involution or Power (거듭제곱 법)
    LineMaker();
    printf("Involution or Power\n");
    {
        double involution_double = 3.2;
        printf("Power_C_JH : %.3lf\n", Power_R(involution_double, 3));
        printf("Power_R_JH : %.3lf\n", Power_R(involution_double, 3));
    }
#endif
#if ___FIBONACCI_NUMBERS
#include "Fibonacci.h"
    //Fibonacci numbers
    LineMaker();
    printf("Fibonacci numbers\n");
    {
        int fivonacci_int = 6;
        printf("FibonacciNumbers_C_JH : %d\n", FibonacciNumbers_C(6));
        printf("FibonacciNumbers_R_JH : %d\n", FibonacciNumbers_R(6));
    }
#endif
#if ___HANOI_TOWER
#include "HanoiTower.h"
    //Hanoi Tower
    LineMaker();
    printf("Hanoi Tower\n");
    {
        HanoiTower_C(4, 'A', 'B', 'C');
    }
#endif
#if ___POLYNOMIAL_EXPRESSION1
#include "Polynomial_Expression.h"
    //Polynomial Expression 1
    LineMaker();
    printf("Polynomial Expression 1\n");
    {
        PEE1 polynomial_expr1_exmple1 = {5, {3, 6, 0, 0, 0, 10}};
        PEE1 polynomial_expr1_exmple2 = {5, {3, 6, 0, 0, 0, 10}};
        PEE1 polynomial_expr1_exmple3 = PEE1__Add(polynomial_expr1_exmple1, polynomial_expr1_exmple2);

        PEE1__Print(polynomial_expr1_exmple3);
    }
#endif
#if ___POLYNOMIAL_EXPRESSION2
#include "Polynomial_Expression.h"
    //Polynomial Expression 2
    LineMaker();
    printf("Polynomial Expression 2\n");
    {
        int Cs, Ce;
        int avail = 6;
        PEE2 terms[POLYNOMIAL_EXPR2_MAX_TERMS] = {{8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0}};
        PEE2__Add(terms, &avail, 0, 2, 3, 5, &Cs, &Ce);
        PEE2__Print(terms, &avail);
    }
#endif
#if ___SPARSE_MATRIX_EXPRESSION
#include "SparseMatrix.h"
    //Sparse Matrix Expression
    LineMaker();
    printf("Sparse Matrix Expression\n");
    {
        SME1 sparse_matrix_expr1_exmple1 = {{{1, 1, 5}, {2, 2, 9}}, 3, 3, 2};
        SME1 sparse_matrix_expr1_exmple2 = {{{0, 0, 5}, {2, 2, 9}}, 3, 3, 2};
        SME1 sparse_matrix_expr1_exmple3 = SME1__Add(&sparse_matrix_expr1_exmple1, &sparse_matrix_expr1_exmple2);

        SME1__Print(&sparse_matrix_expr1_exmple1);
        SME1__Print(&sparse_matrix_expr1_exmple2);
        SME1__Print(&sparse_matrix_expr1_exmple3);
    }
#endif
#if ___LIST_MADE_BY_ARRAY
#include "List_Array.h"

    //List made by Array
    LineMaker();
    printf("List made by Array\n");
    {
        LA_ list_array_exmple1;
        LA__Initialize(&list_array_exmple1);
        LA__Add(&list_array_exmple1, 0, 10);
        LA__Add(&list_array_exmple1, 0, 20);
        LA__Add(&list_array_exmple1, 0, 30);
        LA__Display(&list_array_exmple1);
    }
#endif
#if ___SINGLY_LINKED_LIST
#include "Singly_Linked_List.h"
    //Singly Linked List
    LineMaker();
    printf("Singly Linked List\n");
    {
        LS_Node *singly_linked_list_exmple1 = NULL;
        LS_Node *singly_linked_list_exmple2 = NULL;
        printf("	Add Section\n");
        LS__Insert(&singly_linked_list_exmple1, NULL, LS__CreateNode(10, NULL));
        LS__Insert(&singly_linked_list_exmple1, NULL, LS__CreateNode(20, NULL));
        LS__Insert(&singly_linked_list_exmple1, NULL, LS__CreateNode(30, NULL));
        LS__Insert(&singly_linked_list_exmple1, NULL, LS__CreateNode(40, NULL));
        LS__Insert(&singly_linked_list_exmple1, NULL, LS__CreateNode(50, NULL));
        LS__Display(singly_linked_list_exmple1);
        printf("	Remove Section\n");  //삭제하려는 노드의 이전 노드를 알아야 한다는 것 자체가 말이 안됨. 정상적으론 얻을 방법이 없음
        LS__Remove(&singly_linked_list_exmple1, singly_linked_list_exmple1->link, LS__Search(singly_linked_list_exmple1, 30));
        LS__Display(singly_linked_list_exmple1);
        printf("	Add2 Section\n");
        LS__Insert(&singly_linked_list_exmple2, NULL, LS__CreateNode(80, NULL));
        LS__Insert(&singly_linked_list_exmple2, NULL, LS__CreateNode(90, NULL));
        LS__Display(singly_linked_list_exmple2);
        printf("	Concat Section\n");
        LS_Node *singly_linked_list_exmple3 = LS__Concat(singly_linked_list_exmple1, singly_linked_list_exmple2);
        LS__Display(singly_linked_list_exmple3);
        printf("	Reverse Section\n");
        singly_linked_list_exmple3 = LS__Reverse(singly_linked_list_exmple3);
        LS__Display(singly_linked_list_exmple3);
        LS__MemoryFree(singly_linked_list_exmple3);
    }
#endif
#if ___CIRCULAR_LINKED_LIST
#include "Circular_Linked_List.h"
    //Circular Linked List
    LineMaker();
    printf("Circular Linked List\n");
    {
        LC_Node *circular_linked_list_exmple = NULL;  //반드시 초기화가 되어야 한다.
        LC__Insert(&circular_linked_list_exmple, NULL, LC__CreateNode(50));
        LC__Insert(&circular_linked_list_exmple, NULL, LC__CreateNode(60));
        LC__Insert(&circular_linked_list_exmple, NULL, LC__CreateNode(70));
        LC__Insert(&circular_linked_list_exmple, LC__Search_JH(circular_linked_list_exmple, 60), LC__CreateNode(20));
        LC__Display(circular_linked_list_exmple);
        LC__MemoryFree(circular_linked_list_exmple);
    }
#endif
#if ___DOUBLY_LINKED_LIST
#include "Doubly_Linked_List.h"
    //Doubly Linked List
    LineMaker();
    printf("Doubly Linked List\n");
    {
        LD_Node *doubly_linked_list_exmple = NULL;  //반드시 NULL로 초기화 필요
        LD__Insert(&doubly_linked_list_exmple, NULL, LD__CreateNode(100));
        LD__Insert(&doubly_linked_list_exmple, NULL, LD__CreateNode(110));
        LD__Insert(&doubly_linked_list_exmple, NULL, LD__CreateNode(120));
        LD__Display(doubly_linked_list_exmple);

        LD__Insert(&doubly_linked_list_exmple, LD__Search(doubly_linked_list_exmple, 110), LD__CreateNode(400));
        LD__Display(doubly_linked_list_exmple);
        LD__MemoryFree(doubly_linked_list_exmple);
    }
#endif
#if ___POLYNOMIAL_EXPRESSION_EXAMPLE
#include "Polynomial_Expression_UsingSinglyLinked_List_Example.h"
    //Polynomial_Expression_UsingSinglyLinked_List_Example
    LineMaker();
    printf("Polynomial_Expression_UsingSinglyLinked_List_Example\n");
    {
        printf("	InsertFrist Section\n");
        PELSE_Node_Adminster pelse_exmple1;
        PELSE__NodeAdminInit(&pelse_exmple1);
        PELSE__InsertFirst(&pelse_exmple1, PELSE__CreateNode(PELSE__CreateElement(10, 0)));
        PELSE__InsertFirst(&pelse_exmple1, PELSE__CreateNode(PELSE__CreateElement(9, 3)));
        PELSE__InsertFirst(&pelse_exmple1, PELSE__CreateNode(PELSE__CreateElement(12, 5)));
        PELSE__Print(pelse_exmple1);

        printf("	InsertLast Section\n");
        PELSE_Node_Adminster pelse_exmple2;
        PELSE__NodeAdminInit(&pelse_exmple2);
        PELSE__InsertLast(&pelse_exmple2, PELSE__CreateNode(PELSE__CreateElement(4, 5)));
        PELSE__InsertLast(&pelse_exmple2, PELSE__CreateNode(PELSE__CreateElement(9, 1)));
        PELSE__InsertLast(&pelse_exmple2, PELSE__CreateNode(PELSE__CreateElement(12, 0)));
        PELSE__Print(pelse_exmple2);

        printf("	Add Section\n");
        PELSE_Node_Adminster pelse_exmple3 = PELSE__Add(pelse_exmple1, pelse_exmple2);
        PELSE__Print(pelse_exmple3);

        PELSE__MemoryFree(&pelse_exmple1);
        PELSE__MemoryFree(&pelse_exmple2);
        PELSE__MemoryFree(&pelse_exmple3);
    }
#endif
#if ___STACK_USING_ARRAY
#include "Stack.h"
    //Stack Using Array
    LineMaker();
    printf("Stack Using Array\n");
    {
        UAStack_ uastack_exmple1;
        UAStack__Initialization(&uastack_exmple1);

        UAStack_Element uastack_sample;
        UAStack__Push(&uastack_exmple1, UAStack__CreateElement(10));
        UAStack__Push(&uastack_exmple1, UAStack__CreateElement(20));
        UAStack__Push(&uastack_exmple1, UAStack__CreateElement(30));
        UAStack__Push(&uastack_exmple1, UAStack__CreateElement(40));

        for (int i = 0; i < 3; i++) {
            uastack_sample = UAStack__Pop(&uastack_exmple1);
            printf("%d ", uastack_sample.data);
        }
        uastack_sample = UAStack__Peek(&uastack_exmple1);
        printf("\nPeek : %d\n", uastack_sample.data);
        printf("Pop Again :");
        uastack_sample = UAStack__Pop(&uastack_exmple1);
        printf("%d\n", uastack_sample.data);
        printf("IsEmpty : %d\n", UAStack__IsEmpty(&uastack_exmple1));
    }
#endif
#if ___STACK_USING_LIST
#include "Stack.h"
    //Stack Using List
    LineMaker();
    printf("Stack Using List\n");
    {
        ULStack_ *ulstack_exmple1 = NULL;  //반드시 초기화!
        ULStack_Element ulstack_sample;

        ULStack__Push(&ulstack_exmple1, ULStack__CreateElement(110));
        ULStack__Push(&ulstack_exmple1, ULStack__CreateElement(120));
        ULStack__Push(&ulstack_exmple1, ULStack__CreateElement(130));
        ULStack__Push(&ulstack_exmple1, ULStack__CreateElement(140));
        for (int i = 0; i < 3; i++) {
            ulstack_sample = ULStack__Pop(&ulstack_exmple1);
            printf("%d ", ulstack_sample.data);
        }

        ulstack_sample = ULStack__Peek(ulstack_exmple1);
        printf("\nPeek : %d\n", ulstack_sample.data);
        printf("Pop Again :");
        ulstack_sample = ULStack__Pop(&ulstack_exmple1);
        printf("%d\n", ulstack_sample.data);
        printf("IsEmpty : %d\n", ULStack__IsEmpty(ulstack_exmple1));
        ULStack__MemoryFree(ulstack_exmple1);
    }
#endif
#if ___STACK_EXAMPLE
#include "Stack_Example.h"
    //Stack Example 1
    LineMaker();
    printf("Stack Example 1\n");
    {
        printf("Is {A[(i+1)] = 0;} correct?\n");
        if (EXStack__MatchingCheck("{A[(i+1)] = 0;}"))
            printf("Sentence Correct\n");
        else
            printf("Sentence has problem\n");
        printf("Is {B[(j] = 0;} correct?\n");
        if (EXStack__MatchingCheck("{B[(j] = 0;}"))
            printf("Sentence Correct\n");
        else
            printf("Sentence has problem\n");
    }

    //Stack Example 2
    LineMaker();
    printf("Stack Example 2\n");
    {
        char *stack_exmple2 = EXStack__EncodingPostfixNotation("(3+2*4)/5");
        printf("EXStackEncodingPostfixNotation : %s\n", stack_exmple2);

        //Stack Example 3
        LineMaker();
        printf("Stack Example 3\n");
        char *stack_exmple3 = EXStack__ClassifyNumber("(35+27*4)/5");
        printf("EXStackClassifyNumber : %s\n", stack_exmple3);
        char *stack_exmple4 = EXStack__EncodingPostfixNotation(stack_exmple3);
        printf("EXStackEncodingPostfixNotation 2 : %s\n", stack_exmple4);

        //Stack Example 4
        LineMaker();
        printf("Stack Example 4\n");
        char *stack_exmple1 = EXStack__ClassifyNumber("[350]/[50]*[2]-[1]");
        printf("EXStackCaclulatePostfixNotation 1 : %d\n", EX2Stack__CaclulatePostfixNotation("2+3*4"));
        printf("EXStackCaclulatePostfixNotation 2 : %d\n", EX2Stack__CaclulatePostfixNotation(stack_exmple1));
        free(stack_exmple1);
        free(stack_exmple2);
        free(stack_exmple3);
        free(stack_exmple4);
    }
    LineMaker();
    printf("Stack Example 5\n");
    {
        char stack_example5_map[EX3_MAX_VERTICAL_SIZE][EX3_MAX_HORIZONTAL_SIZE] = {
            {'1', '1', '1', '1', '1', '1'},
            {'S', '0', '1', '0', '0', '1'},
            {'1', '0', '0', '0', '1', '1'},
            {'1', '0', '1', '0', '1', '1'},
            {'1', '0', '1', '0', '0', 'E'},
            {'1', '1', '1', '1', '1', '1'}};

        char stack_example6_map[EX3_MAX_VERTICAL_SIZE][EX3_MAX_HORIZONTAL_SIZE] = {
            {'1', '1', '1', '1', '1', '1'},
            {'S', '0', '0', '0', '0', '1'},
            {'1', '0', '1', '0', '1', '1'},
            {'1', '1', '1', '0', '0', 'E'},
            {'1', '1', '1', '0', '1', '1'},
            {'1', '1', '1', '1', '1', '1'}};

        char stack_example7_map[EX3_MAX_VERTICAL_SIZE][EX3_MAX_HORIZONTAL_SIZE] = {
            {'1', '1', 'S', '1', '1', '1'},
            {'1', '0', '0', '0', '0', '1'},
            {'1', '0', '1', '1', '0', '1'},
            {'1', '0', '0', '1', '0', '1'},
            {'1', '0', '0', '1', '0', '1'},
            {'1', '1', 'E', '1', '1', '1'}};
        EX3Stack_ *stack_example5_pass = NULL;
        EX3Stack_ *stack_example6_pass = NULL;
        EX3Stack_ *stack_example7_pass = NULL;
        printf("Fisrt Map\n");
        if (EX3Stack__FindProcessOfPass(stack_example5_map, false, &stack_example5_pass))
            printf("Success!\n");
        else
            printf("Fail\n");

        printf("Second Map\n");
        if (EX3Stack__FindProcessOfPass(stack_example6_map, false, &stack_example6_pass))
            printf("Success!\n");
        else
            printf("Fail\n");

        printf("Third Map\n");
        if (EX3Stack__FindProcessOfPass(stack_example7_map, false, &stack_example7_pass))
            printf("Success!\n");
        else
            printf("Fail\n");

        EX3Stack__MemoryFree(stack_example5_pass);
        EX3Stack__MemoryFree(stack_example6_pass);
        EX3Stack__MemoryFree(stack_example7_pass);
    }

    //Stack Example 6 //책 예제 그대로 실음
    LineMaker();
    printf("Stack Example 6\n");
    {
        char stack_example8_maze[EX3ASTACK_MAZE_MAX_SIZE][EX3ASTACK_MAZE_MAX_SIZE] = {
            {'1', '1', '1', '1', '1', '1'},
            {'e', '0', '1', '0', '0', '1'},
            {'1', '0', '0', '0', '1', '1'},
            {'1', '0', '1', '0', '0', 'x'},
            {'1', '1', '1', '1', '1', '1'}};
        int stack_example8_r;
        int stack_example8_c;
        EX3AStack_Type stack_example8_s;
        EX3AStack_Element stack_example8_here = {1, 0};
        EX3AStack_Element stack_example8_entry = {1, 0};

        EX3AStack__init(&stack_example8_s);
        stack_example8_here = stack_example8_entry;
        while (stack_example8_maze[stack_example8_here.r][stack_example8_here.c] != 'x') {
            stack_example8_r = stack_example8_here.r;
            stack_example8_c = stack_example8_here.c;
            stack_example8_maze[stack_example8_r][stack_example8_c] = '.';
            EX3AStack__push_Loc(&stack_example8_s, stack_example8_r - 1, stack_example8_c, stack_example8_maze);
            EX3AStack__push_Loc(&stack_example8_s, stack_example8_r + 1, stack_example8_c, stack_example8_maze);
            EX3AStack__push_Loc(&stack_example8_s, stack_example8_r, stack_example8_c - 1, stack_example8_maze);
            EX3AStack__push_Loc(&stack_example8_s, stack_example8_r, stack_example8_c + 1, stack_example8_maze);
            if (EX3AStack__is_empty(&stack_example8_s)) {
                printf("fail\n");
                break;
            } else {
                stack_example8_here = EX3AStack__pop(&stack_example8_s);
            }
        }
        printf("success\n");
    }
#endif
#if ___KOREAN_CHARACTER_ADJUSTMENT
#include "Korean_Character_Adjustment_InUTF8.h"
    //Korean character adjustment (한글 문자배열 조정) in UTF-8
    LineMaker();
    printf("Korean character adjustment\n");
    {
        printf("%-18s", "아이스크림");
        KoreanAdjInUTF8Print(KoreanAdjInUTF8Count("아이스크림"));
        printf("%6d", 1600);

        printf("    ");
        printf("%-18s", "쌍쌍바");
        KoreanAdjInUTF8Print(KoreanAdjInUTF8Count("쌍쌍바"));
        printf("%6d", 1200);

        printf("\n");
        printf("%-18s", "빙수");
        KoreanAdjInUTF8Print(KoreanAdjInUTF8Count("빙수"));
        printf("%6d", 3000);

        printf("    ");
        printf("%-18s", "엄마는외계인");
        KoreanAdjInUTF8Print(KoreanAdjInUTF8Count("엄마는외계인"));
        printf("%6d", 6000);
    }
#endif
#if ___QUEUE_USING_ARRAY
#include "Queue.h"
    //Queue Using Array
    LineMaker();
    printf("Queue Using Array\n");
    {
        UAQueue_ queue_example1;
        UAQueue__Initialize(&queue_example1);

        UAQueue__Enqueue(&queue_example1, UAQueue__CreateElement(10));
        UAQueue__Enqueue(&queue_example1, UAQueue__CreateElement(20));
        UAQueue__Enqueue(&queue_example1, UAQueue__CreateElement(30));
        UAQueue__Enqueue(&queue_example1, UAQueue__CreateElement(40));
        for (int i = 0; i < 4; i++) {
            printf("%d 번째 DeQueue = %d\n", i + 1, UAQueue__Dequeue(&queue_example1).data);
        }
        //printf("Peek : %d\n", UAQueue__Peek(&queue_example1).data);
    }
#endif
#if ___QUEUE_USING_LIST
#include "Queue.h"
    //Queue Using List
    LineMaker();
    printf("Queue Using List\n");
    {
        ULQueue_ queue_example2;
        ULQueue__Initialize(&queue_example2);
        ULQueue__Enqueue(&queue_example2, ULQueue__CreateNode(50));
        ULQueue__Enqueue(&queue_example2, ULQueue__CreateNode(60));
        ULQueue__Enqueue(&queue_example2, ULQueue__CreateNode(70));
        ULQueue__Enqueue(&queue_example2, ULQueue__CreateNode(80));

        for (int i = 0; i < 3; i++) {
            printf("%d 번째 Dequeue = %d\n", i + 1, ULQueue__Dequeue(&queue_example2).data1);
        }
        printf("Peek : %d\n", ULQueue__Peek(&queue_example2).data1);
        ULQueue__Destructor(&queue_example2);
    }
#endif
#if ___DEQUEUE_USING_DOUBLY_LINKED_LIST
#include "Deque.h"
    //Dequeue Using Doubly_Linked_List
    LineMaker();
    printf("Dequeue Using Doubly_Linked_List\n");
    {
        Deque_ deque_example1;
        Deque__Initialize(&deque_example1);

        Deque__AddFront(&deque_example1, Deque__CreateNode(10));
        Deque__AddFront(&deque_example1, Deque__CreateNode(20));
        Deque__AddRear(&deque_example1, Deque__CreateNode(50));
        Deque__AddRear(&deque_example1, Deque__CreateNode(60));

        printf("Deque DeleteFront : %d\n", Deque__DeleteFront(&deque_example1).data1);
        printf("Deque DeleteRear : %d\n", Deque__DeleteRear(&deque_example1).data1);

        printf("Deque GetFront : %d\n", Deque__GetFront(&deque_example1).data1);
        printf("Deque GetRear : %d\n", Deque__GetRear(&deque_example1).data1);

        Deque__Destructor(&deque_example1);
        printf("Deque__IsEmpty : %d\n", Deque__IsEmpty(&deque_example1));
    }
#endif
#if ___BINARY_TREE
#include "Binary_Tree.h"
    //Binary_Tree
    /*
            15
        4          20
    1          16       25
                 42   92    62
    */
    LineMaker();
    printf("Binary_Tree\n");
    {
        Binary_Tree_Node_ btn_sample1_n1 = {42, NULL, NULL};
        Binary_Tree_Node_ btn_sample1_n2 = {92, NULL, NULL};
        Binary_Tree_Node_ btn_sample1_n3 = {62, NULL, NULL};
        Binary_Tree_Node_ btn_sample1_n4 = {1, NULL, NULL};
        Binary_Tree_Node_ btn_sample1_n5 = {16, NULL, &btn_sample1_n1};
        Binary_Tree_Node_ btn_sample1_n6 = {25, &btn_sample1_n2, &btn_sample1_n3};
        Binary_Tree_Node_ btn_sample1_n7 = {4, &btn_sample1_n4, NULL};
        Binary_Tree_Node_ btn_sample1_n8 = {20, &btn_sample1_n5, &btn_sample1_n6};
        Binary_Tree_Node_ btn_sample1_n9 = {15, &btn_sample1_n7, &btn_sample1_n8};
        Binary_Tree_Node_ *root = &btn_sample1_n9;

        printf("\npreorder 전위순회 :\n");
        BTN__Preorder(root);
        printf("\ninorder 중위순회 :\n");
        BTN__Inorder(root);
        printf("\npostorder 후위순회 :\n");
        BTN__Postorder(root);
        printf("\nlevelorder 레벨순회 :\n");
        BTN__Levelorder(root);
        printf("\n");
        printf("노드 개수 구하기 : %d\n", BTN__GetNodeCount(root));
        printf("단말(leaf) 노드 개수 구하기 : %d\n", BTN__GetLeafNodeCount(root));
        printf("노드 Height : %d\n", BTN__GetHeight(root));
    }
#endif
#if ___THREAD_BINARY_TREE
#include "Thread_Binary_Tree.h" |
    //Thread_Binary_Tree
    /*
            15
        4          20
    1          16       25
                 42   92    62
    */
    LineMaker();
    printf("Thread_Binary_Tree\n");
    {
        Thread_Binary_Tree_Node_ tbt_sample1_n1 = {42, true, NULL, NULL};
        Thread_Binary_Tree_Node_ tbt_sample1_n2 = {92, true, NULL, NULL};
        Thread_Binary_Tree_Node_ tbt_sample1_n3 = {62, false, NULL, NULL};
        Thread_Binary_Tree_Node_ tbt_sample1_n4 = {1, true, NULL, NULL};
        Thread_Binary_Tree_Node_ tbt_sample1_n5 = {16, false, NULL, &tbt_sample1_n1};
        Thread_Binary_Tree_Node_ tbt_sample1_n6 = {25, false, &tbt_sample1_n2, &tbt_sample1_n3};
        Thread_Binary_Tree_Node_ tbt_sample1_n7 = {4, true, &tbt_sample1_n4, NULL};
        Thread_Binary_Tree_Node_ tbt_sample1_n8 = {20, false, &tbt_sample1_n5, &tbt_sample1_n6};
        Thread_Binary_Tree_Node_ tbt_sample1_n9 = {15, false, &tbt_sample1_n7, &tbt_sample1_n8};

        tbt_sample1_n1.right = &tbt_sample1_n8;
        tbt_sample1_n2.right = &tbt_sample1_n6;
        tbt_sample1_n4.right = &tbt_sample1_n7;
        tbt_sample1_n7.right = &tbt_sample1_n9;

        Thread_Binary_Tree_Node_ *root = &tbt_sample1_n9;

        printf("\ninorderThread 중위순회 :\n");
        TBT__InorderThread(root);
        printf("\n");
    }
#endif
#if ___BINARY_SEARCH_TREE
#include "Binary_Search_Tree.h"
    //Binary_Search_Tree
    /*
            30
        25          39
    12     28     32       54
         26     31  35
    */
    LineMaker();
    printf("Binary_Search_Tree\n");
    {
        Binary_Search_Tree_Node_ *bst_sample1 = NULL;
        BST__InsertNode(&bst_sample1, BST__CreateNode(30, 1020));
        BST__InsertNode(&bst_sample1, BST__CreateNode(25, 195));
        BST__InsertNode(&bst_sample1, BST__CreateNode(39, 1021));
        BST__InsertNode(&bst_sample1, BST__CreateNode(12, 1320));
        BST__InsertNode(&bst_sample1, BST__CreateNode(28, 3020));
        BST__InsertNode(&bst_sample1, BST__CreateNode(32, 5020));
        BST__InsertNode(&bst_sample1, BST__CreateNode(54, 7020));
        BST__InsertNode(&bst_sample1, BST__CreateNode(26, 1520));
        BST__InsertNode(&bst_sample1, BST__CreateNode(31, 1440));
        BST__InsertNode(&bst_sample1, BST__CreateNode(35, 3333));

        printf("중위순회 : ");
        BST__Inorder(bst_sample1);
        printf("\n");

        printf("BST__Search_C 순환 탐색 : %d : 기대값 :1520\n", BST__Search_C(bst_sample1, 26)->data);
        printf("BST__Search_R 순환 탐색 : %d : 기대값 :5020\n", BST__Search_R(bst_sample1, 32)->data);

        BST__DeleteNode(&bst_sample1, 28);
        printf("DeleteNode 28 : ");
        BST__Inorder(bst_sample1);
        printf("\n");

        BST__DeleteNode(&bst_sample1, 39);
        printf("DeleteNode 39 : ");
        BST__Inorder(bst_sample1);
        printf("\n");

        BST__DeleteNode(&bst_sample1, 30);
        printf("DeleteNode 30 : ");
        BST__Inorder(bst_sample1);
        printf("\n");

        BST__FreeMemoryUsingPostorder(bst_sample1);
    }
#endif
#if ___HEAP
#include "Heap.h"
    //Heap
    /*
            9
        7          6
    5      4     2       1
  2   1  3         
    */
    LineMaker();
    printf("Heap\n");
    Heap_ sample1;
    InitHeap(&sample1);
    InsertMaxHeap(&sample1, CreateNode(9));
    InsertMaxHeap(&sample1, CreateNode(7));
    InsertMaxHeap(&sample1, CreateNode(6));
    InsertMaxHeap(&sample1, CreateNode(5));
    InsertMaxHeap(&sample1, CreateNode(4));
    InsertMaxHeap(&sample1, CreateNode(2));
    InsertMaxHeap(&sample1, CreateNode(1));
    InsertMaxHeap(&sample1, CreateNode(2));
    InsertMaxHeap(&sample1, CreateNode(1));
    InsertMaxHeap(&sample1, CreateNode(3));

    PrintHeap(&sample1);
    printf("\nDelete Test\n");
    printf("1 : %d\n", DeleteMaxHeap(&sample1).key);
    PrintHeap(&sample1);
    printf("2 : %d\n", DeleteMaxHeap(&sample1).key);
    PrintHeap(&sample1);
    printf("3 : %d\n", DeleteMaxHeap(&sample1).key);
    PrintHeap(&sample1);

    printf("Sorting Test\n");
    Node_ A[50];
    for (int i = 0; i < 50; i++) {
        A[i].key = (rand() % 100) + 1;
    }
    SortHeap(A, sizeof(A) / sizeof(Node_));
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0)
            printf("\n");
        printf("%2d ", A[i].key);
    }

#endif
#if ___HEAP_EXAMPLE
#include "Heap_Example.h"
    LineMaker();
    printf("Heap_Example\n");
    Node_ event;
    Heap_ heap;
    unsigned int t = 0;

    InitHeap(&heap);
    //처음에 몇개의 초기 이벤트를 생성시킨다.
    while (t < 5) {
        t += random(6);
        event.type = ARRIVAL;
        event.key = t;
        event.number = 1 + random(4);
        InsertMinHeap(&heap, event);
    }
    //시뮬레이션을 수행한다.
    while (!IsEmptyHeap(&heap)) {
        event = DeleteMinHeap(&heap);
        process_event(&heap, event);
    }
    printf("전체 순이익은 =%f입니다.\n", profit);
#endif

    return 0;
}
