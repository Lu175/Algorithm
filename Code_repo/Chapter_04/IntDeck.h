#pragma once
#ifndef _Lu175_INT_DECK
#define _Lu175_INT_DECK

typedef struct {
	int max;    // Queue�� �뷮
	int num;    // ���� data ��
	int front;    // ������ �������� ù��° index
	int rear;    // ������ �������� ������ ��� ������ index
	int *deck;    // Queue�� ù ��ҿ� ���� ������
}IntDeck;

int Initialize(IntDeck *d, int max);    // Queue �ʱ�ȭ

int R_Enque(IntDeck *d, int x);    // Rear���� data�� enqueue
int F_Enque(IntDeck *d, int x);    // Front���� data�� enqueue

int F_Deque(IntDeck *d, int *x);    // Front���� data�� dequeue
int R_Deque(IntDeck *d, int *x);    // Rear���� data�� dequeue

int F_Peek(const IntDeck *d, int *x);    // Front���� data�� peak
int R_Peek(const IntDeck *d, int *x);    // Rear���� data�� peak

void Clear(IntDeck *d);    // ��� data ����

int Capacity(const IntDeck *d);    // Queue�� �ִ� �뷮

int Size(const IntDeck *d);    // Queue�� ����� data ��

int IsEmpty(const IntDeck *d);    // Queue�� ����ִ°�?

int IsFull(const IntDeck *d);    // Queue�� ���� ���ִ°�?

int Search(const IntDeck *d, int x);    // Queue���� �˻�    // index ��ȯ
int Search2(const IntDeck *d, int x);    // Queue���� �˻�    // Front�κ��� ����� ��ġ ��ȯ

void Print(const IntDeck *d);    // ��� data ���

void Terminate(IntDeck *d);    // Queue ����
#endif _Lu175_INT_DECK