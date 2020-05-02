#include "Stack_Example.h"
#include "ToInteger.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//EX1
bool EXStack__IsEmpty(EXStack_* obj) {
    if (obj == NULL)
        return true;
    return false;
}

void EXStack__Push(EXStack_** obj, EXStack_Element item) {
    if ((*obj) == NULL) {
        (*obj) = (EXStack_*)malloc(sizeof(EXStack_));
        (*obj)->data = item;
        (*obj)->next = NULL;
    } else {
        EXStack_* temp = (EXStack_*)malloc(sizeof(EXStack_));
        temp->data = item;
        temp->next = (*obj);
        (*obj) = temp;
    }
}

EXStack_Element EXStack__CreateElement(char data) {
    EXStack_Element temp = {data};
    return temp;
}
EXStack_Element EXStack__Pop(EXStack_** obj) {
    if (EXStack__IsEmpty((*obj))) {
        printf("ULStackPop Error\n");
        exit(1);
    }
    EXStack_Element temp1 = (*obj)->data;
    EXStack_* temp2 = (*obj)->next;
    free((*obj));
    (*obj) = temp2;

    return temp1;
}
EXStack_Element EXStack__Peek(EXStack_* obj) {
    if (EXStack__IsEmpty(obj)) {
        printf("ULStackPeak Error\n");
        exit(1);
    }

    return obj->data;
}

void EXStack__MemoryFree(EXStack_* obj) {
    EXStack_* temp1;
    while (obj != NULL) {
        temp1 = obj->next;
        free(obj);
        obj = temp1;
    }
}

