#include "Test_Control.h"
#if ___SPARSE_MATRIX_EXPRESSION

#include "SparseMatrix.h"
#include <stdio.h>
#include <stdlib.h>
/*
Sparse Matrix
희소행렬 표현법 #1
이러한 0들이 많은 행렬을 희소행렬이라 하는데, 이를 효율적으로 저장하는 방법. 
대부분의 항이 0인 행렬인 경우 일반적인 2차원 배열에 행렬을 저장하는 것은 메모리 낭비가 심하다.
*/
SME1 SME1__Add(SME1 *A, SME1 *B) {
    SME1 C;
    int ca = 0, cb = 0, cc = 0; //각 배열의 항목을 가르키는 인덱스

    //배열 A와 B의 크기가 같은지 확인
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("SparseMatrixExpressionAdd Size ERROR\n");
        exit(1);
    }
    C.rows = A->rows;
    C.cols = A->cols;
    C.terms = 0;

    int inda, indb; //각 행렬의 순차번호
    while (ca < A->terms && cb < B->terms) {
        inda = A->data[ca].row * A->cols + A->data[ca].col;
        indb = B->data[cb].row * B->cols + B->data[cb].col;
        if (inda < indb) { //A 배열 항목이 앞에 있으면
            C.data[cc++] = A->data[ca++];
        } else if (inda == indb) { //A와 B가 같은 위치
            if ((A->data[ca].value + B->data[cb].value) != 0) {
                C.data[cc].row = A->data[ca].row;
                C.data[cc].col = A->data[ca].col;
                C.data[cc++].value = A->data[ca++].value + B->data[cb++].value;
            } else {
                ca++;
                cb++;
            }
        } else { //B 배열 항목이 앞에 있음
            C.data[cc++] = B->data[cb++];
        }
    }
    for (; ca < A->terms;)
        C.data[cc++] = A->data[ca++];
    for (; cb < B->terms;)
        C.data[cc++] = B->data[cb++];
    C.terms = cc;

    return C;
}
void SME1__Print(SME1 *A) {
    if (A->terms < 1) {
        printf("SparseMatrixExpressionPrint ERROR/terms size too small\n");
        exit(1);
    }
    printf("\n");
    int terms = 0;
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            if (i == A->data[terms].row && j == A->data[terms].col) {
                printf("%d ", A->data[terms++].value);
            } else
                printf("%0d ", 0);
        }
        printf("\n");
    }
}
#endif