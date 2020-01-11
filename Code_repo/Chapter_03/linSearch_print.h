#pragma once
#ifndef _LU175_LINEAR_SEARCH_PRINT_PROCESS
#define _LU175_LINEAR_SEARCH_PRINT_PROCESS

int linSearch_print(int a[], int n, int key, int* ptr) {
	int i, j;
	int* count = ptr;
	a[n] = key;

// [Start] index ����
	printf("\n   |");
	for (i = 0; i < n; i++) {
		printf("%3d", i);
	}
	printf("\n---+");
	for (i = 0; i < n; i++) {
		printf("---");
	}
	puts("");
// [End] index ����

	for (i = 0; i <= n; i++) {
// [Start] test �κ� print
		printf("   |");
		for (j = 0; j < i; j++) { printf("   "); }    // *(���� �˻���) ǥ�� ���� ���� ���
		printf("  *\n");    // *(���� �˻��� ��ġ) ���
		printf("%3d|", i);    // ���� test index �� ���

		for (j = 0; j < n; j++) { printf("%3d", a[j]); }    // �˻� ��Ұ��� ǥ�� (�迭 ǥ��)
		puts("");
// [End] test �κ� print

// [Start] test logic
		(*count)++;
		if (a[i] == key) { break; }    // �˻� success -> �˻��� ����� index ��ȯ
// [END] test logic
	}
	return (i == n) ? -1 : i;    // �˻��� index i�� sentinel�� index(�� ������ ���)�� �� -1�� ��ȯ -> �˻� fail
}
#endif //_LU175_LINEAR_SEARCH_PRINT_PROCESS