// __________binary search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "binSearch.h"

int binSearch(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("이진 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("\n임의의 %d개 요소들로 구성된 배열을 오름차순으로 생성합니다.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = rand() % 10;    // 첫 요소
	printf("%4d", x[0]);
	for (i = 1; i < nx; i++) {
		do {
			x[i] = rand() % (10 + 10 * i);    // index가 1 증가하면 랜덤 숫자 범위도 10 증가
		} while (x[i] < x[i - 1]);    // 이전 요소값보다 작으면 재입력
		printf("%4d", x[i]);
	}
	printf("\n\n검색값: ");
	scanf("%d", &key);
	idx = binSearch(x, nx, key, &compCount);    // binSearch
	if (idx == -1) {
		puts("검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회", compCount);
	}
	else {
		printf("%d(은)는 x[%d]에 있습니다.\n", key, idx);
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	free(x);

	return 0;
}