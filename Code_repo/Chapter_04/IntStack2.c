// __________IntStack2 : �迭 �ϳ��� �����ϴ� 2���� stack__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack2.h"

int Initialize(IntStack2 *s, int max) {    // Stack �ʱ�ȭ
	s->A_ptr = 0;
	s->B_ptr = 0;
	if((s->stk = calloc(max, sizeof(int))) == NULL) {    // Stack�� �޸� ���� �Ҵ�
		s->max = 0;    // ���� �Ҵ��� �ȵǸ� �迭 ���� ����    // �������� �ʴ� �迭 stk�� ������ �������ؼ� 0 ����
		return -1;
	}
	s->max = max;    // ���� �Ҵ��� �Ǹ� �迭 ���� ����
	return 0;
}

int A_Push(IntStack2 *s, int x) {    // Stack A�� data�� push
	if(s->A_ptr >= (s->max - s->B_ptr)) { return -1; }    // Stack A�� ���� ��
	s->stk[(s->A_ptr)++] = x;    // Top ���� data �ױ�
	return 0;
}
int B_Push(IntStack2 *s, int x) {    // Stack B�� data�� push
	if(s->B_ptr >= (s->max - s->A_ptr)) { return -1; }    // Stack B�� ���� ��
	s->stk[(s->max - (s->B_ptr)++) -1] = x;    // Top ���� data �ױ�
	return 0;
}

int A_Pop(IntStack2 *s, int *x) {    // Stack A���� data�� pop
	if(s->A_ptr <= 0) { return -1; }    // Stack A�� �������
	*x = s->stk[--(s->A_ptr)];    // Top ��Ұ��� ������ x�� ����
	return 0;
}
int B_Pop(IntStack2 *s, int *x) {    // Stack B���� data�� pop
	if(s->B_ptr <= 0) { return -1; }    // Stack B�� �������
	*x = s->stk[s->max - --(s->B_ptr)];    // Top ��Ұ��� ������ x�� ����
	return 0;
}

int A_Peek(const IntStack2 *s, int *x) {    // Stack A���� data�� peek
	if(s->A_ptr <= 0) { return -1; }    // Stack A�� �������
	*x = s->stk[s->A_ptr - 1];    // Top�� ������ �ִ��� Ȯ��
	return 0;
}
int B_Peek(const IntStack2 *s, int *x) {    // Stack B���� data�� peek
	if(s->B_ptr <= 0) { return -1; }    // Stack B�� �������
	*x = s->stk[s->max - s->B_ptr];    // Top�� ������ �ִ��� Ȯ��
	return 0;
}

void A_Clear(IntStack2 *s) {    // Stack A ����
	s->A_ptr = 0;
}
void B_Clear(IntStack2 *s) {    // Stack B ����
	s->B_ptr = 0;
}

int Capacity(const IntStack2 *s) {    // Stack�� �ִ� �뷮
	return s->max;
}

int A_Size(const IntStack2 *s) {    // Stack�� data ����
	return s->A_ptr;
}
int B_Size(const IntStack2 *s) {    // Stack�� data ����
	return s->B_ptr;
}

int A_IsEmpty(const IntStack2 *s) {    // Stack A�� ����ִ°�?
	return s->A_ptr <= 0;
}
int B_IsEmpty(const IntStack2 *s) {    // Stack B�� ����ִ°�?
	return s->B_ptr <= 0;
}

int IsFull(const IntStack2 *s) {    // Stack�� ���� ���ִ°�?
	return (s->A_ptr + s->B_ptr) >= s->max;
}

int A_Search(const IntStack2 *s, int x) {    // Stack A���� �˻�
	int i;
	for(i = s->A_ptr -1; i >= 0; i--) {    // Linear search (Top to Bottom)
		if(s->stk[i] == x) { return s->A_ptr - i; }    // �˻� ����    // Top���� ���° ���� ��ȯ
	}
	return -1;    // �˻� ����
}
int B_Search(const IntStack2 *s, int x) {    // Stack B���� �˻�
	int i;
	for(i = s->B_ptr; i >= 0; i--) {    // Linear search (Top to Bottom)
		if(s->stk[s->max - i] == x) { return s->B_ptr - (i -1); }    // �˻� ����    // Top���� ���° ���� ��ȯ
	}
	return -1;    // �˻� ����
}

void A_Print(const IntStack2 *s) {    // Stack A�� ��� data ���
	int i;
	for(i = 0; i < s->A_ptr; i++) {
		printf("%d ", s->stk[i]);
	}
	putchar('\n');
}
void B_Print(const IntStack2 *s) {    // Stack B�� ��� data ���
	int i;
	for(i = 0; i < s->B_ptr; i++) {
		printf("%d ", s->stk[(s->max -1) - i]);
	}
	putchar('\n');
}

void Terminate(IntStack2 *s) {    // Stack ����
	if(s->stk != NULL) { free(s->stk); }    // Stack�� �������� �迭 stk�� free
	s->max = s->A_ptr = 0;
}