#include "Test_Control.h"

#if ___KOREAN_CHARACTER_ADJUSTMENT

#include "Korean_Character_Adjustment_InUTF8.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KoreanAdjInUTF8Count(char* string) {
    //printf("%d\n", strlen(string));
    if (strlen(string) < 3) {
        printf("KoreanAdjInUTF8Count Error/Too small sentence\n");
        exit(1);
    }
    //int k = strlen(string);
    int count_korean = 0;

    for (int i = 0; i < strlen(string); i++) {
        
        //printf("%x %x %x\n", string[i + 0], string[i + 1], string[i + 2]);
        //printf("%d %d %d\n",(string[i] >= -22 && string[i] <= -19), ((string[i + 1] & 0x80) == 0x80) , ((string[i + 2] & 0x80) == 0x80));
        //-22 => 0xEA ,-19=> 0xED, char은 양수 127을 넘어가는 숫자는 표현하지 못한다. 그런데 16진수 0xEA는 250을 뜻함으로 음수로 처리된다.
        if ((string[i] >= -22 && string[i] <= -19) && ((string[i + 1] & 0x80) == 0x80) && ((string[i + 2] & 0x80) == 0x80)) {
            i += 2;
            count_korean++;
        }

    }
    return count_korean;
}
void KoreanAdjInUTF8Print(int num) {
    for (int i = 0; i < num; i++) {
        printf(" ");
    }
}
#endif