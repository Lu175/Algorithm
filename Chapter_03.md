# 자료구조와 함께 배우는 알고리즘 입문 (C언어 편)
+ 2019.11.25.
+ Chapter 3 (pp. 95-113) // p. 128까지 

* * *
## Table of contents

* [p.113](#113)
    - [Q1: linear search (sentinel method)](#q1)
    - [Q2: linear search (sentinel method) 과정 출력하기](#q2)
        + [linSearch.h](#linsearchh)
        + [main.c](#mainc)
* * *
## p.113
>#### Q1
```C
// __________linear search (sentinel method)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	idx = linSearch(x, nx, key, &compCount);
	if (idx == -1) {
		puts("검색에 실패했습니다.");
		printf("검색 종료조건 검사 비용: %d회", compCount);
	}
	else {
		printf("%d(은)는 x[%d]에 있습니다.\n", key, idx);
		printf("검색 종료조건 검사 비용: %d회", compCount);
	}
	free(x);

	return 0;
}


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
```
>#### Q2
#### linSearch.h
```C
#pragma once
#ifndef _LU175_LINEAR_SEARCH_PRINT_PROCESS
#define _LU175_LINEAR_SEARCH_PRINT_PROCESS

int linSearch(int a[], int n, int key, int* ptr) {
	int i, j;
	int* count = ptr;
	a[n] = key;

	printf("\n   |");
	for (i = 0; i < n; i++) {
		printf("%3d", i);
	}
	printf("\n---+");
	for (i = 0; i < n; i++) {
		printf("---");
	}
	puts("");

	for (i = 0; i <= n; i++) {
		printf("   |");
		for (j = 0; j < i; j++) {    // *(현재 검사요소) 표시 왼쪽 공백 출력
			printf("   ");
		}
		printf("  *\n");    // *(현재 검사요소 위치) 출력
		printf("%3d|", i);    // *(현재 검사요소 숫자) 출력

		// 검사 요소값들 표시 (배열 표시)
		for (j = 0; j < n; j++) {
			printf("%3d", a[j]);
		}
		puts("");

		// test logic
		(*count)++;
		if (a[i] == key) { break; }    // 검색 success -> 검색된 요소의 index 반환
	}
	return (i == n) ? -1 : i;    // 검색된 index i가 sentinel의 index(맨 마지막 요소)일 때 -1을 반환 -> 검색 fail
}
#endif //_LU175_LINEAR_SEARCH_PRINT_PROCESS
```
#### main.c
```C
// __________linear search (sentinel method) 과정 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "linSearch.h"

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
	idx = linSearch(x, nx, key, &compCount);
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
