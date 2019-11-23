// __________°ö¼ÀÇ¥ Ãâ·ÂÇÏ±â__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j;

	printf("     ----- °ö¼ÀÇ¥ -----\n");
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			printf("%3d", i * j);
		}
		putchar('\n');
	}

	return 0;
}