// __________네 값의 최댓값__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max4(int a, int b, int c, int d) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}

int main(void) {
	printf("max4(%d, %d, %d, %d) = %d\n", 4, 3, 2, 1, max4(4, 3, 2, 1));
	printf("max4(%d, %d, %d, %d) = %d\n", 3, 3, 4, 1, max4(3, 3, 4, 1));
	printf("max4(%d, %d, %d, %d) = %d\n", 2, 1, 2, 3, max4(2, 1, 2, 3));

	return 0;
}