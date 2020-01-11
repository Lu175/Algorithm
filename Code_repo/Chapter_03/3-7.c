// __________구조체 배열에서 bsearch 사용__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
} Person;

int npcmp(const Person* x, const Person* y);

int main(void) {
	Person x[] = {    // 배열의 요소는 오름차순으로 정렬되어 있어야한다.
		{"김영준", 179, 79},
		{"박현규", 172, 63},
		{"이수진", 176, 52},
		{"최윤미", 165, 51},
		{"함진아", 181, 73},
		{"홍연의", 172, 84}
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int retry;
	puts("이름으로 검색합니다.");
	do {
		Person temp, * p;
		printf("이름: ");
		scanf("%s", &temp.name);
		p = bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void*, const void*)) npcmp);
		if (p == NULL) { puts("검색에 실패했습니다."); }
		else {
			puts("검색 성공!! 아래의 요소를 찾았습니다.");
			printf("x[%d] : %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);
		}
		printf("다시 검색할까요? (1)예 /(0)아니오 : ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}

int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}