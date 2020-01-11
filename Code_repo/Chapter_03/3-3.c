// __________linear search (sentinel method)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linSearch.h"

int linSearch(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("���� �˻� (���ʹ�)");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));
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