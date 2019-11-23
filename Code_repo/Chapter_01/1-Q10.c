// __________b-a 츨력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, numA, numB;

	puts("(B - A)의 값을 구합니다.");
	do {
		printf("A의 값: ");
		scanf("%d", &numA);
	} while (numA < 0);
	i = 0;
	do {
		if (i++) printf("A보다 큰 값을 입력하세요!!\n");

		printf("B의 값: ");
		scanf("%d", &numB);
	} while ((numB - numA) <= 0);
	printf("(%d - %d)의 값은 %d입니다.", numB, numA, numB - numA);

	return 0;
}