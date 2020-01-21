//// __________IntQueue__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include "IntQueue.h"
//
//int Initialize(IntQueue *q, int max) {    // Queue �ʱ�ȭ
//	q->num = q->front = q->rear = 0;
//	if((q->que = calloc(max, sizeof(int))) == NULL) {    // Queue�� �޸� ���� �Ҵ�
//		q->max = 0;    // ���� �Ҵ��� �ȵǸ� �迭 ���� ����    // �������� �ʴ� �迭 que�� ������ �������ؼ� 0 ����
//		return -1;
//	}
//	q->max = max;    // ���� �Ҵ��� �Ǹ� �迭 ���� ����
//	return 0;
//}
//
//int Enque(IntQueue *q, int x) {    // Queue�� data�� enqueue
//	if(q->num >= q->max) { return -1; }    // Queue�� ���� ��
//	else {
//		q->num++;
//		q->que[(q->rear)++] = x;    // 'rear index'�� data �ֱ�
//		if(q->rear == q->max) { q->rear = 0; }    // Ring buffer process
//		return 0;
//	}
//}
//
//int Deque(IntQueue *q, int *x) {    // Queue���� data�� dequeue
//	if(q->num <= 0) { return -1; }    // Queue�� �������
//	else {
//		q->num--;
//		*x = q->que[(q->front)++];    // 'front index'�� data ����
//		if(q->front == q->max) {q->front = 0;}    // Ring buffer process
//		return 0;
//	}
//}
//
//int Peek(const IntQueue *q, int *x) {    // Queue���� data�� peak
//	if(q->num <= 0) { return -1; }    // Queue�� �������
//	*x = q->que[q->front];    // Front�� ������ �ִ��� Ȯ��
//	return 0;
//}
//
//void Clear(IntQueue *q) {    // ��� data ����
//	q->num = q->front = q->rear = 0;
//}
//
//int Capacity(const IntQueue *q) {    // Queue�� �ִ� �뷮
//	return q->max;
//}
//
//int Size(const IntQueue *q) {    // Queue�� ����� data ��
//	return q->num;
//}
//
//int IsEmpty(const IntQueue *q) {    // Queue�� ����ִ°�?
//	return q->num <= 0;
//}
//
//int IsFull(const IntQueue *q) {    // Queue�� ���� ���ִ°�?
//	return q->num >= q->max;
//}
//
//int Search(const IntQueue *q, int x) {    // Queue���� �˻�
//	int i, idx;
//	for(i = 0; i < q->num; i++) {    // Linear search (Front to Rear)
//		if(q->que[idx = (i + q->front) % q->max] == x) { return idx; }    // �˻� ����    // index ��ȯ
//	}
//	return -1;    // �˻� ����
//}
//int Search2(const IntQueue *q, int x) {    // Queue���� �˻�
//	int i, idx;
//	for(i = 0; i < q->num; i++) {    // Linear search (Front to Rear)
//		if(q->que[idx = (i + q->front) % q->max] == x) {    // �˻� ����    // Front�κ��� ����� ��ġ ��ȯ
//			if(q->front > idx) {    // �˻��� ����� index�� front index���� �۴ٸ�
//				return (q->max - q->front) + idx;
//			}
//			return idx - q->front;
//		}
//	}
//	return -1;    // �˻� ����
//}
//
//void Print(const IntQueue *q) {    // ��� data ���
//	int i;
//	for(i = 0; i < q->num; i++) {
//		printf("\tque[%d] : %d\n", (i + q->front) % q->max, q->que[(i + q->front) % q->max]);
//	}
//	putchar('\n');
//}
//
//void Terminate(IntQueue *q) {    // Queue ����
//	if(q->que != NULL) { free(q->que); }    // Queue�� �������� �迭 que�� free
//	q->max = q->num = q->front = q->rear = 0;
//}