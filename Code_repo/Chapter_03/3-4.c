// __________binary search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "binSearch.h"

int binSearch(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("���� �˻�");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("\n������ %d�� ��ҵ�� ������ �迭�� ������������ �����մϴ�.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = rand() % 10;    // ù ���
	printf("%4d", x[0]);
	for (i = 1; i < nx; i++) {
		do {
			x[i] = rand() % (10 + 10 * i);    // index�� 1 �����ϸ� ���� ���� ������ 10 ����
		} while (x[i] < x[i - 1]);    // ���� ��Ұ����� ������ ���Է�
		printf("%4d", x[i]);
	}
	printf("\n\n�˻���: ");
	scanf("%d", &key);
	idx = binSearch(x, nx, key, &compCount);    // binSearch
	if (idx == -1) {
		puts("�˻��� �����߽��ϴ�.");
		printf("�˻� �������� �˻� ���: %dȸ", compCount);
	}
	else {
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", key, idx);
		printf("�˻� �������� �˻� ���: %dȸ\n", compCount);
	}
	free(x);

	return 0;
}