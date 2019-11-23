// _________배열 복사__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

void aryCopy(int copy[], const int source[], int elementNum);

int main(void) {
	int i;
	int* s;
	int* c;
	int eleNum;

	printf("배열의 요소 수 : ");
	scanf("%d", &eleNum);
	s = calloc(eleNum, sizeof(int));
	c = calloc(eleNum, sizeof(int));

	// source의 요소를 난수로 생성
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

	// 배열 복사
	for (i = 0; i < elementNum; i++) {
		copy[i] = source[i];
		printf("%d ", copy[i]);
	}
}