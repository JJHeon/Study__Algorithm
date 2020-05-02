#include "Polynomial_Expression.h"
#include <stdio.h>
#include <stdlib.h>
/*
 Polynomial Expression 1
다항식의 표현방법 #1 
모든 차수에 대한 계수값을 배열로 저장.
하나의 다항식을 하나의 배열로 표현. 
장점 : 구현이 쉬움. 
단점 : 항의 계수가 0인 항이 많으면 공간 낭비가 심한 다항식 표현법

PolynomialExpressionOneAdd		다항식간 덧셈. 
PolynomialExpressionOnePrint	다항식 화면출력 
*/
PEE1 PEE1__Add(PEE1 A, PEE1 B) {
    PEE1 C; //결과 다항식
    int A_pos = 0, B_pos = 0, C_pos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;

    C.degree = A.degree > B.degree ? A.degree : B.degree;
    while (A_pos <= A.degree && B_pos <= B.degree) {
        if (degree_a > degree_b) {
            C.coef[C_pos++] = A.coef[A_pos++];
            degree_a--;
        } else if (degree_a == degree_b) {
            C.coef[C_pos++] = A.coef[A_pos++] + B.coef[B_pos++];
            degree_a--;
            degree_b--;
        } else {
            C.coef[C_pos++] = B.coef[B_pos++];
            degree_b--;
        }
    }
    return C;
}

void PEE1__Print(PEE1 A) {
    for (int i = 0; i < POLYNOMIAL_EXPR1_MAX_DEGREE; i++) {
        printf("%.3lf ", A.coef[i]);
    }
    printf("\n");
}

/*
Polynomial Expression 2
다항식의 표현방법 #2
개인적으로 선호되지 않는 방법임. 
0이 아닌 항만을 배열에 저장 
(계수, 차수) 형식으로 배열에 저장 함

배열 하나에 여러 다항식이 공존할 수 있고 각 다항식의 범위는 As,Ae 같은 변수로 지정되있다. 
*/
char PEE2__CompareWithExpon(int A, int B) {
    if (A > B)
        return '>';
    else if (A == B)
        return '=';
    else
        return '<';
}
void PEE2Attach(PEE2 *terms, int *avail, double coef, int expon) {
    if (*avail > POLYNOMIAL_EXPR2_MAX_TERMS) {
        printf("POLYNOMIAL_EXPR2 in PolynomialExpressionTwoAttach/ERROR\n");
        exit(1);
    }
    terms[(*avail)].coef = coef;
    terms[(*avail)++].expon = expon;
}
void PEE2__Add(PEE2 *terms, int *avail, int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
    double tempcoef;
    *Cs = *avail;
    while (As <= Ae && Bs <= Be) {
        switch (PEE2__CompareWithExpon(terms[As].expon, terms[Bs].expon)) {
        case '>': //A의 차수 > B의 차수
            PEE2Attach(terms, avail, terms[As].coef, terms[As].expon);
            As++;
            break;
        case '=': //A의 차수 == B의 차수
            tempcoef = terms[As].coef + terms[Bs].coef;
            if (tempcoef)
                PEE2Attach(terms, avail, tempcoef, terms[As].expon);
            As++;
            Bs++;
            break;
        case '<': //A의 차수 < B의 차수
            PEE2Attach(terms, avail, terms[Bs].coef, terms[Bs].expon);
            Bs++;
            break;
        }
    }
    //A의 나머지 항들 이동
    for (; As <= Ae; As++) {
        PEE2Attach(terms, avail, terms[As].coef, terms[As].expon);
    }
    //B의 나머지 항들 이동
    for (; Bs <= Be; Bs++) {
        PEE2Attach(terms, avail, terms[Bs].coef, terms[Bs].expon);
    }
    *Ce = (*avail) - 1;
}

void PEE2__Print(PEE2 *terms, int *avail) {
    for (int i = 0; i < (*avail); i++) {
        printf("[%.1lf %d] ", terms[i].coef, terms[i].expon);
    }
    printf("\n");
}
