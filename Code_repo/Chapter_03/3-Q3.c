// __________linear search (sentinel method)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "search_idx.h"

int search_idx(const int a[], int n, int key, int target_idx[], int* ptr);

int main(void) {
	int i, nx, key, num_target;
	int* x, target_idx;
	int compCount = 0;

	puts("선형 검색 (보초법)");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	target_idx = calloc(nx, sizeof(int));
	puts("요소값을 입력하세요.");
	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	printf("검색값: ");
	scanf("%d", &key);
	puts("");

	num_target = search_idx(x, nx, key, target_idx, &compCount);    // search_idx

	if (num_target == -1) {
		puts("검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	else {
		printf("%d(은)는 %d개 있습니다.\n", key, num_target);
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	free(x);

	return 0;
}