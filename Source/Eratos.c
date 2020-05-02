#include "Eratos.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
Eratostenes
소수를 찾는 방법. 
in : 찾고자 하는 1 ~ n 소수 범위 
out : i 에서 소수인지 true,false를 가진 배열 주소 
*/
bool* Eratos(int n) {
    if (n <= 1)
        return false;

    /*	2부터 n까지 n-1개를 저장할 수 있는 배열 할당
		배열 참조 번호와 소수와 일치하도록 배열의 크기는
		n+1 길이만큼 할당(인덱스 번호 0과 1은 사용하지 않음)	*/
    bool* PrimeArray = (bool*)malloc(sizeof(bool) * (n + 1));

    /*  배열초기화: 처음엔 모두 소수로 보고 true값을 줌	*/
    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true;

    /*	에라토스테네스의 체에 맞게 소수를 구함
		만일, PrimeArray[i]가 true이면 i 이후의 i 배수는 약수로 i를 
		가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
		PrimeArray[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시
		소수가 아니게 된다. 그러므로 검사할 필요도 없다.
		또한 i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2 에서 i*i로 개선할 수 있다.
	*/
    for (int i = 2; i * i <= n; i++) {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
    }
    return PrimeArray;
}