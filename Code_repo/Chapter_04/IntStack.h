#pragma once
#ifndef _INT_STACK
#define _INT_STACK

typedef struct {
	int max;    // Stack �뷮 (�迭 stk�� ��� ����)
	int ptr;    // Stack ������ (stack�� �׿��ִ� data ����)
	int *stk;    // Stack ù ��ҿ� ���� ������
} IntStack;

int Initialize(IntStack *s, int max);    // Stack �ʱ�ȭ

int Push(IntStack *s, int x);    // Stack�� data�� push

int Pop(IntStack *s, int *x);    // Stack���� data�� pop

int Peek(const IntStack *s, int *x);    // Stack���� data�� peek

void Clear(IntStack *s);    // Stack ����

int Capacity(const IntStack *s);    // Stack�� �ִ� �뷮

int Size(const IntStack *s);    // Stack�� data ����

int IsEmpty(const IntStack *s);    // Stack�� ����ִ°�?

int IsFull(const IntStack *s);    // Stack�� ���� ���ִ°�?

int Search(const IntStack *s, int x);    // Stack���� �˻�

void Print(const IntStack *s);    // ��� data ���

void Terminate(IntStack *s);    // Stack ����
#endif _INT_STACK