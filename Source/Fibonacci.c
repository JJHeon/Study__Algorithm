#include "Fibonacci.h"
/*
Fibonacci Numbers
in	: n까지의 피보나치 수열
 
Circulation 사용시 비효율적, n이 크면 클수록 중복호출이 심해짐 
*/
int FibonacciNumbers_C(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (FibonacciNumbers_C(n - 1) + FibonacciNumbers_C(n - 2));
}
int FibonacciNumbers_R(int n) {
    int temp, current = 1, last = 0;
    if (n < 2)
        return n;
    else {
        for (int i = 2; i <= n; i++) {
            temp = current;
            current += last;
            last = temp;
        }
        return current;
    }
}
