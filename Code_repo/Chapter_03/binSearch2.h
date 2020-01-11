#pragma once
#ifndef _LU175_BINARY_SEARCH2
#define _LU175_BINARY_SEARCH2

int binSearch2(const int a[], int n, int key, int* ptr) {
	int pl = 0;
	int pr = n - 1;
	int pc, pc_shift;
	int shift = 0;
	int* count = ptr;

	do {
		pc = (pl + pr) / 2;
		if ((*count)++, (a[pc] == key)) {    // 검색 success
// [Start] 왼쪽의 같은 요소값 검색
			while (1) {
				pc_shift = pc - ++shift;    // pc를 왼쪽으로 이동
				if (a[pc_shift] != key) { return pc; }
				pc = pc_shift;
			}
// [End] 왼쪽의 같은 요소값 검색
		}
		else if ((*count)++, (a[pc] < key)) { pl = pc + 1; }    // 검색 범위의 왼쪽 limit 줄이기
		else { pr = pc - 1; }    // 검색 범위의 오른쪽 limit 줄이기
	} while (pl <= pr);
	return -1;    // 검색 fail
}
#endif //_LU175_BINARY_SEARCH2