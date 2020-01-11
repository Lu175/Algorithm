#pragma once
#ifndef _LU175_LINEAR_SEARCH
#define _LU175_LINEAR_SEARCH

int linSearch(int a[], int n, int key, int* ptr) {
	int i;
	int* count = ptr;
	a[n] = key;
	for (i = 0; i <= n; i++) {
		(*count)++;
		if (a[i] == key) { break; }    // �˻� success -> �˻��� ����� index ��ȯ
	}
	return (i == n) ? -1 : i;    // �˻��� index i�� sentinel�� index(�� ������ ���)�� �� -1�� ��ȯ -> �˻� fail
}
#endif //_LU175_LINEAR_SEARCH