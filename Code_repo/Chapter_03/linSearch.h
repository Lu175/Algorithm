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
		for (j = 0; j < i; j++) {    // *(���� �˻���) ǥ�� ���� ���� ���
			printf("   ");
		}
		printf("  *\n");    // *(���� �˻��� ��ġ) ���
		printf("%3d|", i);    // *(���� �˻��� ����) ���

		// �˻� ��Ұ��� ǥ�� (�迭 ǥ��)
		for (j = 0; j < n; j++) {
			printf("%3d", a[j]);
		}
		puts("");

		// test logic
		(*count)++;
		if (a[i] == key) { break; }    // �˻� success -> �˻��� ����� index ��ȯ
	}
	return (i == n) ? -1 : i;    // �˻��� index i�� sentinel�� index(�� ������ ���)�� �� -1�� ��ȯ -> �˻� fail
}
#endif //_LU175_LINEAR_SEARCH_PRINT_PROCESS