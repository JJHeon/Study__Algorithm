#include "Test_Control.h"
#if ___ToInteger

#include "Power.h"
#include "ToInteger.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ToIntegerFromCharArr(char* string, int from, int to) {
    if(string ==NULL){
        printf("ToIntegerFromCharArr/Error string == NULL");
        exit(1);
    }
    
    int result = 0;
    int multiple_10 = to - from;
    int temp = 0;
    for (int i = from; i <= to; i++) {
        if (string[i] >= 0x30 && string[i] <= 0x39) {
            temp = string[i] - 0x30;
            result += (int)Power_C(10.0, multiple_10--) * temp;
        }else{
            printf("ToIntegerFromCharArr/Error string is not complete num.\n");
            exit(1);
        }
    }
    return result;
}
#endif