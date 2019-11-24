#pragma once
#ifndef _LU175_LINEAR_SEARCH_PRINT_PROCESS
#define _LU175_LINEAR_SEARCH_PRINT_PROCESS

int linSearch(int a[], int n, int key, int* ptr) {
	int i, j;
	int* count = ptr;
	a[n] = key;

	printf("\n   |");
	for (i = 0; i < n; i++) {
		printf("%3d", i);
	}
	printf("\n---+");
	for (i = 0; i < n; i++) {
		printf("---");
	}
	puts("");

	for (i = 0; i <= n; i++) {
		printf("   |");
		for (j = 0; j < i; j++) {    // *(현재 검사요소) 표시 왼쪽 공백 출력
			printf("   ");
		}
		printf("  *\n");    // *(현재 검사요소 위치) 출력
		printf("%3d|", i);    // *(현재 검사요소 숫자) 출력

		// 검사 요소값들 표시 (배열 표시)
		for (j = 0; j < n; j++) {
			printf("%3d", a[j]);
		}
		puts("");

		// test logic
		(*count)++;
		if (a[i] == key) { break; }    // 검색 success -> 검색된 요소의 index 반환
	}
	return (i == n) ? -1 : i;    // 검색된 index i가 sentinel의 index(맨 마지막 요소)일 때 -1을 반환 -> 검색 fail
}
#endif //_LU175_LINEAR_SEARCH_PRINT_PROCESS