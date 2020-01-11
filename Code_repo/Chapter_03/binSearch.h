#pragma once
#ifndef _LU175_BINARY_SEARCH
#define _LU175_BINARY_SEARCH

int binSearch(const int a[], int n, int key, int* ptr) {
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
#endif //_LU175_BINARY_SEARCH