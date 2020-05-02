#ifndef __STACK_EMAMPLE_H_
#define __STACK_EMAMPLE_H_
/*
Stack_Using_List => UL
ULStack_Example => EXStack

1. 괄호검사
2. 중위표기->후위표기변환
3. 후위표기 계산
4. 미로탐색

EX1 : 괄호검사, 중위->후위표기 변환을 위한 char 데이터 stack
EX2 : 후위표기 계산을 위한 int 데이터 stack
EX3 : 미로탐색을 위한 Stack
EX3A : 미로탐색 제일 간소화버전

*/
#include <stdbool.h>

//EX1
//DATA CHAR
typedef struct EXStack_Element {
    char data;
} EXStack_Element;
typedef struct EXStack_ {
    EXStack_Element data;
    struct EXStack_* next;
} EXStack_;

bool EXStack__IsEmpty(EXStack_* obj);

void EXStack__Push(EXStack_** obj, EXStack_Element item);

EXStack_Element EXStack__CreateElement(char data);
EXStack_Element EXStack__Pop(EXStack_** obj);
EXStack_Element EXStack__Peek(EXStack_* obj);

void EXStack__MemoryFree(EXStack_* obj);
/*
스택을 이용한 괄호검사.
여기선 LIST이용한 스택활용.
*/
bool EXStack__MatchingCheck(char* string);
/*
숫자 크기 select 
동적주소반환
*/
char* EXStack__ClassifyNumber(char* string);
/*
중위표기 -> 후위표기 변환
동적주소반환.
여기에 후위변환된 식을 또 넣지말 것, 검사장치가 없기때문에 값에 오류가 생긴다.
*/
char* EXStack__EncodingPostfixNotation(char* string);
int EXStack__OperatorProirity(char obj);

//EX2
//DATA Int
typedef struct EX2Stack_Element {
    int data;
} EX2Stack_Element;
typedef struct EX2Stack_ {
    EX2Stack_Element data;
    struct EX2Stack_* next;
} EX2Stack_;
bool EX2Stack__IsEmpty(EX2Stack_* obj);

void EX2Stack__Push(EX2Stack_** obj, EX2Stack_Element item);
void EX2Stack__MemoryFree(EX2Stack_* obj);

EX2Stack_Element EX2Stack__CreateElement(int data);
EX2Stack_Element EX2Stack__Pop(EX2Stack_** obj);
EX2Stack_Element EX2Stack__Peek(EX2Stack_* obj);
/*
후위표기 계산
*/
int EX2Stack__CaclulatePostfixNotation(char* string);

//EX3
#define EX3_MAX_VERTICAL_SIZE 6
#define EX3_MAX_HORIZONTAL_SIZE 6
typedef struct EX3Stack_Element {
    int row;
    int col;
} EX3Stack_Element;
typedef struct EX3Stack_ {
    EX3Stack_Element data;
    struct EX3Stack_* next;
} EX3Stack_;

bool EX3Stack__IsEmpty(EX3Stack_* obj);

void EX3Stack__Push(EX3Stack_** obj, EX3Stack_Element item);
void EX3Stack__MemoryFree(EX3Stack_* obj);

EX3Stack_Element EX3Stack__CreateElement(int row, int col);
EX3Stack_Element EX3Stack__Pop(EX3Stack_** obj);
EX3Stack_Element EX3Stack__Peek(EX3Stack_* obj);



EX3Stack_* EX3Stack__FindStartPoint(char (*map)[EX3_MAX_HORIZONTAL_SIZE]);
bool EX3Stack__FindProcessOfPass(char (*map)[EX3_MAX_HORIZONTAL_SIZE], bool want_view, EX3Stack_** stack_correct_pass);
bool EX3Stack__ComparisonFactorCalulation(char (*map)[EX3_MAX_HORIZONTAL_SIZE], EX3Stack_* stack_pass, int row_t, int col_t);
void EX3Stack__View(char (*map)[EX3_MAX_HORIZONTAL_SIZE], EX3Stack_Element current_point);
bool EX3Stack__CheckValidityForPosition(EX3Stack_Element obj1, EX3Stack_Element obj2);

//EX3_A => EX3A
#define EX3ASTACK_MAX_SIZE 100

#define EX3ASTACK_MAZE_MAX_SIZE 6
typedef struct {
    int r;
    int c;
} EX3AStack_Element;
typedef struct {
    EX3AStack_Element stack[EX3ASTACK_MAX_SIZE];
    int top;
} EX3AStack_Type;

void EX3AStack__init(EX3AStack_Type* s);
int EX3AStack__is_empty(EX3AStack_Type* s);
int EX3AStack__is_full(EX3AStack_Type* s);
void EX3AStack__push(EX3AStack_Type* s, EX3AStack_Element item);

EX3AStack_Element EX3AStack__pop(EX3AStack_Type* s);
EX3AStack_Element EX3AStack__peek(EX3AStack_Type* s);

void EX3AStack__push_Loc(EX3AStack_Type* s, int r, int c, char (*maze)[EX3ASTACK_MAZE_MAX_SIZE]);

#endif