// _________배열 초기화__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i;
	int a[5] = { 1, 2, 3, 4, 5 };
	int na = sizeof(a) / sizeof(a[0]);

	printf("배열 a의 요소 개수는 %d입니다.\n", na);

	for (i = 0; i < na; i++) { printf("a[%d] = %d\n", i, a[i]); }

	return 0;
}