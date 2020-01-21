//// __________ArrayIntQueue__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include "ArrayIntQueue.h"
//
//int Initialize(ArrayIntQueue *q, int max) {    // Queue 초기화
//	q->num = 0;
//	if((q->que = calloc(max, sizeof(int))) == NULL) {    // Queue의 메모리 공간 할당
//		q->max = 0;    // 공간 할당이 안되면 배열 생성 실패    // 존재하지 않는 배열 que에 접근을 막기위해서 0 대입
//		return -1;
//	}
//	q->max = max;    // 공간 할당이 되면 배열 생성 성공
//	return 0;
//}
//
//int Enque(ArrayIntQueue *q, int x) {    // Queue에 data를 enqueue
//	if(q->num >= q->max) { return -1; }    // Queue가 가득 참
//	q->que[(q->num)++] = x;    // Rear 쪽으로 data 넣기
//	return 0;
//}
//
//int Deque(ArrayIntQueue *q, int *x) {    // Queue에서 data를 dequeue
//	if(q->num <= 0) { return -1; }    // Queue가 비어있음
//	*x = q->que[0];    // Front 쪽에서 data 방출
//	if(--(q->num) <= 0) { return 0; }    // 방출 후 Queue가 비어있는 경우
//
//	int i;
//	for(i = 1; i <= q->num; i++) {    // Front 쪽으로 한 칸씩 shift
//		q->que[i -1] = q->que[i];
//	}
//	return 0;
//}
//
//int Peek(const ArrayIntQueue *q, int *x) {    // Queue에서 data를 peak
//	if(q->num <= 0) { return -1; }    // Queue가 비어있음
//	*x = q->que[0];    // Front에 무엇이 있는지 확인
//	return 0;
//}
//
//void Clear(ArrayIntQueue *q) {    // 모든 data 삭제
//	q->num = 0;
//}
//
//int Capacity(const ArrayIntQueue *q) {    // Queue의 최대 용량
//	return q->max;
//}
//
//int Size(const ArrayIntQueue *q) {    // Queue에 저장된 data 수
//	return q->num;
//}
//
//int IsEmpty(const ArrayIntQueue *q) {    // Queue가 비어있는가?
//	return q->num <= 0;
//}
//
//int IsFull(const ArrayIntQueue *q) {    // Queue가 가득 차있는가?
//	return q->num >= q->max;
//}
//
//int Search(const ArrayIntQueue *q, int x) {    // Queue에서 검색
//	int i;
//	for(i = 0; i < q->num; i++) {    // Linear search (Front to Rear)
//		if(q->que[i] == x) { return i; }    // 검색 성공    // index 반환
//	}
//	return -1;    // 검색 실패
//}
//
//void Print(const ArrayIntQueue *q) {    // 모든 data 출력
//	int i;
//	for(i = 0; i < q->num; i++) {
//		printf("%d ", q->que[i]);
//	}
//	putchar('\n');
//}
//
//void Terminate(ArrayIntQueue *q) {    // Queue 종료
//	if(q->que != NULL) { free(q->que); }    // Queue가 차있으면 배열 que를 free
//	q->max = q->num = 0;
//}