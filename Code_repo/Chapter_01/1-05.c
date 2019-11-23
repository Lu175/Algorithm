// __________1부터 n까지의 정수 합 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, n;
	int sum;

	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값: ");
	scanf("%d", &n);

	sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
	}
	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

	return 0;
}