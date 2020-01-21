#pragma once
#ifndef _Lu175_ARRAY_INT_QUEUE
#define _Lu175_ARRAY_INT_QUEUE

typedef struct {
	int max;    // Queue의 용량
	int num;    // 현재 data 수
	int *que;    // Queue의 첫 요소에 대한 포인터
}ArrayIntQueue;

int Initialize(ArrayIntQueue *q, int max);    // Queue 초기화

int Enque(ArrayIntQueue *q, int x);    // Queue에 data를 enqueue

int Deque(ArrayIntQueue *q, int *x);    // Queue에서 data를 dequeue

int Peek(const ArrayIntQueue *q, int *x);    // Queue에서 data를 peak

void Clear(ArrayIntQueue *q);    // 모든 data 삭제

int Capacity(const ArrayIntQueue *q);    // Queue의 최대 용량

int Size(const ArrayIntQueue *q);    // Queue에 저장된 data 수

int IsEmpty(const ArrayIntQueue *q);    // Queue가 비어있는가?

int IsFull(const ArrayIntQueue *q);    // Queue가 가득 차있는가?

int Search(const ArrayIntQueue *q, int x);    // Queue에서 검색

void Print(const ArrayIntQueue *q);    // 모든 data 출력

void Terminate(ArrayIntQueue *q);    // Queue 종료
#endif _Lu175_ARRAY_INT_QUEUE