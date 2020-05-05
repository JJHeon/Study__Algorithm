#include "Math.h"

int Max(int A, int B){
    if(A>B)
        return A;
    else
        return B;
}
void InitGenerateRandomNumber(void){
    srand((unsigned int)time(NULL));
}
int GenerateRandomNumber(int range_max){
    return (int)((double)rand()/ RAND_MAX * range_max);
}
