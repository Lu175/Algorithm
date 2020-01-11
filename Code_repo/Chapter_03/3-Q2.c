// __________linear search (sentinel method) ���� ����ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "linSearch_print.h"

int linSearch_print(int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("���� �˻� (���ʹ�)");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));
	printf("\n������ %d�� ��ҵ�� ������ �迭�� �����մϴ�.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % 100;
		printf("%3d", x[i]);
	}
	printf("\n\n�˻���: ");
	scanf("%d", &key);
	idx = linSearch_print(x, nx, key, &compCount);    // linSearch_print
	if (idx == -1) {
		puts("\n�˻��� �����߽��ϴ�.");
		printf("�˻� �������� �˻� ���: %dȸ\n", compCount);
	}
	else {
		printf("\n%d(��)�� x[%d]�� �ֽ��ϴ�.\n", key, idx);
		printf("�˻� �������� �˻� ���: %dȸ\n", compCount);
	}
	free(x);

	return 0;
}