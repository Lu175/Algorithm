// __________binary search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binSearch(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("���� �˻�");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	puts("��Ұ��� ������������ �Է��ϼ���.");
	printf("x[0]: ");
	scanf("%d", &(x[0]));
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d]: ", i);
			scanf("%d", &(x[i]));
		} while (x[i] < x[i - 1]);    // ���� ��Ұ����� ������ ���Է�
	}
	printf("�˻���: ");
	scanf("%d", &key);
	idx = binSearch(x, nx, key, &compCount);
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


int binSearch(int a[], int n, int key, int* ptr) {
	int pl = 0;
	int pr = n - 1;
	int pc;
	int* count = ptr;

	do {
		pc = (pl + pr) / 2;
		if ((*count)++, (a[pc] == key)) { return pc; }    // �˻� success
		else if ((*count)++, (a[pc] < key)) { pl = pc + 1; }    // �˻� ������ ���� limit ���̱�
		else { pr = pc - 1; }    // �˻� ������ ������ limit ���̱�
	} while (pl <= pr);
	return -1;    // �˻� fail
}