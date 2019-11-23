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
	if (n % 2) {
		sum = n--;
	}
	sum += (1 + n) * (n / 2);

	printf("1부터 입력한 숫자까지의 합은 %d입니다.\n", sum);

	return 0;
}