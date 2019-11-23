// _________직각 이등변 삼각형 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j, n;

	do {
		printf("몇 단 삼각형 입니까? : ");
		scanf("%d", &n);
	} while (n <= 0);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf(" *");
		}
		putchar('\n');
	}

	return 0;
}