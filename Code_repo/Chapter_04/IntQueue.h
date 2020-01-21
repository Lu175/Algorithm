#pragma once
#ifndef _Lu175_INT_QUEUE
#define _Lu175_INT_QUEUE

typedef struct {
	int max;    // Queue�� �뷮
	int num;    // ���� data ��
	int front;    // ������ �������� ù��° index
	int rear;    // ������ �������� ������ ��� ������ index
	int *que;    // Queue�� ù ��ҿ� ���� ������
}IntQueue;

int Initialize(IntQueue *q, int max);    // Queue �ʱ�ȭ

int Enque(IntQueue *q, int x);    // Queue�� data�� enqueue

int Deque(IntQueue *q, int *x);    // Queue���� data�� dequeue

int Peek(const IntQueue *q, int *x);    // Queue���� data�� peak

void Clear(IntQueue *q);    // ��� data ����

int Capacity(const IntQueue *q);    // Queue�� �ִ� �뷮

int Size(const IntQueue *q);    // Queue�� ����� data ��

int IsEmpty(const IntQueue *q);    // Queue�� ����ִ°�?

int IsFull(const IntQueue *q);    // Queue�� ���� ���ִ°�?

int Search(const IntQueue *q, int x);    // Queue���� �˻�    // index ��ȯ
int Search2(const IntQueue *q, int x);    // Queue���� �˻�    // Front�κ��� ����� ��ġ ��ȯ

void Print(const IntQueue *q);    // ��� data ���

void Terminate(IntQueue *q);    // Queue ����
#endif _Lu175_INT_QUEUE