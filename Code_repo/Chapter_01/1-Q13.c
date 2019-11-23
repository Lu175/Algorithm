// __________µ¡¼ÀÇ¥ Ãâ·ÂÇÏ±â__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j;

	puts("  |  1  2  3  4  5  6  7  8  9");
	printf("--+---------------------------\n");
	for (i = 1; i <= 9; i++) {
		printf("%d |", i);
		for (j = 1; j <= 9; j++) {
			printf("%3d", i + j);
		}
		putchar('\n');
	}

	return 0;
}