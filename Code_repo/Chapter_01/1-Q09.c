// __________A���� B������ ���� �� ���ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumof(int a, int b);

int main(void) {
	int numA, numB;
	puts("A���� B������ ���� ���մϴ�. (��� �������� ����)");
	printf("A�� ��: ");
	scanf("%d", &numA);
	printf("B�� ��: ");
	scanf("%d", &numB);

	if (numA > numB) {
		printf("%d���� %d������ ���� %d�Դϴ�.\n", numB, numA, sumof(numA, numB));
	}
	else if (numA < numB) {
		printf("%d���� %d������ ���� %d�Դϴ�.\n", numA, numB, sumof(numB, numA));
	}
	else
		printf("%d���� %d������ ���� %d�Դϴ�.\n", numA, numB, 0);


	return 0;
}

int sumof(int numHigh, int numLow) {
	int sumHigh = 0;
	int sumLow = 0;
	numLow--;

	// 1���� numHigh������ �� ���ϱ�
	if (numHigh % 2) {
		sumHigh = numHigh--;
	}
	sumHigh += (1 + numHigh) * (numHigh / 2);

	// 1���� (numLow - 1)������ �� ���ϱ�
	if (numLow % 2) {
		sumLow = numLow--;
	}
	sumLow += (1 + numLow) * (numLow / 2);

	return sumHigh - sumLow;
}