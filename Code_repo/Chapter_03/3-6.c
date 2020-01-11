// __________bsearch function (내림차순)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_cmp_r(const int* a, const int* b);

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
	printf("\n임의의 %d개 요소들로 구성된 배열을 내림차순으로 생성합니다.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = (rand() % 10) + (nx - 1) * 10;    // 첫 요소
	printf("%3d", x[0]);
	for (i = 1; i < nx; i++) {
		do {
			x[i] = (rand() % 10) + (nx - 1 - i) * 10;    // index가 1 증가하면 랜덤 숫자 범위도 10 감소
		} while (x[i] > x[i - 1]);    // 이전 요소값보다 크면 재입력
		printf("%3d", x[i]);
	}
	printf("\n\n검색값: ");
	scanf("%d", &key);
	p = bsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp_r);    // bsearch
	puts("");

	if (p == NULL) { puts("검색에 실패했습니다."); }
	else { printf("%d(은)는 x[%d]에 있습니다.\n", key, (int)(p - x)); }
	free(x);

	return 0;
}

int int_cmp_r(const int* a, const int* b) {
	if (*a < *b) { return 1; }
	else if (*a > * b) { return -1; }
	else { return 0; }
	// 아래와 같이 작성할 수 도 있다.
	// return (*a < *b) ? 1 : ((*a > *b) ? -1 : 0)
}