// __________bsearch function (��������)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_cmp_r(const int* a, const int* b);

int main(void) {
	int i, nx, key;
	int* x;
	int* p;    // �˻��� ��ҿ� ���� ������

	puts("'bsearch' utility �Լ��� ����� �˻�");
	do {
		printf("��� ����: ");
		scanf("%d", &nx);
	} while (nx <= 0);
	x = calloc(nx, sizeof(int));
	printf("\n������ %d�� ��ҵ�� ������ �迭�� ������������ �����մϴ�.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = (rand() % 10) + (nx - 1) * 10;    // ù ���
	printf("%3d", x[0]);
	for (i = 1; i < nx; i++) {
		do {
			x[i] = (rand() % 10) + (nx - 1 - i) * 10;    // index�� 1 �����ϸ� ���� ���� ������ 10 ����
		} while (x[i] > x[i - 1]);    // ���� ��Ұ����� ũ�� ���Է�
		printf("%3d", x[i]);
	}
	printf("\n\n�˻���: ");
	scanf("%d", &key);
	p = bsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp_r);    // bsearch
	puts("");

	if (p == NULL) { puts("�˻��� �����߽��ϴ�."); }
	else { printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", key, (int)(p - x)); }
	free(x);

	return 0;
}

int int_cmp_r(const int* a, const int* b) {
	if (*a < *b) { return 1; }
	else if (*a > * b) { return -1; }
	else { return 0; }
	// �Ʒ��� ���� �ۼ��� �� �� �ִ�.
	// return (*a < *b) ? 1 : ((*a > *b) ? -1 : 0)
}