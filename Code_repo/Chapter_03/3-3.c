// __________linear search (sentinel method)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int linSearch(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("선형 검색 (보초법)");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));
	puts("요소값을 입력하세요.");
	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	printf("검색값: ");
	scanf("%d", &key);
	idx = linSearch(x, nx, key, &compCount);
	if (idx == -1) {
		puts("검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회", compCount);
	}
	else {
		printf("%d(은)는 x[%d]에 있습니다.\n", key, idx);
		printf("검색 종료조건 검사 비용: %d회", compCount);
	}
	free(x);

	return 0;
}


int linSearch(int a[], int n, int key, int* ptr) {
	int i = 0;
	int* count = ptr;
	a[n] = key;
	while (1) {
		(*count)++;
		if (a[i] == key) { break; }    // 검색 success -> 검색된 요소의 index 반환
		i++;
	}
	return (i == n) ? -1 : i;    // 검색된 index i가 sentinel의 index(맨 마지막 요소)일 때 -1을 반환 -> 검색 fail
}