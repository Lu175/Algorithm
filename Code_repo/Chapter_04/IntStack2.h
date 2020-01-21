#pragma once
#ifndef _Lu175_INT_STACK_2
#define _Lu175_INT_STACK_2

typedef struct {
	int max;    // Stack 용량 (배열 stk의 요소 개수)
	int A_ptr;    // Stack A 포인터 (stack A에 쌓여있는 data 개수)
	int B_ptr;    // Stack B 포인터 (stack B에 쌓여있는 data 개수)
	int *stk;    // Stack 첫 요소에 대한 포인터
} IntStack2;

int Initialize(IntStack2 *s, int max);    // Stack 초기화

int A_Push(IntStack2 *s, int x);    // Stack A에 data를 push
int B_Push(IntStack2 *s, int x);    // Stack B에 data를 push

int A_Pop(IntStack2 *s, int *x);    // Stack A에서 data를 pop
int B_Pop(IntStack2 *s, int *x);    // Stack B에서 data를 pop

int A_Peek(const IntStack2 *s, int *x);    // Stack A에서 data를 peek
int B_Peek(const IntStack2 *s, int *x);    // Stack B에서 data를 peek

void A_Clear(IntStack2 *s);    // Stack A 비우기
void B_Clear(IntStack2 *s);    // Stack B 비우기

int Capacity(const IntStack2 *s);    // Stack의 최대 용량

int A_Size(const IntStack2 *s);    // Stack A의 data 개수
int B_Size(const IntStack2 *s);    // Stack B의 data 개수

int A_IsEmpty(const IntStack2 *s);    // Stack A가 비어있는가?
int B_IsEmpty(const IntStack2 *s);    // Stack B가 비어있는가?

int IsFull(const IntStack2 *s);    // Stack이 가득 차있는가?

int A_Search(const IntStack2 *s, int x);    // Stack A에서 검색
int B_Search(const IntStack2 *s, int x);    // Stack B에서 검색

void A_Print(const IntStack2 *s);    // Stack A의 모든 data 출력
void B_Print(const IntStack2 *s);    // Stack B의 모든 data 출력

void Terminate(IntStack2 *s);    // Stack 종료
#endif _INT_STACK_2