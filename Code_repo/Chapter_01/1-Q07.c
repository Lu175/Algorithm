// __________1���� n������ ���� �� ���ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, n;
	int sum;

	puts("1���� n������ ���� ���մϴ�.");
	printf("n�� ��: ");
	scanf("%d", &n);

	sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
		printf("%d", i);
		if (i < n)
			printf(" + ");
		else
			printf(" = ");
	}
	printf("%d\n", sum);

	return 0;
}