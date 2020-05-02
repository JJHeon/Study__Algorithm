#ifndef __KOREAN_CHARACTER_ADJUSTMENT_INUTF8_H_
#define __KOREAN_CHARACTER_ADJUSTMENT_INUTF8_H_
/*
Korean_Adj_InUTF8
UTF8에선 한글은 한문자당 3바이트를 차지한다.
따라서 출력시에는 2바이트크기로 출력이 되는데 바이트수는 3바이트이므로
1바이트 손해가 발생해 아래와 같은 의도된 문장 크기 출력이 어려워 진다.
printf("%10s","한글"); //한칸씩 앞으로 밀림 한문자당.

따라서 한글 후에 공백을 출력해 크기를 맞춰줄 필요가 있다.
*/
int KoreanAdjInUTF8Count(char* string);
void KoreanAdjInUTF8Print(int num);

#endif
