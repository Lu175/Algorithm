// __________binsearch function__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
int int_cmp(const int* a, const int* b);

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
	x[0] = rand() % 10;    // ù ���
	printf("%3d", x[0]);
	for (i = 1; i < nx; i++) {
		do {
			x[i] = rand() % (10 + 5 * i);    // index�� 1 �����ϸ� ���� ���� ������ 5 ����
		} while (x[i] < x[i - 1]);    // ���� ��Ұ����� ������ ���Է�
		printf("%3d", x[i]);
	}
	printf("\n\n�˻���: ");
	scanf("%d", &key);
	p = binsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);    // binsearch
	puts("");

	if (p == NULL) { puts("�˻��� �����߽��ϴ�."); }
	else { printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", key, (int)(p - x)); }
	free(x);

	return 0;
}

int int_cmp(const int* a, const int* b) {
	if (*a < *b) { return -1; }
	else if (*a > * b) { return 1; }
	else { return 0; }
	// �Ʒ��� ���� �ۼ��� �� �� �ִ�.
	// return (*a < *b) ? -1 : ((*a > *b) ? 1 : 0)
}

void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*)) {
	int pl = 0;
	int pr = nmemb - 1;
	int pc, pc_cmpFlag;

	int ta_addr = base;    // Test array address
	int* ti_p;    // Test index pointer

	do {
		pc = (pl + pr) / 2;
		ti_p = ta_addr + pc * size;
		pc_cmpFlag = compar(key, (const void*)ti_p);
		if (pc_cmpFlag == 0) { return ti_p; }    // �˻� success
		else if (pc_cmpFlag == 1) { pl = pc + 1; }    // �˻� ������ ���� limit ���̱�
		else { pr = pc - 1; }    // �˻� ������ ������ limit ���̱�
	} while (pl <= pr);
	return NULL;    // �˻� fail
}