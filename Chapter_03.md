# 자료구조와 함께 배우는 알고리즘 입문 (C언어 편)
+ 2019.11.25.
+ Chapter 3 (pp. 95-113) // p. 128까지 봐야함
+ 2020.01.12.
+ Chapter 3 (pp. 113-128)
* * *
## Table of contents

* [p.113](#p113)
    - [Q1: linear search (sentinel method)](#q1)
    	+ [linSearch.h](#linsearchh)
    	+ [main.c](#mainc)
    - [Q2: linear search (sentinel method) 과정 출력하기](#q2)
    	+ [linSearch_print.h](#linsearch-printh)
    	+ [main.c](#mainc-1)
* [p.115](#p115)
    - [Q3: linear search (sentinel method)](#q3)
    	+ [search_idx.h](#search-idxh)
    	+ [main.c](#mainc-2)
    - [Q4: binary search](#q4)
    	+ [binSearch_print.h](#binsearch-printh)
    	+ [main.c](#mainc-3)
    - [Q5: binary search](#q5)
    	+ [binSearch2.h](#binsearch2h)
    	+ [main.c](#mainc-4)
* [p.128](#p128)
    - [Q6: long type bsearch function (내림차순)](#q6)
    - [Q7: seqsearch function](#q7)
    - [Q8: binsearch function](#q8)
    - [Q9: binsearch2 function](#q9)
* * *
## p.113
>#### Q1
#### linSearch.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/linSearch.h)
```C
#pragma once
#ifndef _LU175_LINEAR_SEARCH
#define _LU175_LINEAR_SEARCH

int linSearch(int a[], int n, int key, int* ptr) {
	int i;
	int* count = ptr;
	a[n] = key;
	for (i = 0; i <= n; i++) {
		(*count)++;
		if (a[i] == key) { break; }    // 검색 success -> 검색된 요소의 index 반환
	}
	return (i == n) ? -1 : i;    // 검색된 index i가 sentinel의 index(맨 마지막 요소)일 때 -1을 반환 -> 검색 fail
}
#endif //_LU175_LINEAR_SEARCH
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q1.c)
```C
// __________linear search (sentinel method)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linSearch.h"

int linSearch(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("선형 검색 (보초법)");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));
	puts("요소값을 입력하세요.");
	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	printf("검색값: ");
	scanf("%d", &key);
	idx = linSearch(x, nx, key, &compCount);    // linSearch
	if (idx == -1) {
		puts("검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	else {
		printf("%d(은)는 x[%d]에 있습니다.\n", key, idx);
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	free(x);

	return 0;
}
```
>#### Q2
#### linSearch_print.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/linSearch_print.h)
```C
#pragma once
#ifndef _LU175_LINEAR_SEARCH_PRINT_PROCESS
#define _LU175_LINEAR_SEARCH_PRINT_PROCESS

int linSearch_print(int a[], int n, int key, int* ptr) {
	int i, j;
	int* count = ptr;
	a[n] = key;

// [Start] index 나열
	printf("\n   |");
	for (i = 0; i < n; i++) {
		printf("%3d", i);
	}
	printf("\n---+");
	for (i = 0; i < n; i++) {
		printf("---");
	}
	puts("");
// [End] index 나열

	for (i = 0; i <= n; i++) {
// [Start] test 부분 print
		printf("   |");
		for (j = 0; j < i; j++) { printf("   "); }    // *(현재 검사요소) 표시 왼쪽 공백 출력
		printf("  *\n");    // *(현재 검사요소 위치) 출력
		printf("%3d|", i);    // 현재 test index 값 출력

		for (j = 0; j < n; j++) { printf("%3d", a[j]); }    // 검사 요소값들 표시 (배열 표시)
		puts("");
// [End] test 부분 print

// [Start] test logic
		(*count)++;
		if (a[i] == key) { break; }    // 검색 success -> 검색된 요소의 index 반환
// [END] test logic
	}
	return (i == n) ? -1 : i;    // 검색된 index i가 sentinel의 index(맨 마지막 요소)일 때 -1을 반환 -> 검색 fail
}
#endif //_LU175_LINEAR_SEARCH_PRINT_PROCESS
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q2.c)
```C
// __________linear search (sentinel method) 과정 출력하기__________
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

	puts("선형 검색 (보초법)");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));
	printf("\n임의의 %d개 요소들로 구성된 배열을 생성합니다.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % 100;
		printf("%3d", x[i]);
	}
	printf("\n\n검색값: ");
	scanf("%d", &key);
	idx = linSearch_print(x, nx, key, &compCount);    // linSearch_print
	if (idx == -1) {
		puts("\n검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	else {
		printf("\n%d(은)는 x[%d]에 있습니다.\n", key, idx);
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	free(x);

	return 0;
}
```
## p.115
>#### Q3
#### search_idx.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/search_idx.h)
```C
#pragma once
#ifndef _LU175_SEARCH_IDX
#define _LU175_SEARCH_IDX

int search_idx(const int a[], int n, int key, int target_idx[], int* ptr) {
	int i, j, k, num_target;
	int* idx_buffer;
	int count_idx = 0;
	int* count = ptr;

	idx_buffer = calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		(*count)++;
		if (a[i] == key) {
			idx_buffer[i] = 1;
		}
		else {
			idx_buffer[i] = 0;
		}
	}
	for (j = 0; j < n; j++) {
		if (idx_buffer[j] == 1) {
			target_idx[count_idx] = idx_buffer[j];
			count_idx++;
		}
	}
	for (k = 0; k < n; k++) {
		if (target_idx[k] == 0) {
			break;
		}
	}
	free(idx_buffer);
	num_target = k;
	return (num_target == 0) ? -1 : num_target;    // target이 없으면 -> 검색 fail
}
#endif //_LU175_SEARCH_IDX
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q3.c)
```C
// __________linear search (sentinel method)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "search_idx.h"

int search_idx(const int a[], int n, int key, int target_idx[], int* ptr);

int main(void) {
	int i, nx, key, num_target;
	int* x, target_idx;
	int compCount = 0;

	puts("선형 검색 (보초법)");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	target_idx = calloc(nx, sizeof(int));
	puts("요소값을 입력하세요.");
	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	printf("검색값: ");
	scanf("%d", &key);
	puts("");

	num_target = search_idx(x, nx, key, target_idx, &compCount);    // search_idx

	if (num_target == -1) {
		puts("검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	else {
		printf("%d(은)는 %d개 있습니다.\n", key, num_target);
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	free(x);

	return 0;
}
```
>#### Q4
#### binSearch_print.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/binSearch_print.h)
```C
#pragma once
#ifndef _LU175_BINARY_SEARCH_PRINT_PROCESS
#define _LU175_BINARY_SEARCH_PRINT_PROCESS

int binSearch_print(const int a[], int n, int key, int* ptr) {
	int i;
	int edgeFlag = 0;
	int pl = 0;
	int pr = n -1;
	int pc;
	int* count = ptr;

// [Start] index 나열
	printf("\n    |");
	for (i = 0; i < n; i++) {
		printf("%4d", i);
	}
	printf("\n----+");
	for (i = 0; i < n; i++) {
		printf("----");
	}
	puts("");
// [End] index 나열

// [Start] test 부분 print
	do {
		//edgeFlag = 0;    // Reset edgeFlag
		pc = (pl + pr) / 2;
		// <- : 검색 범위 lower limit    // pl
		//  + : 검색 범위 center         // pc
		// -> : 검색 범위 upper limit    // pr
		if (pr - pl > 1) {    // pc가 검색 범위의 중간에 있다면
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <- ");    // pl 출력
			for (i = 0; i < pc - pl - 1; i++) { printf("    "); }    // pl과 pc 사이의 공백 출력
			printf("  + ");    // pc 출력
			for (i = 0; i < pr - pc - 1; i++) { printf("    "); }    // pc과 pr 사이의 공백 출력
			printf("  ->\n");    // pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
		}
		else if (pc == pl) {    // pc가 검색 범위의 왼쪽 끝(pl)에 있다면
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <-+");    // pl, pc 출력
			printf("  ->\n");    // pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
			if (a[pc] < key) { edgeFlag = 1; }    // key가 검색 범위의 왼쪽 두번째 요소라면 -> Special case
		}
		else {    // pc가 검색 범위의 오른쪽 끝(pr)에 있다면
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <- ");    // pl 출력
			printf(" +->\n");    // pc, pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
			if (a[pc] > key) { edgeFlag = 2; }    // key가 검색 범위의 오른쪽 두번째 요소라면 -> Special case
		}

		for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // 검사 요소값들 표시 (배열 표시)
		puts("");

// [Start] Special case
		if (edgeFlag == 1) {
			pc += 1;
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <- ");    // pl 출력
			printf(" +->\n");    // pc, pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
			for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // 검사 요소값들 표시 (배열 표시)
			puts("");
		}
		if (edgeFlag == 2) {
			pc += 1;
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <-+");    // pl, pc 출력
			printf("  ->\n");    // pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
			for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // 검사 요소값들 표시 (배열 표시)
			puts("");
		}
// [End] Special case

// [Start] test logic
		if ((*count)++, (a[pc] == key)) { return pc; }    // 검색 success
		else if ((*count)++, (a[pc] < key)) { pl = pc +1; }    // 검색 범위의 왼쪽 limit 줄이기
		else { pr = pc -1; }    // 검색 범위의 오른쪽 limit 줄이기
// [END] test logic

		if (edgeFlag != 0) { break; };
	} while (pl <= pr);
// [End] test 부분 print

	return -1;    // 검색 fail
}
#endif //_LU175_BINARY_SEARCH_PRINT_PROCESS
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q4.c)
```C
// __________binary search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "binSearch_print.h"

int binSearch_print(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("이진 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("\n임의의 %d개 요소들로 구성된 배열을 오름차순으로 생성합니다.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = rand() % 10;    // 첫 요소
	printf("%4d", x[0]);
	for (i = 1; i < nx; i++) {
		do {
			x[i] = rand() % (10 + 10 * i);    // index가 1 증가하면 랜덤 숫자 범위도 10 증가
		} while (x[i] < x[i - 1]);    // 이전 요소값보다 작으면 재입력
		printf("%4d", x[i]);
	}
	printf("\n\n검색값: ");
	scanf("%d", &key);
	idx = binSearch_print(x, nx, key, &compCount);    // binSearch_print
	if (idx == -1) {
		puts("검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회", compCount);
	}
	else {
		printf("%d(은)는 x[%d]에 있습니다.\n", key, idx);
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	free(x);

	return 0;
}
```
>#### Q5
#### binSearch2.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/binSearch2.h)
```C
#pragma once
#ifndef _LU175_BINARY_SEARCH2
#define _LU175_BINARY_SEARCH2

int binSearch2(const int a[], int n, int key, int* ptr) {
	int pl = 0;
	int pr = n - 1;
	int pc, pc_shift;
	int shift = 0;
	int* count = ptr;

	do {
		pc = (pl + pr) / 2;
		if ((*count)++, (a[pc] == key)) {    // 검색 success
// [Start] 왼쪽의 같은 요소값 검색
			while (1) {
				pc_shift = pc - ++shift;    // pc를 왼쪽으로 이동
				if (a[pc_shift] != key) { return pc; }
				pc = pc_shift;
			}
// [End] 왼쪽의 같은 요소값 검색
		}
		else if ((*count)++, (a[pc] < key)) { pl = pc + 1; }    // 검색 범위의 왼쪽 limit 줄이기
		else { pr = pc - 1; }    // 검색 범위의 오른쪽 limit 줄이기
	} while (pl <= pr);
	return -1;    // 검색 fail
}
#endif //_LU175_BINARY_SEARCH2
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q5.c)
```C
// __________binary search__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "binSearch2.h"

int binSearch2(const int a[], int n, int key, int* ptr);

int main(void) {
	int i, nx, key, idx;
	int* x;
	int compCount = 0;

	puts("이진 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("\n임의의 %d개 요소들로 구성된 배열을 오름차순으로 생성합니다.\n", nx);
	printf("Random array x[%d] : ", nx);
	srand(time(NULL));
	x[0] = rand() % 10;    // 첫 요소
	printf("%4d", x[0]);
	for (i = 1; i < nx; i++) {
		do {
			x[i] = rand() % (5 + 2 * i);    // index가 1 증가하면 랜덤 숫자 범위도 2 증가
		} while (x[i] < x[i - 1]);    // 이전 요소값보다 작으면 재입력
		printf("%4d", x[i]);
	}
	printf("\n\n검색값: ");
	scanf("%d", &key);
	idx = binSearch2(x, nx, key, &compCount);    // binSearch2
	puts("");

	if (idx == -1) {
		puts("검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회", compCount);
	}
	else {
		printf("%d(은)는 x[%d]에 있습니다.\n", key, idx);
		printf("검색 종료조건 검사 비용: %d회\n", compCount);
	}
	free(x);

	return 0;
}
```
## p.128
>#### Q6
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q6.c)
```C
// __________long type bsearch function (내림차순)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int long_cmp_r(const long* a, const long* b);

int main(void) {
	int i, nx, key;
	long* x;
	long* p;    // 검색한 요소에 대한 포인터

	puts("'long type bsearch' utility 함수를 사용한 검색");
	do {
		printf("요소 개수: ");
		scanf("%d", &nx);
	} while (nx <= 0);
	x = calloc(nx, sizeof(long));
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
	p = bsearch(&key, x, nx, sizeof(long), (int(*)(const void*, const void*)) long_cmp_r);    // bsearch
	puts("");

	if (p == NULL) { puts("검색에 실패했습니다."); }
	else { printf("%d(은)는 x[%d]에 있습니다.\n", key, (int)(p - x)); }
	free(x);

	return 0;
}

int long_cmp_r(const long* a, const long* b) {
	if (*a < *b) { return 1; }
	else if (*a > * b) { return -1; }
	else { return 0; }
	// 아래와 같이 작성할 수 도 있다.
	// return (*a < *b) ? 1 : ((*a > *b) ? -1 : 0)
}
```
>#### Q7
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q7.c)
```C
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
```
>#### Q8
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q8.c)
```C
// __________binsearch function__________
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
			x[i] = rand() % (10 + 5 * i);    // index가 1 증가하면 랜덤 숫자 범위도 5 증가
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
	int pc, pc_cmpFlag;

	int ta_addr = base;    // Test array address
	int* ti_p;    // Test index pointer

	do {
		pc = (pl + pr) / 2;
		ti_p = ta_addr + pc * size;
		pc_cmpFlag = compar(key, (const void*)ti_p);
		if (pc_cmpFlag == 0) { return ti_p; }    // 검색 success
		else if (pc_cmpFlag == 1) { pl = pc + 1; }    // 검색 범위의 왼쪽 limit 줄이기
		else { pr = pc - 1; }    // 검색 범위의 오른쪽 limit 줄이기
	} while (pl <= pr);
	return NULL;    // 검색 fail
}
```
>#### Q9
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_03/3-Q9.c)
```C
// __________binsearch2 function__________
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
```
