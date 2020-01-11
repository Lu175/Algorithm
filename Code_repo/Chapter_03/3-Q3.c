// __________linear search (sentinel method)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "search_idx.h"

int search_idx(const int a[], int n, int key, int target_idx[], int* ptr);

int main(void) {
	int i, nx, key, num_target;
	int* x, target_idx;
	int compCount = 0;

	puts("���� �˻� (���ʹ�)");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	target_idx = calloc(nx, sizeof(int));
	puts("��Ұ��� �Է��ϼ���.");
	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	printf("�˻���: ");
	scanf("%d", &key);
	puts("");

	num_target = search_idx(x, nx, key, target_idx, &compCount);    // search_idx

	if (num_target == -1) {
		puts("�˻��� �����߽��ϴ�.");
		printf("�˻� �������� �˻� ���: %dȸ\n", compCount);
	}
	else {
		printf("%d(��)�� %d�� �ֽ��ϴ�.\n", key, num_target);
		printf("�˻� �������� �˻� ���: %dȸ\n", compCount);
	}
	free(x);

	return 0;
}