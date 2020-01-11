// __________function pointer / µ¡¼ÀÇ¥, °ö¼ÀÇ¥ print__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int x1, int x2);
int mul(int x1, int x2);
void kuku(int(*calc)(int, int));

int main(void) {
	puts("µ¡¼ÀÇ¥");
	kuku(sum);
	puts("\n°ö¼ÀÇ¥");
	kuku(mul);

	return 0;
}

int sum(int x1, int x2) {
	return x1 + x2;
}

int mul(int x1, int x2) {
	return x1 * x2;
}

void kuku(int(*calc)(int, int)) {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			printf("%3d", (*calc)(i, j));
		}
		putchar('\n');
	}
}