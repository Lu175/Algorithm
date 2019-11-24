// __________linear search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int linSearch(const int a[], int n, int key);

int main(void) {
	int i, nx, key, idx;
	int* x;

	puts("���� �˻�");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	puts("��Ұ��� �Է��ϼ���.");
	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	printf("�˻���: ");
	scanf("%d", &key);
	idx = linSearch(x, nx, key);
	if (idx == -1) { puts("�˻��� �����߽��ϴ�."); }
	else { printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", key, idx); }
	free(x);

	return 0;
}


int linSearch(const int a[], int n, int key) {
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] == key) { return i; }    // success -> �˻��� ����� index ��ȯ
	}
	return -1;    // fail
}