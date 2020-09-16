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

 int* GenerateRandomNumber__NoOverlap(int numbers, int range_max){
    if (numbers > range_max) exit(1); //Error

    int* value_array = (int*)calloc(numbers,sizeof(int));

    for (int i = 0; i < numbers; i++){
        value_array[i] = GenerateRandomNumber(range_max);
        for (int j = 0; j < i; j++){
            if(value_array[j]==value_array[i]){
                i--;
                break;
            }
        }
    }

    return value_array;
}

