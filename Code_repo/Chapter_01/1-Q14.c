// __________���簢�� ����ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j, n;

	puts("���簢���� ����մϴ�.");
	printf("�Է��� ��: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf(" *");
		}
		putchar('\n');
	}

	return 0;
}