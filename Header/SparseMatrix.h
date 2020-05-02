#ifndef __SPARSEMATRIX_H_
#define __SPARSEMATRIX_H_
/*
Sparse Matrix

Sparse Matrix Expression 1 => SME1

희소행렬 표현법 #1
이러한 0들이 많은 행렬을 희소행렬이라 하는데, 이를 효율적으로 저장하는 방법. 
대부분의 항이 0인 행렬인 경우 일반적인 2차원 배열에 행렬을 저장하는 것은 메모리 낭비가 심하다.
*/
#define SPARSE_MATRIX_ELEMENT_TERMS_NUMBER 10
typedef struct SME1_Element {
    int row;
    int col;
    int value;
} SME1_Element;
typedef struct SME1 {
    SME1_Element data[SPARSE_MATRIX_ELEMENT_TERMS_NUMBER];
    int rows;
    int cols;
    int terms;
} SME1;

SME1 SME1__Add(SME1 *A, SME1 *B);
void SME1__Print(SME1 *A);
#endif
