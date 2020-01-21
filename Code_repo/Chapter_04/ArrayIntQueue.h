#pragma once
#ifndef _Lu175_ARRAY_INT_QUEUE
#define _Lu175_ARRAY_INT_QUEUE

typedef struct {
	int max;    // Queue�� �뷮
	int num;    // ���� data ��
	int *que;    // Queue�� ù ��ҿ� ���� ������
}ArrayIntQueue;

int Initialize(ArrayIntQueue *q, int max);    // Queue �ʱ�ȭ

int Enque(ArrayIntQueue *q, int x);    // Queue�� data�� enqueue

int Deque(ArrayIntQueue *q, int *x);    // Queue���� data�� dequeue

int Peek(const ArrayIntQueue *q, int *x);    // Queue���� data�� peak

void Clear(ArrayIntQueue *q);    // ��� data ����

int Capacity(const ArrayIntQueue *q);    // Queue�� �ִ� �뷮

int Size(const ArrayIntQueue *q);    // Queue�� ����� data ��

int IsEmpty(const ArrayIntQueue *q);    // Queue�� ����ִ°�?

int IsFull(const ArrayIntQueue *q);    // Queue�� ���� ���ִ°�?

int Search(const ArrayIntQueue *q, int x);    // Queue���� �˻�

void Print(const ArrayIntQueue *q);    // ��� data ���

void Terminate(ArrayIntQueue *q);    // Queue ����
#endif _Lu175_ARRAY_INT_QUEUE