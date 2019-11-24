// __________linear search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int linSearch(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

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
	idx = linSearch(x, nx, key, &compCount);
	if (idx == -1) {
		puts("�˻��� �����߽��ϴ�.");
		printf("�˻� �������� �˻� ���: %dȸ", compCount);
	}
	else {
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", key, idx);
		printf("�˻� �������� �˻� ���: %dȸ", compCount);
	}
	free(x);

	return 0;
}


int linSearch(const int a[], int n, int key, int* ptr) {
	int i = 0;
	int* count = ptr;
	while (1) {
		(*count)++;
		if (i == n) { return -1; }    // fail
		(*count)++;
		if (a[i] == key) { return i; }    // success -> �˻��� ����� index ��ȯ
		i++;
	}
}