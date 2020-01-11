// __________own bsearch function__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
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
	printf("\n임의의 %d개 요소들로 구성된 배열을 오름차순으로 생성합니다.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = rand() % 10;    // 첫 요소
	printf("%3d", x[0]);
	for (i = 1; i < nx; i++) {
		do {
			x[i] = rand() % (10 + 2 * i);    // index가 1 증가하면 랜덤 숫자 범위도 2 증가
		} while (x[i] < x[i - 1]);    // 이전 요소값보다 작으면 재입력
		printf("%3d", x[i]);
	}
	printf("\n\n검색값: ");
	scanf("%d", &key);
	p = binsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);    // binsearch
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

void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*)) {
	int pl = 0;
	int pr = nmemb - 1;
	int pc, pc_shift, pc_cmpFlag;
	int shift = 0;

	int ta_addr = base;    // Test array address
	int* ti_p;    // Test index pointer
	int* ti_p_shift;    // Test index pointer

	do {
		pc = (pl + pr) / 2;
		ti_p = ta_addr + pc * size;
		pc_cmpFlag = compar(key, (const void*)ti_p);
		if (pc_cmpFlag == 0) {    // 검색 success
// [Start] 왼쪽의 같은 요소값 검색
			while (1) {
				pc_shift = pc - ++shift;    // pc를 왼쪽으로 이동
				ti_p_shift = ta_addr + pc_shift * size;
				pc_cmpFlag = compar(key, (const void*)ti_p_shift);
				if (pc_cmpFlag != 0) { return ti_p; }

				ti_p = ti_p_shift;
			}
			// [End] 왼쪽의 같은 요소값 검색
		}
		else if (pc_cmpFlag == 1) { pl = pc + 1; }    // 검색 범위의 왼쪽 limit 줄이기
		else { pr = pc - 1; }    // 검색 범위의 오른쪽 limit 줄이기
	} while (pl <= pr);
	return NULL;    // 검색 fail
}