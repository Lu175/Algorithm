// _________소수 나열하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int tNum, mNum, inNum;    // test Num, mod Num, input Num
	unsigned int modCount = 0;

	puts("출력할 소수의 범위를 설정합니다.");
	do {
		printf("상한: ");
		scanf("%d", &inNum);
	} while (inNum <= 0);
	printf("자연수 중 %d이하의 소수를 출력합니다.\n\n", inNum);

	for (tNum = 2; tNum <= inNum; tNum++) {
		// tNum을 2부터 mNum-1까지 나누는 loop
		mNum = 2;
		while (1) {
			if (tNum == mNum) {
				printf("%d\n", tNum);
				break;
			}
			modCount++;
			if ((tNum % mNum) == 0) {    // 소수 X
				break;
			}
			mNum++;
		}
	}
	printf("나눗셈을 실행한 횟수: %d", modCount);

	return 0;
}