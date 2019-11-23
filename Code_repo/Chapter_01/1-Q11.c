// __________양수 A의 자릿수 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, numA, pow10, test;
	int numIndex;

	puts("양수 A의 자릿수를 구합니다.");
	do {
		printf("A의 값: ");
		scanf("%d", &numA);
	} while (numA <= 0);
	i = 0;
	do {
		pow10 = 1;
		// 10의 i제곱을 계산하는 내부 loop
		for (int j = 0; j <= i; j++) {
			pow10 *= 10;
		}

		test = (int)(numA / pow10);
		i++;
	} while (test);
	numIndex = i;

	printf("그 수는 %d자리입니다.", numIndex);

	return 0;
}