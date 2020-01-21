// __________IntStack2 : 배열 하나를 공유하는 2개의 stack__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack2.h"

int Initialize(IntStack2 *s, int max) {    // Stack 초기화
	s->A_ptr = 0;
	s->B_ptr = 0;
	if((s->stk = calloc(max, sizeof(int))) == NULL) {    // Stack의 메모리 공간 할당
		s->max = 0;    // 공간 할당이 안되면 배열 생성 실패    // 존재하지 않는 배열 stk에 접근을 막기위해서 0 대입
		return -1;
	}
	s->max = max;    // 공간 할당이 되면 배열 생성 성공
	return 0;
}

int A_Push(IntStack2 *s, int x) {    // Stack A에 data를 push
	if(s->A_ptr >= (s->max - s->B_ptr)) { return -1; }    // Stack A가 가득 참
	s->stk[(s->A_ptr)++] = x;    // Top 위에 data 쌓기
	return 0;
}
int B_Push(IntStack2 *s, int x) {    // Stack B에 data를 push
	if(s->B_ptr >= (s->max - s->A_ptr)) { return -1; }    // Stack B가 가득 참
	s->stk[(s->max - (s->B_ptr)++) -1] = x;    // Top 위에 data 쌓기
	return 0;
}

int A_Pop(IntStack2 *s, int *x) {    // Stack A에서 data를 pop
	if(s->A_ptr <= 0) { return -1; }    // Stack A가 비어있음
	*x = s->stk[--(s->A_ptr)];    // Top 요소값을 포인터 x에 저장
	return 0;
}
int B_Pop(IntStack2 *s, int *x) {    // Stack B에서 data를 pop
	if(s->B_ptr <= 0) { return -1; }    // Stack B가 비어있음
	*x = s->stk[s->max - --(s->B_ptr)];    // Top 요소값을 포인터 x에 저장
	return 0;
}

int A_Peek(const IntStack2 *s, int *x) {    // Stack A에서 data를 peek
	if(s->A_ptr <= 0) { return -1; }    // Stack A가 비어있음
	*x = s->stk[s->A_ptr - 1];    // Top에 무엇이 있는지 확인
	return 0;
}
int B_Peek(const IntStack2 *s, int *x) {    // Stack B에서 data를 peek
	if(s->B_ptr <= 0) { return -1; }    // Stack B가 비어있음
	*x = s->stk[s->max - s->B_ptr];    // Top에 무엇이 있는지 확인
	return 0;
}

void A_Clear(IntStack2 *s) {    // Stack A 비우기
	s->A_ptr = 0;
}
void B_Clear(IntStack2 *s) {    // Stack B 비우기
	s->B_ptr = 0;
}

int Capacity(const IntStack2 *s) {    // Stack의 최대 용량
	return s->max;
}

int A_Size(const IntStack2 *s) {    // Stack의 data 개수
	return s->A_ptr;
}
int B_Size(const IntStack2 *s) {    // Stack의 data 개수
	return s->B_ptr;
}

int A_IsEmpty(const IntStack2 *s) {    // Stack A가 비어있는가?
	return s->A_ptr <= 0;
}
int B_IsEmpty(const IntStack2 *s) {    // Stack B가 비어있는가?
	return s->B_ptr <= 0;
}

int IsFull(const IntStack2 *s) {    // Stack이 가득 차있는가?
	return (s->A_ptr + s->B_ptr) >= s->max;
}

int A_Search(const IntStack2 *s, int x) {    // Stack A에서 검색
	int i;
	for(i = s->A_ptr -1; i >= 0; i--) {    // Linear search (Top to Bottom)
		if(s->stk[i] == x) { return s->A_ptr - i; }    // 검색 성공    // Top에서 몇번째 인지 반환
	}
	return -1;    // 검색 실패
}
int B_Search(const IntStack2 *s, int x) {    // Stack B에서 검색
	int i;
	for(i = s->B_ptr; i >= 0; i--) {    // Linear search (Top to Bottom)
		if(s->stk[s->max - i] == x) { return s->B_ptr - (i -1); }    // 검색 성공    // Top에서 몇번째 인지 반환
	}
	return -1;    // 검색 실패
}

void A_Print(const IntStack2 *s) {    // Stack A의 모든 data 출력
	int i;
	for(i = 0; i < s->A_ptr; i++) {
		printf("%d ", s->stk[i]);
	}
	putchar('\n');
}
void B_Print(const IntStack2 *s) {    // Stack B의 모든 data 출력
	int i;
	for(i = 0; i < s->B_ptr; i++) {
		printf("%d ", s->stk[(s->max -1) - i]);
	}
	putchar('\n');
}

void Terminate(IntStack2 *s) {    // Stack 종료
	if(s->stk != NULL) { free(s->stk); }    // Stack이 차있으면 배열 stk를 free
	s->max = s->A_ptr = 0;
}