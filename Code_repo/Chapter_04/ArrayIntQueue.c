//// __________ArrayIntQueue__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include "ArrayIntQueue.h"
//
//int Initialize(ArrayIntQueue *q, int max) {    // Queue �ʱ�ȭ
//	q->num = 0;
//	if((q->que = calloc(max, sizeof(int))) == NULL) {    // Queue�� �޸� ���� �Ҵ�
//		q->max = 0;    // ���� �Ҵ��� �ȵǸ� �迭 ���� ����    // �������� �ʴ� �迭 que�� ������ �������ؼ� 0 ����
//		return -1;
//	}
//	q->max = max;    // ���� �Ҵ��� �Ǹ� �迭 ���� ����
//	return 0;
//}
//
//int Enque(ArrayIntQueue *q, int x) {    // Queue�� data�� enqueue
//	if(q->num >= q->max) { return -1; }    // Queue�� ���� ��
//	q->que[(q->num)++] = x;    // Rear ������ data �ֱ�
//	return 0;
//}
//
//int Deque(ArrayIntQueue *q, int *x) {    // Queue���� data�� dequeue
//	if(q->num <= 0) { return -1; }    // Queue�� �������
//	*x = q->que[0];    // Front �ʿ��� data ����
//	if(--(q->num) <= 0) { return 0; }    // ���� �� Queue�� ����ִ� ���
//
//	int i;
//	for(i = 1; i <= q->num; i++) {    // Front ������ �� ĭ�� shift
//		q->que[i -1] = q->que[i];
//	}
//	return 0;
//}
//
//int Peek(const ArrayIntQueue *q, int *x) {    // Queue���� data�� peak
//	if(q->num <= 0) { return -1; }    // Queue�� �������
//	*x = q->que[0];    // Front�� ������ �ִ��� Ȯ��
//	return 0;
//}
//
//void Clear(ArrayIntQueue *q) {    // ��� data ����
//	q->num = 0;
//}
//
//int Capacity(const ArrayIntQueue *q) {    // Queue�� �ִ� �뷮
//	return q->max;
//}
//
//int Size(const ArrayIntQueue *q) {    // Queue�� ����� data ��
//	return q->num;
//}
//
//int IsEmpty(const ArrayIntQueue *q) {    // Queue�� ����ִ°�?
//	return q->num <= 0;
//}
//
//int IsFull(const ArrayIntQueue *q) {    // Queue�� ���� ���ִ°�?
//	return q->num >= q->max;
//}
//
//int Search(const ArrayIntQueue *q, int x) {    // Queue���� �˻�
//	int i;
//	for(i = 0; i < q->num; i++) {    // Linear search (Front to Rear)
//		if(q->que[i] == x) { return i; }    // �˻� ����    // index ��ȯ
//	}
//	return -1;    // �˻� ����
//}
//
//void Print(const ArrayIntQueue *q) {    // ��� data ���
//	int i;
//	for(i = 0; i < q->num; i++) {
//		printf("%d ", q->que[i]);
//	}
//	putchar('\n');
//}
//
//void Terminate(ArrayIntQueue *q) {    // Queue ����
//	if(q->que != NULL) { free(q->que); }    // Queue�� �������� �迭 que�� free
//	q->max = q->num = 0;
//}