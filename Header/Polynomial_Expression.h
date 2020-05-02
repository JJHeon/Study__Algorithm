#ifndef __POLYNOMIAL_EXPRESSION_H_
#define __POLYNOMIAL_EXPRESSION_H_
/*
Polynomial Expression 1

Polynomial_Equation_expr1 =>PEE1

다항식의 표현방법 #1 
모든 차수에 대한 계수값을 배열로 저장.
하나의 다항식을 하나의 배열로 표현. 
장점 : 구현이 쉬움. 
단점 : 항의 계수가 0인 항이 많으면 공간 낭비가 심한 다항식 표현법

PolynomialExpressionOneAdd		다항식간 덧셈. 
PolynomialExpressionOnePrint	다항식 화면출력 
*/
#define POLYNOMIAL_EXPR1_MAX_DEGREE 6
typedef struct PEE1 {
    int degree;
    double coef[POLYNOMIAL_EXPR1_MAX_DEGREE];
} PEE1;

PEE1 PEE1__Add(PEE1 A, PEE1 B);
void PEE1__Print(PEE1 A);

/*
Polynomial Expression 2

Polynomial_Equation_expr2 =>PEE2


다항식의 표현방법 #2
개인적으로 선호되지 않는 방법임. 
0이 아닌 항만을 배열에 저장 
(계수, 차수) 형식으로 배열에 저장 함

배열 하나에 여러 다항식이 공존할 수 있고 각 다항식의 범위는 As,Ae 같은 변수로 지정되있다. 
*/
#define POLYNOMIAL_EXPR2_MAX_TERMS 50
typedef struct PEE2 {
    float coef;
    int expon;
} PEE2;

char PEE2__CompareWithExpon(int A, int B);
void PEE2__Attach_JH(PEE2 *terms, int *avail, double coef, int expon);
void PEE2__Add(PEE2 *terms, int *avail, int As, int Ae, int Bs, int Be, int *Cs, int *Ce);
void PEE2__Print(PEE2 *terms, int *avail);
#endif