#pragma once
#ifndef _Lu175_INT_STACK_2
#define _Lu175_INT_STACK_2

typedef struct {
	int max;    // Stack �뷮 (�迭 stk�� ��� ����)
	int A_ptr;    // Stack A ������ (stack A�� �׿��ִ� data ����)
	int B_ptr;    // Stack B ������ (stack B�� �׿��ִ� data ����)
	int *stk;    // Stack ù ��ҿ� ���� ������
} IntStack2;

int Initialize(IntStack2 *s, int max);    // Stack �ʱ�ȭ

int A_Push(IntStack2 *s, int x);    // Stack A�� data�� push
int B_Push(IntStack2 *s, int x);    // Stack B�� data�� push

int A_Pop(IntStack2 *s, int *x);    // Stack A���� data�� pop
int B_Pop(IntStack2 *s, int *x);    // Stack B���� data�� pop

int A_Peek(const IntStack2 *s, int *x);    // Stack A���� data�� peek
int B_Peek(const IntStack2 *s, int *x);    // Stack B���� data�� peek

void A_Clear(IntStack2 *s);    // Stack A ����
void B_Clear(IntStack2 *s);    // Stack B ����

int Capacity(const IntStack2 *s);    // Stack�� �ִ� �뷮

int A_Size(const IntStack2 *s);    // Stack A�� data ����
int B_Size(const IntStack2 *s);    // Stack B�� data ����

int A_IsEmpty(const IntStack2 *s);    // Stack A�� ����ִ°�?
int B_IsEmpty(const IntStack2 *s);    // Stack B�� ����ִ°�?

int IsFull(const IntStack2 *s);    // Stack�� ���� ���ִ°�?

int A_Search(const IntStack2 *s, int x);    // Stack A���� �˻�
int B_Search(const IntStack2 *s, int x);    // Stack B���� �˻�

void A_Print(const IntStack2 *s);    // Stack A�� ��� data ���
void B_Print(const IntStack2 *s);    // Stack B�� ��� data ���

void Terminate(IntStack2 *s);    // Stack ����
#endif _INT_STACK_2