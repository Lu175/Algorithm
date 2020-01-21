// __________IntDeck__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntDeck.h"

int Initialize(IntDeck *d, int max) {    // Queue �ʱ�ȭ
	d->num = d->front = d->rear = 0;
	if((d->deck = calloc(max, sizeof(int))) == NULL) {    // Queue�� �޸� ���� �Ҵ�
		d->max = 0;    // ���� �Ҵ��� �ȵǸ� �迭 ���� ����    // �������� �ʴ� �迭 que�� ������ �������ؼ� 0 ����
		return -1;
	}
	d->max = max;    // ���� �Ҵ��� �Ǹ� �迭 ���� ����
	return 0;
}

int R_Enque(IntDeck *d, int x) {    // Rear���� data�� enqueue
	if(d->num >= d->max) { return -1; }    // Queue�� ���� ��
	else {
		d->num++;
		d->deck[(d->rear)++] = x;    // 'rear index'�� data �ֱ�
		if(d->rear == d->max) { d->rear = 0; }    // Ring buffer process
		return 0;
	}
}
int F_Enque(IntDeck *d, int x) {    // Front���� data�� enqueue
	if(d->num >= d->max) { return -1; }    // Queue�� ���� ��
	else {
		d->num++;
		if(d->front == d->rear) { d->deck[(d->rear)++] = x; }    // front�� rear�� ���� �� (= Deck�� ������� ��), front�� �״�� rear�� ����
		else {
			if(--(d->front) == -1) { d->front = d->max -1; }    // Ring buffer process
			d->deck[d->front] = x;        // 'front index'�� data �ֱ�
		}
		return 0;
	}
}

int F_Deque(IntDeck *d, int *x) {    // Front���� data�� dequeue
	if(d->num <= 0) { return -1; }    // Queue�� �������
	else {
		d->num--;
		*x = d->deck[(d->front)++];    // 'front index'�� data ����
		if(d->front == d->max) { d->front = 0; }    // Ring buffer process
		return 0;
	}
}
int R_Deque(IntDeck *d, int *x) {    // Rear���� data�� dequeue
	if(d->num <= 0) { return -1; }    // Queue�� �������
	else {
		d->num--;
		if(--(d->rear) == -1) { d->rear = d->max -1; }    // Ring buffer process
		*x = d->deck[d->rear];    // 'rear index' ������ data ����
		return 0;
	}
}

int F_Peek(const IntDeck *d, int *x) {    // Front���� data�� peak
	if(d->num <= 0) { return -1; }    // Queue�� �������
	*x = d->deck[d->front];    // 'front index'�� data�� Ȯ��
	return 0;
}
int R_Peek(const IntDeck *d, int *x) {    // Rear���� data�� peak
	if(d->num <= 0) { return -1; }    // Queue�� �������

	int r_peek_idx = d->rear -1;
	if(r_peek_idx == -1) { r_peek_idx = d->max -1; }
	*x = d->deck[r_peek_idx];    // 'rear index' ������ data�� Ȯ��
	return 0;
}

void Clear(IntDeck *d) {    // ��� data ����
	d->num = d->front = d->rear = 0;
}

int Capacity(const IntDeck *d) {    // Queue�� �ִ� �뷮
	return d->max;
}

int Size(const IntDeck *d) {    // Queue�� ����� data ��
	return d->num;
}

int IsEmpty(const IntDeck *d) {    // Queue�� ����ִ°�?
	return d->num <= 0;
}

int IsFull(const IntDeck *d) {    // Queue�� ���� ���ִ°�?
	return d->num >= d->max;
}

int Search(const IntDeck *d, int x) {    // Queue���� �˻�
	int i, idx;
	for(i = 0; i < d->num; i++) {    // Linear search (Front to Rear)
		if(d->deck[idx = (i + d->front) % d->max] == x) { return idx; }    // �˻� ����    // index ��ȯ
	}
	return -1;    // �˻� ����
}
int Search2(const IntDeck *d, int x) {    // Queue���� �˻�
	int i, idx;
	for(i = 0; i < d->num; i++) {    // Linear search (Front to Rear)
		if(d->deck[idx = (i + d->front) % d->max] == x) {    // �˻� ����    // Front�κ��� ����� ��ġ ��ȯ
			if(d->front > idx) {    // �˻��� ����� index�� front index���� �۴ٸ�
				return (d->max - d->front) + idx;
			}
			return idx - d->front;
		}
	}
	return -1;    // �˻� ����
}

void Print(const IntDeck *d) {    // ��� data ���
	int i;
	for(i = 0; i < d->num; i++) {
		printf("\tque[%d] : %d\n", (i + d->front) % d->max, d->deck[(i + d->front) % d->max]);
	}
	putchar('\n');
}

void Terminate(IntDeck *d) {    // Queue ����
	if(d->deck != NULL) { free(d->deck); }    // Queue�� �������� �迭 que�� free
	d->max = d->num = d->front = d->rear = 0;
}