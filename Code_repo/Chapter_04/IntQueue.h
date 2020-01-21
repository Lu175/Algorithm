#pragma once
#ifndef _Lu175_INT_QUEUE
#define _Lu175_INT_QUEUE

typedef struct {
	int max;    // Queue의 용량
	int num;    // 현재 data 수
	int front;    // 논리적인 순서에서 첫번째 index
	int rear;    // 논리적인 순서에서 마지막 요소 다음의 index
	int *que;    // Queue의 첫 요소에 대한 포인터
}IntQueue;

int Initialize(IntQueue *q, int max);    // Queue 초기화

int Enque(IntQueue *q, int x);    // Queue에 data를 enqueue

int Deque(IntQueue *q, int *x);    // Queue에서 data를 dequeue

int Peek(const IntQueue *q, int *x);    // Queue에서 data를 peak

void Clear(IntQueue *q);    // 모든 data 삭제

int Capacity(const IntQueue *q);    // Queue의 최대 용량

int Size(const IntQueue *q);    // Queue에 저장된 data 수

int IsEmpty(const IntQueue *q);    // Queue가 비어있는가?

int IsFull(const IntQueue *q);    // Queue가 가득 차있는가?

int Search(const IntQueue *q, int x);    // Queue에서 검색    // index 반환
int Search2(const IntQueue *q, int x);    // Queue에서 검색    // Front로부터 상대적 위치 반환

void Print(const IntQueue *q);    // 모든 data 출력

void Terminate(IntQueue *q);    // Queue 종료
#endif _Lu175_INT_QUEUE