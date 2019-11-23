// _________피라미드 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void spira(int n);

int main(void) {
	int n;

	do {
		printf("몇 단 피라미드 입니까? : ");
		scanf("%d", &n);
	} while (n <= 0);
	spira(n);

	return 0;
}


void spira(int n) {
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = n; j >= i; j--) { printf("  "); }
		for (k = 1; k < (2 * i); k++) { printf(" *"); }
		putchar('\n');
	}
	putchar('\n');
}