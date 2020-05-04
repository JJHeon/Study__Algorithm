#include "Test_Control.h"
#if ___HANOI_TOWER
#include "HanoiTower.h"
#include <stdio.h>
/*
 Hanoi Top
 in : 원판 개수 n, (from temp to) : A B C 
 n개의 원판을 A->B->C(A에서 C)로 옮길 수 있는 방법
 이러한 방법은 머리에서 직관적으로 떠오르기 어렵다. 가능하다 하더라도 순간적으로 많은 것들을 기억하면서
 진행을 도표화 시키면서 일련의 규칙을 찾아야한다. 따라서 왠만하면 손으로 적으면서 규칙을 찾도록 하자.
 Ex) 4개의 원판이 있을 경우. 다음은 일련의 규칙성을 보인다
 
 1 ACB A->B
 2 ABC A->C
 1 BAC B->C
 3 ACB A->B
 1 CBA C->A
 2 CAB C->B
 1 ACB A->B
 4 ABC A->C
 1 BAC B->C
 2 BCA B->A
 1 CBA C->A
 3 BAC B->C
 1 ACB A->B
 2 ABC A->C
 1 BAC B->C
 
 이러힌 경우 circulation으로 구성하는게 타당해 보인다. 
 */
void HanoiTower_C(int n, char from, char temp, char to) {
    if (n == 1)
        printf("원판 %d을 %c 에서 %c로 옮긴다.\n", 1, from, to);
    else {
        HanoiTower_C(n - 1, from, to, temp);
        printf("원판 %d을 %c 에서 %c로 옮긴다.\n", n, from, to);
        HanoiTower_C(n - 1, temp, from, to);
    }
}
#endif