// __________��� A�� �ڸ��� ���ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, numA, pow10, test;
	int numIndex;

	puts("��� A�� �ڸ����� ���մϴ�.");
	do {
		printf("A�� ��: ");
		scanf("%d", &numA);
	} while (numA <= 0);
	i = 0;
	do {
		pow10 = 1;
		// 10�� i������ ����ϴ� ���� loop
		for (int j = 0; j <= i; j++) {
			pow10 *= 10;
		}

		test = (int)(numA / pow10);
		i++;
	} while (test);
	numIndex = i;

	printf("�� ���� %d�ڸ��Դϴ�.", numIndex);

	return 0;
}