#include "Test_Control.h"
#if ___FACTORIAL
#include "Factorial.h"
/*
Factorial
in : n factorial 
2가지 방법으로 구현 가능.

n! =	{ 1 		, n = 0 }
		{ n * (n-1)!, n >=1 }
		 
*/
//Circulation
int Factorial_C(int n) {
    if (n <= 1)
        return 1;
    else
        return (n * Factorial_C(n - 1));
}
//Repeat
int Factorial_R(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result = result * i;
    }
    return result;
}
#endif