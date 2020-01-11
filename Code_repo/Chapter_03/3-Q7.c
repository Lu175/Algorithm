// __________seqsearch function__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
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
	printf("\n������ %d�� ��ҵ�� ������ �迭�� �����մϴ�.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = rand() % 100;    // ù ���
	printf("%3d", x[0]);
	for (i = 1; i < nx; i++) {
		x[i] = rand() % 100;
		printf("%3d", x[i]);
	}
	printf("\n\n�˻���: ");
	scanf("%d", &key);
	p = seqsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);    // seqsearch
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

void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*)) {
	size_t ti;    // Test index
	int ta_addr = base;    // Test array address
	int* ti_p;    // Test index pointer
	for (ti = 0; ti < nmemb; ti++) {
		ti_p = ta_addr + ti * size;
		if (!compar(key, (const void*)ti_p)) {
			return ti_p;
		}
	}
	return NULL;
}