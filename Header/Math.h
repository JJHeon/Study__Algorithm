#ifndef __MATH_H_
#define __MATH_H_
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Max(int A, int B);


void InitGenerateRandomNumber(void);
/*
C/C++이야 오래전 언어라서 기본 랜덤 함수가 약하긴 하지만 자바나 C#은 이런 문제가 전혀 없죠. 이들 언어에서는 double랜덤을 리턴한다던지, 범위 랜덤을 자동으로 구해주는 기능이 있습니다. 하지만 C++을 쓴다면 알아둬야 합니다. rand() % n은 분포가 고르게 나오지 않을 수 있습니다.

C/C++의 rand()를 보면 최대값이 RAND_MAX로 정의되어있죠. 32767입니다. 어떻게 보면 상당히 작은 값입니다. 그리고 이 값이 실제로 쓰기엔 좀 작기 때문에 보통 rand() % n의 분포에 문제가 생깁니다.

예를 들어보죠. 0~9999사이의 랜덤을 구하면 보통 rand() % 10000으로 씁니다. 하지만 이렇게 되면 0~2767가 2768~9999보다 많이 나옵니다. 즉, rand()가 이상적으로 고른 분포를 가진다고 했을 때, 원래대로라면 0~2767 범위에서 랜덤 값이 27.67% 확률로 나와야 하지만 실제로는 그보다 더 나옵니다.

이유는 간단합니다. rand()의 범위 자체가 애초에 0~32767인데, 이 범위를 늘이거나 줄이려면 랜덤 분포 자체도 scaling해야지, 범위를 단순히 modulo연산으로 나눠버리면 나눠서 떨어지지 않는 부분은 그 만큼 랜덤이 더 나오게 되죠.
 
이유를 알았으니, 분포를 고르게 하는 방법 역시 쉽습니다. rand()의 범위를 쉽게 0~1의 실수형으로 바꾼 후, 여기에 우리가 원하는 범위값을 곱해주면 됩니다. 아래와 같이요.

(double)rand() / RAND_MAX * RANGE_MAX
CAUTION: RANGE_MAX 의 범위 32767 까지.
*/
int GenerateRandomNumber(int range_max);

#endif