#pragma once
#ifndef _LU175_LINEAR_SEARCH
#define _LU175_LINEAR_SEARCH

int linSearch(int a[], int n, int key, int* ptr) {
	int i;
	int* count = ptr;
	a[n] = key;
	for (i = 0; i <= n; i++) {
		(*count)++;
		if (a[i] == key) { break; }    // 검색 success -> 검색된 요소의 index 반환
	}
	return (i == n) ? -1 : i;    // 검색된 index i가 sentinel의 index(맨 마지막 요소)일 때 -1을 반환 -> 검색 fail
}
#endif //_LU175_LINEAR_SEARCH