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
	if (n % 2) {
		sum = n--;
	}
	sum += (1 + n) * (n / 2);

	printf("1���� �Է��� ���ڱ����� ���� %d�Դϴ�.\n", sum);

	return 0;
}