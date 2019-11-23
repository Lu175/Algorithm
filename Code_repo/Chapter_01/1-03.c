// __________조건 판단과 분기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;

	printf("정수를 입력하세요: ");
	scanf("%d", &n);

	if (n > 0) {
		printf("이 수는 양수입니다.\n");
	}
	else if (n < 0) {
		printf("이 수는 음수입니다.\n");
	}
	else
		printf("이 수는 0입니다.\n");

	return 0;
}