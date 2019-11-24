// __________binary search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binSearch(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("이진 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	puts("요소값을 오름차순으로 입력하세요.");
	printf("x[0]: ");
	scanf("%d", &(x[0]));
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d]: ", i);
			scanf("%d", &(x[i]));
		} while (x[i] < x[i - 1]);    // 이전 요소값보다 작으면 재입력
	}
	printf("검색값: ");
	scanf("%d", &key);
	idx = binSearch(x, nx, key, &compCount);
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


int binSearch(int a[], int n, int key, int* ptr) {
	int pl = 0;
	int pr = n - 1;
	int pc;
	int* count = ptr;

	do {
		pc = (pl + pr) / 2;
		if ((*count)++, (a[pc] == key)) { return pc; }    // 검색 success
		else if ((*count)++, (a[pc] < key)) { pl = pc + 1; }    // 검색 범위의 왼쪽 limit 줄이기
		else { pr = pc - 1; }    // 검색 범위의 오른쪽 limit 줄이기
	} while (pl <= pr);
	return -1;    // 검색 fail
}