#pragma once
#ifndef _Lu175_INT_DECK
#define _Lu175_INT_DECK

typedef struct {
	int max;    // Queue의 용량
	int num;    // 현재 data 수
	int front;    // 논리적인 순서에서 첫번째 index
	int rear;    // 논리적인 순서에서 마지막 요소 다음의 index
	int *deck;    // Queue의 첫 요소에 대한 포인터
}IntDeck;

int Initialize(IntDeck *d, int max);    // Queue 초기화

int R_Enque(IntDeck *d, int x);    // Rear에서 data를 enqueue
int F_Enque(IntDeck *d, int x);    // Front에서 data를 enqueue

int F_Deque(IntDeck *d, int *x);    // Front에서 data를 dequeue
int R_Deque(IntDeck *d, int *x);    // Rear에서 data를 dequeue

int F_Peek(const IntDeck *d, int *x);    // Front에서 data를 peak
int R_Peek(const IntDeck *d, int *x);    // Rear에서 data를 peak

void Clear(IntDeck *d);    // 모든 data 삭제

int Capacity(const IntDeck *d);    // Queue의 최대 용량

int Size(const IntDeck *d);    // Queue에 저장된 data 수

int IsEmpty(const IntDeck *d);    // Queue가 비어있는가?

int IsFull(const IntDeck *d);    // Queue가 가득 차있는가?

int Search(const IntDeck *d, int x);    // Queue에서 검색    // index 반환
int Search2(const IntDeck *d, int x);    // Queue에서 검색    // Front로부터 상대적 위치 반환

void Print(const IntDeck *d);    // 모든 data 출력

void Terminate(IntDeck *d);    // Queue 종료
#endif _Lu175_INT_DECK