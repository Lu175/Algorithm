// _________���� ���Ƕ�̵� ����ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void nrpira(int n);

int main(void) {
	int n;

	do {
		printf("�� �� �Ƕ�̵� �Դϱ�? : ");
		scanf("%d", &n);
	} while (n <= 0);
	nrpira(n);

	return 0;
}


void nrpira(int n) {
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) { printf("  "); }
		for (k = 0; k <= 2 * (n - i); k++) { printf(" %d", i % 10); }
		putchar('\n');
	}
	putchar('\n');
}