// __________네 값의 최솟값__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min4(int a, int b, int c, int d) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;
	return min;
}

int main(void) {
	printf("min4(%d, %d, %d, %d) = %d\n", 4, 3, 2, 1, min4(4, 3, 2, 1));
	printf("min4(%d, %d, %d, %d) = %d\n", 3, 3, 4, 2, min4(3, 3, 4, 2));
	printf("min4(%d, %d, %d, %d) = %d\n", 3, 4, 4, 3, min4(3, 4, 4, 3));

	return 0;
}