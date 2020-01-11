// __________long type bsearch function (��������)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int long_cmp_r(const long* a, const long* b);

int main(void) {
	int i, nx, key;
	long* x;
	long* p;    // �˻��� ��ҿ� ���� ������

	puts("'long type bsearch' utility �Լ��� ����� �˻�");
	do {
		printf("��� ����: ");
		scanf("%d", &nx);
	} while (nx <= 0);
	x = calloc(nx, sizeof(long));
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
	p = bsearch(&key, x, nx, sizeof(long), (int(*)(const void*, const void*)) long_cmp_r);    // bsearch
	puts("");

	if (p == NULL) { puts("�˻��� �����߽��ϴ�."); }
	else { printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", key, (int)(p - x)); }
	free(x);

	return 0;
}

int long_cmp_r(const long* a, const long* b) {
	if (*a < *b) { return 1; }
	else if (*a > * b) { return -1; }
	else { return 0; }
	// �Ʒ��� ���� �ۼ��� �� �� �ִ�.
	// return (*a < *b) ? 1 : ((*a > *b) ? -1 : 0)
}