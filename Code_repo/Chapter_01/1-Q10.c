// __________b-a �����ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, numA, numB;

	puts("(B - A)�� ���� ���մϴ�.");
	do {
		printf("A�� ��: ");
		scanf("%d", &numA);
	} while (numA < 0);
	i = 0;
	do {
		if (i++) printf("A���� ū ���� �Է��ϼ���!!\n");

		printf("B�� ��: ");
		scanf("%d", &numB);
	} while ((numB - numA) <= 0);
	printf("(%d - %d)�� ���� %d�Դϴ�.", numB, numA, numB - numA);

	return 0;
}