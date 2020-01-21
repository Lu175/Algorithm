#pragma once
#ifndef _INT_STACK
#define _INT_STACK

typedef struct {
	int max;    // Stack 용량 (배열 stk의 요소 개수)
	int ptr;    // Stack 포인터 (stack에 쌓여있는 data 개수)
	int *stk;    // Stack 첫 요소에 대한 포인터
} IntStack;

int Initialize(IntStack *s, int max);    // Stack 초기화

int Push(IntStack *s, int x);    // Stack에 data를 push

int Pop(IntStack *s, int *x);    // Stack에서 data를 pop

int Peek(const IntStack *s, int *x);    // Stack에서 data를 peek

void Clear(IntStack *s);    // Stack 비우기

int Capacity(const IntStack *s);    // Stack의 최대 용량

int Size(const IntStack *s);    // Stack의 data 개수

int IsEmpty(const IntStack *s);    // Stack이 비어있는가?

int IsFull(const IntStack *s);    // Stack이 가득 차있는가?

int Search(const IntStack *s, int x);    // Stack에서 검색

void Print(const IntStack *s);    // 모든 data 출력

void Terminate(IntStack *s);    // Stack 종료
#endif _INT_STACK