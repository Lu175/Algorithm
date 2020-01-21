//// __________IntQueue__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include "IntQueue.h"
//
//int Initialize(IntQueue *q, int max) {    // Queue 초기화
//	q->num = q->front = q->rear = 0;
//	if((q->que = calloc(max, sizeof(int))) == NULL) {    // Queue의 메모리 공간 할당
//		q->max = 0;    // 공간 할당이 안되면 배열 생성 실패    // 존재하지 않는 배열 que에 접근을 막기위해서 0 대입
//		return -1;
//	}
//	q->max = max;    // 공간 할당이 되면 배열 생성 성공
//	return 0;
//}
//
//int Enque(IntQueue *q, int x) {    // Queue에 data를 enqueue
//	if(q->num >= q->max) { return -1; }    // Queue가 가득 참
//	else {
//		q->num++;
//		q->que[(q->rear)++] = x;    // 'rear index'로 data 넣기
//		if(q->rear == q->max) { q->rear = 0; }    // Ring buffer process
//		return 0;
//	}
//}
//
//int Deque(IntQueue *q, int *x) {    // Queue에서 data를 dequeue
//	if(q->num <= 0) { return -1; }    // Queue가 비어있음
//	else {
//		q->num--;
//		*x = q->que[(q->front)++];    // 'front index'의 data 방출
//		if(q->front == q->max) {q->front = 0;}    // Ring buffer process
//		return 0;
//	}
//}
//
//int Peek(const IntQueue *q, int *x) {    // Queue에서 data를 peak
//	if(q->num <= 0) { return -1; }    // Queue가 비어있음
//	*x = q->que[q->front];    // Front에 무엇이 있는지 확인
//	return 0;
//}
//
//void Clear(IntQueue *q) {    // 모든 data 삭제
//	q->num = q->front = q->rear = 0;
//}
//
//int Capacity(const IntQueue *q) {    // Queue의 최대 용량
//	return q->max;
//}
//
//int Size(const IntQueue *q) {    // Queue에 저장된 data 수
//	return q->num;
//}
//
//int IsEmpty(const IntQueue *q) {    // Queue가 비어있는가?
//	return q->num <= 0;
//}
//
//int IsFull(const IntQueue *q) {    // Queue가 가득 차있는가?
//	return q->num >= q->max;
//}
//
//int Search(const IntQueue *q, int x) {    // Queue에서 검색
//	int i, idx;
//	for(i = 0; i < q->num; i++) {    // Linear search (Front to Rear)
//		if(q->que[idx = (i + q->front) % q->max] == x) { return idx; }    // 검색 성공    // index 반환
//	}
//	return -1;    // 검색 실패
//}
//int Search2(const IntQueue *q, int x) {    // Queue에서 검색
//	int i, idx;
//	for(i = 0; i < q->num; i++) {    // Linear search (Front to Rear)
//		if(q->que[idx = (i + q->front) % q->max] == x) {    // 검색 성공    // Front로부터 상대적 위치 반환
//			if(q->front > idx) {    // 검색된 요소의 index가 front index보다 작다면
//				return (q->max - q->front) + idx;
//			}
//			return idx - q->front;
//		}
//	}
//	return -1;    // 검색 실패
//}
//
//void Print(const IntQueue *q) {    // 모든 data 출력
//	int i;
//	for(i = 0; i < q->num; i++) {
//		printf("\tque[%d] : %d\n", (i + q->front) % q->max, q->que[(i + q->front) % q->max]);
//	}
//	putchar('\n');
//}
//
//void Terminate(IntQueue *q) {    // Queue 종료
//	if(q->que != NULL) { free(q->que); }    // Queue가 차있으면 배열 que를 free
//	q->max = q->num = q->front = q->rear = 0;
//}