bool EXStack__MatchingCheck(char* string) {
    EXStack_* stack = NULL;
    EXStack_Element sample;
    for (int i = 0; i < strlen(string); i++) {
        switch (string[i]) {
            case '(':
            case '[':
            case '{':
                EXStack__Push(&stack, EXStack__CreateElement(string[i]));
                break;
            case ')':
            case ']':
            case '}':
                if (EXStack__IsEmpty(stack))
                    return false;
                else {
                    sample = EXStack__Pop(&stack);
                    if ((sample.data == '(' && string[i] != ')') || (sample.data == '[' && string[i] != ']') || (sample.data == '{' && string[i] != '}')) {
                        return false;
                    }
                }
                break;
            default:
                break;
        }
    }
    if (!EXStack__IsEmpty(stack))
        return false;

    EXStack__MemoryFree(stack);
    return true;
}
char* EXStack__ClassifyNumber(char* string) {
    bool is_num_continue = false;
    int num_count = 0;
    //How many nums string have?
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= 0x30 && string[i] <= 0x39 && !is_num_continue) {
            is_num_continue = true;
            num_count++;
        } else {
            is_num_continue = false;
        }
    }
    //printf("num_count : %d\n", num_count);  //test
    if (num_count == 0) {
        printf("Don't have Num/ERROR\n");
        exit(1);
    }
    //숫자 구분 재생성.
    char* temp = (char*)malloc(strlen(string) + (num_count * 2) + 1);
    if (temp == NULL) {
        printf("ClassifyNumber/Memory Allocator Error\n");
        exit(1);
    }
    int temp_size = strlen(string) + (num_count * 2) + 1;
    int temp_indicator = 0;
    is_num_continue = false;
    for (int i = 0; i < strlen(string); i++) {
        if (temp_indicator < temp_size) {
            if (string[i] >= 0x30 && string[i] <= 0x39 && !is_num_continue) {
                is_num_continue = true;
                temp[temp_indicator++] = '[';
                temp[temp_indicator++] = string[i];
            } else if (is_num_continue && (string[i] < 0x30 || string[i] > 0x39)) {
                is_num_continue = false;
                temp[temp_indicator++] = ']';
                if (string[i] != '[' && string[i] != ']') {
                    temp[temp_indicator++] = string[i];
                }
            } else {
                if (string[i] != '[' && string[i] != ']') {
                    temp[temp_indicator++] = string[i];
                }
            }
        }
    }
    //끝이 숫자로 끝났을 경우 ']' 추가
    if (is_num_continue) {
        temp[temp_indicator++] = ']';
    }
    temp[temp_indicator] = '\0';
    //printf("ClassifyNumber Result: %s\n", temp);  //test
    return temp;
}
char* EXStack__EncodingPostfixNotation(char* string) {
    if (!EXStack__MatchingCheck(string)) {
        printf("EncodingPostfixNotation Error/괄호가 올바르지 않습니다.\n");
        exit(1);
    }

    char* string_refined = EXStack__ClassifyNumber(string);
    if (string_refined == NULL) {
        printf("EncodingPostfixNotation Error/EXClassifyNumber Fail\n");
        exit(1);
    }

    EXStack_* stack = NULL;
    EXStack_Element sample;
    char* result = (char*)malloc(strlen(string_refined) + 1);

    int result_indicator = 0;
    for (int i = 0; i < strlen(string_refined); i++) {
        switch (string_refined[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
                while (!EXStack__IsEmpty(stack) && (EXStack__OperatorProirity(EXStack__Peek(stack).data) >= EXStack__OperatorProirity(string_refined[i]))) {
                    result[result_indicator++] = EXStack__Pop(&stack).data;
                }
                EXStack__Push(&stack, EXStack__CreateElement(string_refined[i]));
                break;
            case '(':
                EXStack__Push(&stack, EXStack__CreateElement(string_refined[i]));
                break;
            case ')':
                sample = EXStack__Pop(&stack);
                while (sample.data != '(') {
                    result[result_indicator++] = sample.data;
                    sample = EXStack__Pop(&stack);
                }
                break;
            default:
                result[result_indicator++] = string_refined[i];
                break;
        }
    }

    while (!EXStack__IsEmpty(stack)) {
        result[result_indicator++] = EXStack__Pop(&stack).data;
    }
    free(string_refined);
    result[result_indicator] = '\0';
    //printf("EXEncodingPostfixNotation Result: %s\n", result);  //test
    return result;
}
int EXStack__OperatorProirity(char obj) {
    switch (obj) {
        case '(':
        case ')':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
    }
    return -1;
}

//EX2
bool EX2Stack__IsEmpty(EX2Stack_* obj) {
    if (obj == NULL)
        return true;
    return false;
}

void EX2Stack__Push(EX2Stack_** obj, EX2Stack_Element item) {
    if ((*obj) == NULL) {
        (*obj) = (EX2Stack_*)malloc(sizeof(EX2Stack_));
        (*obj)->data = item;
        (*obj)->next = NULL;
    } else {
        EX2Stack_* temp = (EX2Stack_*)malloc(sizeof(EX2Stack_));
        temp->data = item;
        temp->next = (*obj);
        (*obj) = temp;
    }
}

EX2Stack_Element EX2Stack__CreateElement(int data) {
    EX2Stack_Element temp = {data};
    return temp;
}
EX2Stack_Element EX2Stack__Pop(EX2Stack_** obj) {
    if (EX2Stack__IsEmpty((*obj))) {
        printf("ULStackPop Error\n");
        exit(1);
    }
    EX2Stack_Element temp1 = (*obj)->data;
    EX2Stack_* temp2 = (*obj)->next;
    free((*obj));
    (*obj) = temp2;

    return temp1;
}
EX2Stack_Element EX2Stack__Peek(EX2Stack_* obj) {
    if (EX2Stack__IsEmpty(obj)) {
        printf("ULStackPeak Error\n");
        exit(1);
    }
    return obj->data;
}
void EX2Stack__MemoryFree(EX2Stack_* obj) {
    EX2Stack_* temp1;
    while (obj != NULL) {
        temp1 = obj->next;
        free(obj);
        obj = temp1;
    }
}

int EX2Stack__CaclulatePostfixNotation(char* string) {
    char* string_refined = EXStack__EncodingPostfixNotation(string);
    if (string_refined == NULL) {
        printf("EXCaclulatePostfixNotation/Memory Allocator Error\n");
        exit(1);
    }

    printf("(EXCaclulatePostfixNotation) Method Initiaiting... - %s\n", string_refined);
    EX2Stack_* stack_int = NULL;
    EX2Stack_Element sample;
    EX2Stack_Element result;
    int temp = 0;
    int to = 0, from = 0;
    for (int i = 0; i < strlen(string_refined); i++) {
        switch (string_refined[i]) {
            case '+':
                sample = EX2Stack__Pop(&stack_int);
                temp = EX2Stack__Pop(&stack_int).data + sample.data;
                EX2Stack__Push(&stack_int, EX2Stack__CreateElement(temp));
                break;
            case '-':
                sample = EX2Stack__Pop(&stack_int);
                temp = EX2Stack__Pop(&stack_int).data - sample.data;
                EX2Stack__Push(&stack_int, EX2Stack__CreateElement(temp));
                break;
            case '*':
                sample = EX2Stack__Pop(&stack_int);
                temp = EX2Stack__Pop(&stack_int).data * sample.data;
                EX2Stack__Push(&stack_int, EX2Stack__CreateElement(temp));
                break;
            case '/':
                sample = EX2Stack__Pop(&stack_int);
                temp = EX2Stack__Pop(&stack_int).data / sample.data;
                EX2Stack__Push(&stack_int, EX2Stack__CreateElement(temp));
                break;
            case '[':
                from = i + 1;
                break;
            case ']':
                to = i - 1;
                temp = ToIntegerFromCharArr(string_refined, from, to);
                EX2Stack__Push(&stack_int, EX2Stack__CreateElement(temp));
                break;
        }
    }
    printf("Method Resulting... : ");
    while (!EX2Stack__IsEmpty(stack_int)) {
        result = EX2Stack__Pop(&stack_int);
        // printf("%d  ",result.data);
    }
    printf("\n");

    free(string_refined);
    EX2Stack__MemoryFree(stack_int);
    return result.data;
}

//EX3
bool EX3Stack__IsEmpty(EX3Stack_* obj) {
    if (obj == NULL)
        return true;
    return false;
}

void EX3Stack__Push(EX3Stack_** obj, EX3Stack_Element item) {
    if ((*obj) == NULL) {
        (*obj) = (EX3Stack_*)malloc(sizeof(EX3Stack_));
        (*obj)->data = item;
        (*obj)->next = NULL;
    } else {
        EX3Stack_* temp = (EX3Stack_*)malloc(sizeof(EX3Stack_));
        temp->data = item;
        temp->next = (*obj);
        (*obj) = temp;
    }
}

EX3Stack_Element EX3Stack__CreateElement(int row, int col) {
    EX3Stack_Element temp = {row, col};
    return temp;
}
EX3Stack_Element EX3Stack__Pop(EX3Stack_** obj) {
    if (EX3Stack__IsEmpty((*obj))) {
        printf("ULStackPop Error\n");
        exit(1);
    }
    EX3Stack_Element temp1 = (*obj)->data;
    EX3Stack_* temp2 = (*obj)->next;
    free((*obj));
    (*obj) = temp2;

    return temp1;
}
EX3Stack_Element EX3Stack__Peek(EX3Stack_* obj) {
    if (EX3Stack__IsEmpty(obj)) {
        printf("ULStackPeak Error\n");
        exit(1);
    }
    return obj->data;
}
void EX3Stack__MemoryFree(EX3Stack_* obj) {
    EX3Stack_* temp1;
    while (obj != NULL) {
        temp1 = obj->next;
        free(obj);
        obj = temp1;
    }
}

EX3Stack_* EX3Stack__FindStartPoint(char (*map)[EX3_MAX_HORIZONTAL_SIZE]) {
    //MAP의 시작은 S, 출구는 E로 표시, PASS 0, Wall 1
    int row = -1, col = -1;
    for (int i = 0; i < EX3_MAX_VERTICAL_SIZE; i++) {
        for (int j = 0; j < EX3_MAX_HORIZONTAL_SIZE; j++) {
            if (map[i][j] == 'S') {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1 && col != -1)
            break;
    }

    EX3Stack_* point_current = NULL;
    EX3Stack__Push(&point_current, EX3Stack__CreateElement(row, col));
    return point_current;
}

bool EX3Stack__FindProcessOfPass(char (*map)[EX3_MAX_HORIZONTAL_SIZE], bool want_view, EX3Stack_** stack_correct_pass) {
    if ((*stack_correct_pass) != NULL) {
        printf("EX3FindProcessOfPass/Error : record_pass should be NULL\n");
        exit(1);
    }
    EX3Stack_* stack_direction = EX3Stack__FindStartPoint(map);

    EX3Stack_Element current_position;
    EX3Stack_Element adjusted_position;
    bool is_push = true;
    bool is_adjust = false;

    memset(&current_position, 0, sizeof(EX3Stack_Element));  //temp 초기화
    memset(&adjusted_position.col, -1, sizeof(int));
    memset(&adjusted_position.row, -1, sizeof(int));
    do {
        current_position = EX3Stack__Pop(&stack_direction);
        is_push = false;

        //current_position의 유효성 검사
        while (is_adjust) {
            if (EX3Stack__CheckValidityForPosition(EX3Stack__Peek(*stack_correct_pass), current_position)) {
                memset(&adjusted_position.col, -1, sizeof(int));
                memset(&adjusted_position.row, -1, sizeof(int));
                is_adjust = false;
                EX3Stack__View(map, EX3Stack__Peek(*stack_correct_pass));
                break;
            } else {
                if (EX3Stack__IsEmpty(*stack_correct_pass)) {
                    printf("EX3StackFindProcessOfPass: EX3StackCheckValidityForPosition/ERROR\n");
                    exit(1);
                }
                adjusted_position = EX3Stack__Pop(stack_correct_pass);
                if (want_view)
                    EX3Stack__View(map, adjusted_position);
            }
        }
        if (map[current_position.row][current_position.col] == 'E')
            is_push = true;

        //반시계 회전탐색
        //북
        if (EX3Stack__ComparisonFactorCalulation(map, *stack_correct_pass, current_position.row - 1, current_position.col)) {
            EX3Stack__Push(&stack_direction, EX3Stack__CreateElement(current_position.row - 1, current_position.col));
            is_push = true;
        }
        //서
        if (EX3Stack__ComparisonFactorCalulation(map, *stack_correct_pass, current_position.row, current_position.col - 1)) {
            EX3Stack__Push(&stack_direction, EX3Stack__CreateElement(current_position.row, current_position.col - 1));
            is_push = true;
        }
        //남
        if (EX3Stack__ComparisonFactorCalulation(map, *stack_correct_pass, current_position.row + 1, current_position.col)) {
            EX3Stack__Push(&stack_direction, EX3Stack__CreateElement(current_position.row + 1, current_position.col));
            is_push = true;
        }
        //동
        if (EX3Stack__ComparisonFactorCalulation(map, *stack_correct_pass, current_position.row, current_position.col + 1)) {
            EX3Stack__Push(&stack_direction, EX3Stack__CreateElement(current_position.row, current_position.col + 1));
            is_push = true;
        }

        //모두 막혀있는 경우.
        if (!is_push) {
            if (!EX3Stack__IsEmpty(stack_direction) && !EX3Stack__IsEmpty(*stack_correct_pass)) {
                is_adjust = true;  //지나온 길을 되돌아가면서 시작부분에서 새로운 길을 다시 찾고 유효성 검사하도록 한다.
                continue;
            } else if (EX3Stack__IsEmpty(stack_direction)) {
                EX3Stack__MemoryFree(stack_direction);
                return false;
            } else {
                EX3Stack__MemoryFree(stack_direction);
                return false;
            }
        }

        EX3Stack__Push(stack_correct_pass, current_position);
        if (want_view)
            EX3Stack__View(map, EX3Stack__Peek(*stack_correct_pass));

    } while (map[current_position.row][current_position.col] != 'E');

    EX3Stack__MemoryFree(stack_direction);
    return true;
}
/*
row_t,col_t : POP한것
row_
*/
bool EX3Stack__ComparisonFactorCalulation(char (*map)[EX3_MAX_HORIZONTAL_SIZE], EX3Stack_* stack_pass, int row_t, int col_t) {
    if (row_t < 0 || row_t >= EX3_MAX_VERTICAL_SIZE || col_t < 0 || col_t >= EX3_MAX_HORIZONTAL_SIZE) {
        return false;
    }

    EX3Stack_Element temp;
    if (!EX3Stack__IsEmpty(stack_pass)) {
        temp = EX3Stack__Peek(stack_pass);
        if (temp.row == row_t && temp.col == col_t)
            return false;
    }

    if (map[row_t][col_t] != '0' && map[row_t][col_t] != 'E' && map[row_t][col_t] != 'S')
        return false;

    return true;
}

bool EX3Stack__CheckValidityForPosition(EX3Stack_Element obj1, EX3Stack_Element obj2) {
    if (obj1.row == obj2.row && obj1.col - 1 == obj2.col)
        return true;
    else if (obj1.row - 1 == obj2.row && obj1.col == obj2.col)
        return true;
    else if (obj1.row == obj2.row && obj1.col + 1 == obj2.col)
        return true;
    else if (obj1.row + 1 == obj2.row && obj1.col == obj2.col)
        return true;

    return false;
}

void EX3Stack__View(char (*map)[EX3_MAX_HORIZONTAL_SIZE], EX3Stack_Element current_point) {
    printf("\n");
    for (int i = 0; i < EX3_MAX_VERTICAL_SIZE; i++) {
        for (int j = 0; j < EX3_MAX_HORIZONTAL_SIZE; j++) {
            if (current_point.row == i && current_point.col == j)
                printf("K ");
            else
                printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//EX3_A => EX3A


void EX3AStack__init(EX3AStack_Type* s){
    s->top = -1;
}
int EX3AStack__is_empty(EX3AStack_Type* s){
    return (s->top == -1);
}
int EX3AStack__is_full(EX3AStack_Type* s){
    return (s->top == (EX3ASTACK_MAX_SIZE - 1));
}
void EX3AStack__push(EX3AStack_Type* s, EX3AStack_Element item){
    if(EX3AStack__is_full(s)){
        printf("stack full error\n");
        exit(1);
    }
    else
        s->stack[++(s->top)] = item;
}

EX3AStack_Element EX3AStack__pop(EX3AStack_Type* s){
    if(EX3AStack__is_empty(s)){
        printf("stack empty error\n");
        exit(1);
    }
    else{
        return s->stack[(s->top)--];
    }
}
EX3AStack_Element EX3AStack__peek(EX3AStack_Type* s){
    if(EX3AStack__is_empty(s)){
        printf("stack empty error\n");
        exit(1);
    }
    else
        return s->stack[s->top];
}


void EX3AStack__push_Loc(EX3AStack_Type* s, int r, int c,char (*maze)[EX3ASTACK_MAZE_MAX_SIZE]){
    if(r<0||c<0)
        return;
    if(maze[r][c] != '1' && maze[r][c] != '.'){
        EX3AStack_Element tmp;
        tmp.r = r;
        tmp.c = c;
        EX3AStack__push(s, tmp);
    }
}