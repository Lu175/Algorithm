// __________A부터 B까지의 정수 합 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumof(int a, int b);

int main(void) {
	int numA, numB;
	puts("A부터 B까지의 합을 구합니다. (모든 정수에서 가능)");
	printf("A의 값: ");
	scanf("%d", &numA);
	printf("B의 값: ");
	scanf("%d", &numB);

	if (numA > numB) {
		printf("%d부터 %d까지의 합은 %d입니다.\n", numB, numA, sumof(numA, numB));
	}
	else if (numA < numB) {
		printf("%d부터 %d까지의 합은 %d입니다.\n", numA, numB, sumof(numB, numA));
	}
	else
		printf("%d부터 %d까지의 합은 %d입니다.\n", numA, numB, 0);


	return 0;
}

int sumof(int numHigh, int numLow) {
	int sumHigh = 0;
	int sumLow = 0;
	numLow--;

	// 1부터 numHigh까지의 합 구하기
	if (numHigh % 2) {
		sumHigh = numHigh--;
	}
	sumHigh += (1 + numHigh) * (numHigh / 2);

	// 1부터 (numLow - 1)까지의 합 구하기
	if (numLow % 2) {
		sumLow = numLow--;
	}
	sumLow += (1 + numLow) * (numLow / 2);

	return sumHigh - sumLow;
}