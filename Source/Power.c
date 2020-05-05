#include "Test_Control.h"
#if (___INVOLUTION_OR_POWER)
#include "Power.h"
/*
Involution or Power (거듭 제곱법) 
Circulation O(log2(n))
Repeat		O(n)	
*/
//Repeat
double Power_R(double eq, int n) {
    double result = 1.0;
    for (int i = 0; i < n; i++)
        result = result * eq;
    return result;
}
//Circulation
double Power_C(double eq, int n) {
    if (n == 0)
        return 1;
    else if ((n % 2) == 0)
        return Power_C(eq * eq, n / 2);
    else
        return eq * Power_C(eq * eq, (n - 1) / 2);
}
#endif