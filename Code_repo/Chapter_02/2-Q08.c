// _________�迭 ����__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

void aryCopy(int copy[], const int source[], int elementNum);

int main(void) {
	int i;
	int* s;
	int* c;
	int eleNum;

	printf("�迭�� ��� �� : ");
	scanf("%d", &eleNum);
	s = calloc(eleNum, sizeof(int));
	c = calloc(eleNum, sizeof(int));

	// source�� ��Ҹ� ������ ����
	srand(time(NULL));
	printf("source: ");
	for (i = 0; i < eleNum; i++) {
		s[i] = rand() % 100;
		printf("%d ", s[i]);
	}
	puts("");
	aryCopy(c, s, eleNum);

	return 0;
}


void aryCopy(int copy[], const int source[], int elementNum) {
	int i;
	printf("  copy: ");

	// �迭 ����
	for (i = 0; i < elementNum; i++) {
		copy[i] = source[i];
		printf("%d ", copy[i]);
	}
}