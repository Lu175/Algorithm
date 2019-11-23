// __________정사각형 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j, n;

	puts("정사각형을 출력합니다.");
	printf("입력할 수: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf(" *");
		}
		putchar('\n');
	}

	return 0;
}