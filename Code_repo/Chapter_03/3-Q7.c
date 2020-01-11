// __________seqsearch function__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
int int_cmp(const int* a, const int* b);

int main(void) {
	int i, nx, key;
	int* x;
	int* p;    // 검색한 요소에 대한 포인터

	puts("'bsearch' utility 함수를 사용한 검색");
	do {
		printf("요소 개수: ");
		scanf("%d", &nx);
	} while (nx <= 0);
	x = calloc(nx, sizeof(int));
	printf("\n임의의 %d개 요소들로 구성된 배열을 생성합니다.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = rand() % 100;    // 첫 요소
	printf("%3d", x[0]);
	for (i = 1; i < nx; i++) {
		x[i] = rand() % 100;
		printf("%3d", x[i]);
	}
	printf("\n\n검색값: ");
	scanf("%d", &key);
	p = seqsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);    // seqsearch
	puts("");

	if (p == NULL) { puts("검색에 실패했습니다."); }
	else { printf("%d(은)는 x[%d]에 있습니다.\n", key, (int)(p - x)); }
	free(x);

	return 0;
}

int int_cmp(const int* a, const int* b) {
	if (*a < *b) { return -1; }
	else if (*a > * b) { return 1; }
	else { return 0; }
	// 아래와 같이 작성할 수 도 있다.
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