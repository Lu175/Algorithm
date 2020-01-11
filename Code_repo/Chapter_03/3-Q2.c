// __________linear search (sentinel method) 과정 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "linSearch_print.h"

int linSearch_print(int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("선형 검색 (보초법)");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));
	printf("\n임의의 %d개 요소들로 구성된 배열을 생성합니다.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % 100;
		printf("%3d", x[i]);
	}
	printf("\n\n검색값: ");
	scanf("%d", &key);
	idx = linSearch_print(x, nx, key, &compCount);    // linSearch_print
	if (idx == -1) {
		puts("\n검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	else {
		printf("\n%d(은)는 x[%d]에 있습니다.\n", key, idx);
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	free(x);

	return 0;
}