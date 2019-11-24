// __________linear search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int linSearch(const int a[], int n, int key);

int main(void) {
	int i, nx, key, idx;
	int* x;

	puts("선형 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	puts("요소값을 입력하세요.");
	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	printf("검색값: ");
	scanf("%d", &key);
	idx = linSearch(x, nx, key);
	if (idx == -1) { puts("검색에 실패했습니다."); }
	else { printf("%d(은)는 x[%d]에 있습니다.\n", key, idx); }
	free(x);

	return 0;
}


int linSearch(const int a[], int n, int key) {
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] == key) { return i; }    // success -> 검색된 요소의 index 반환
	}
	return -1;    // fail
}