// __________IntStack__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack *s, int max) {    // Stack �ʱ�ȭ
	s->ptr = 0;
	if((s->stk = calloc(max, sizeof(int))) == NULL) {    // Stack�� �޸� ���� �Ҵ�
		s->max = 0;    // ���� �Ҵ��� �ȵǸ� �迭 ���� ����    // �������� �ʴ� �迭 stk�� ������ �������ؼ� 0 ����
		return -1;
	}
	s->max = max;    // ���� �Ҵ��� �Ǹ� �迭 ���� ����
	return 0;
}

int Push(IntStack *s, int x) {    // Stack�� data�� push
	if(s->ptr >= s->max) { return -1; }    // Stack�� ���� ��
	s->stk[(s->ptr)++] = x;    // Top ���� data �ױ�
	return 0;
}

int Pop(IntStack *s, int *x) {    // Stack���� data�� pop
	if(s->ptr <= 0) { return -1; }    // Stack�� �������
	*x = s->stk[--(s->ptr)];    // Top ��Ұ��� ������ x�� ����
	return 0;
}

int Peek(const IntStack *s, int *x) {    // Stack���� data�� peek
	if(s->ptr <= 0) { return -1; }    // Stack�� �������
	*x = s->stk[s->ptr - 1];    // Top�� ������ �ִ��� Ȯ��
	return 0;
}

void Clear(IntStack *s) {    // Stack ����
	s->ptr = 0;    // 'ptr'�� stack�� �׿��ִ� data �����̹Ƿ�
}

int Capacity(const IntStack *s) {    // Stack�� �ִ� �뷮
	return s->max;
}

int Size(const IntStack *s) {    // Stack�� data ����
	return s->ptr;
}

int IsEmpty(const IntStack *s) {    // Stack�� ����ִ°�?
	return s->ptr <= 0;
}

int IsFull(const IntStack *s) {    // Stack�� ���� ���ִ°�?
	return s->ptr >= s->max;
}

int Search(const IntStack *s, int x) {    // Stack���� �˻�
	int i;
	for(i = s->ptr -1; i >= 0; i--) {    // Linear search (Top to Bottom)
		if(s->stk[i] == x) { return i; }    // �˻� ����    // index ��ȯ
	}
	return -1;    // �˻� ����
}

void Print(const IntStack *s) {    // ��� data ���
	int i;
	for(i = 0; i < s->ptr; i++) {
		printf("%d ", s->stk[i]);
	}
	putchar('\n');
}

void Terminate(IntStack *s) {    // Stack ����
	if(s->stk != NULL) { free(s->stk); }    // Stack�� �������� �迭 stk�� free
	s->max = s->ptr = 0;
}