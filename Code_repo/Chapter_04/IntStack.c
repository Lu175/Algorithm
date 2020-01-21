// __________IntStack__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack *s, int max) {    // Stack 초기화
	s->ptr = 0;
	if((s->stk = calloc(max, sizeof(int))) == NULL) {    // Stack의 메모리 공간 할당
		s->max = 0;    // 공간 할당이 안되면 배열 생성 실패    // 존재하지 않는 배열 stk에 접근을 막기위해서 0 대입
		return -1;
	}
	s->max = max;    // 공간 할당이 되면 배열 생성 성공
	return 0;
}

int Push(IntStack *s, int x) {    // Stack에 data를 push
	if(s->ptr >= s->max) { return -1; }    // Stack이 가득 참
	s->stk[(s->ptr)++] = x;    // Top 위에 data 쌓기
	return 0;
}

int Pop(IntStack *s, int *x) {    // Stack에서 data를 pop
	if(s->ptr <= 0) { return -1; }    // Stack이 비어있음
	*x = s->stk[--(s->ptr)];    // Top 요소값을 포인터 x에 저장
	return 0;
}

int Peek(const IntStack *s, int *x) {    // Stack에서 data를 peek
	if(s->ptr <= 0) { return -1; }    // Stack이 비어있음
	*x = s->stk[s->ptr - 1];    // Top에 무엇이 있는지 확인
	return 0;
}

void Clear(IntStack *s) {    // Stack 비우기
	s->ptr = 0;    // 'ptr'이 stack에 쌓여있는 data 개수이므로
}

int Capacity(const IntStack *s) {    // Stack의 최대 용량
	return s->max;
}

int Size(const IntStack *s) {    // Stack의 data 개수
	return s->ptr;
}

int IsEmpty(const IntStack *s) {    // Stack이 비어있는가?
	return s->ptr <= 0;
}

int IsFull(const IntStack *s) {    // Stack이 가득 차있는가?
	return s->ptr >= s->max;
}

int Search(const IntStack *s, int x) {    // Stack에서 검색
	int i;
	for(i = s->ptr -1; i >= 0; i--) {    // Linear search (Top to Bottom)
		if(s->stk[i] == x) { return i; }    // 검색 성공    // index 반환
	}
	return -1;    // 검색 실패
}

void Print(const IntStack *s) {    // 모든 data 출력
	int i;
	for(i = 0; i < s->ptr; i++) {
		printf("%d ", s->stk[i]);
	}
	putchar('\n');
}

void Terminate(IntStack *s) {    // Stack 종료
	if(s->stk != NULL) { free(s->stk); }    // Stack이 차있으면 배열 stk를 free
	s->max = s->ptr = 0;
}