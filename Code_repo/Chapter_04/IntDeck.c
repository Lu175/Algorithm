// __________IntDeck__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntDeck.h"

int Initialize(IntDeck *d, int max) {    // Queue 초기화
	d->num = d->front = d->rear = 0;
	if((d->deck = calloc(max, sizeof(int))) == NULL) {    // Queue의 메모리 공간 할당
		d->max = 0;    // 공간 할당이 안되면 배열 생성 실패    // 존재하지 않는 배열 que에 접근을 막기위해서 0 대입
		return -1;
	}
	d->max = max;    // 공간 할당이 되면 배열 생성 성공
	return 0;
}

int R_Enque(IntDeck *d, int x) {    // Rear에서 data를 enqueue
	if(d->num >= d->max) { return -1; }    // Queue가 가득 참
	else {
		d->num++;
		d->deck[(d->rear)++] = x;    // 'rear index'로 data 넣기
		if(d->rear == d->max) { d->rear = 0; }    // Ring buffer process
		return 0;
	}
}
int F_Enque(IntDeck *d, int x) {    // Front에서 data를 enqueue
	if(d->num >= d->max) { return -1; }    // Queue가 가득 참
	else {
		d->num++;
		if(d->front == d->rear) { d->deck[(d->rear)++] = x; }    // front와 rear가 같을 때 (= Deck이 비어있을 때), front는 그대로 rear는 증가
		else {
			if(--(d->front) == -1) { d->front = d->max -1; }    // Ring buffer process
			d->deck[d->front] = x;        // 'front index'에 data 넣기
		}
		return 0;
	}
}

int F_Deque(IntDeck *d, int *x) {    // Front에서 data를 dequeue
	if(d->num <= 0) { return -1; }    // Queue가 비어있음
	else {
		d->num--;
		*x = d->deck[(d->front)++];    // 'front index'의 data 방출
		if(d->front == d->max) { d->front = 0; }    // Ring buffer process
		return 0;
	}
}
int R_Deque(IntDeck *d, int *x) {    // Rear에서 data를 dequeue
	if(d->num <= 0) { return -1; }    // Queue가 비어있음
	else {
		d->num--;
		if(--(d->rear) == -1) { d->rear = d->max -1; }    // Ring buffer process
		*x = d->deck[d->rear];    // 'rear index' 이전의 data 방출
		return 0;
	}
}

int F_Peek(const IntDeck *d, int *x) {    // Front에서 data를 peak
	if(d->num <= 0) { return -1; }    // Queue가 비어있음
	*x = d->deck[d->front];    // 'front index'의 data를 확인
	return 0;
}
int R_Peek(const IntDeck *d, int *x) {    // Rear에서 data를 peak
	if(d->num <= 0) { return -1; }    // Queue가 비어있음

	int r_peek_idx = d->rear -1;
	if(r_peek_idx == -1) { r_peek_idx = d->max -1; }
	*x = d->deck[r_peek_idx];    // 'rear index' 이전의 data를 확인
	return 0;
}

void Clear(IntDeck *d) {    // 모든 data 삭제
	d->num = d->front = d->rear = 0;
}

int Capacity(const IntDeck *d) {    // Queue의 최대 용량
	return d->max;
}

int Size(const IntDeck *d) {    // Queue에 저장된 data 수
	return d->num;
}

int IsEmpty(const IntDeck *d) {    // Queue가 비어있는가?
	return d->num <= 0;
}

int IsFull(const IntDeck *d) {    // Queue가 가득 차있는가?
	return d->num >= d->max;
}

int Search(const IntDeck *d, int x) {    // Queue에서 검색
	int i, idx;
	for(i = 0; i < d->num; i++) {    // Linear search (Front to Rear)
		if(d->deck[idx = (i + d->front) % d->max] == x) { return idx; }    // 검색 성공    // index 반환
	}
	return -1;    // 검색 실패
}
int Search2(const IntDeck *d, int x) {    // Queue에서 검색
	int i, idx;
	for(i = 0; i < d->num; i++) {    // Linear search (Front to Rear)
		if(d->deck[idx = (i + d->front) % d->max] == x) {    // 검색 성공    // Front로부터 상대적 위치 반환
			if(d->front > idx) {    // 검색된 요소의 index가 front index보다 작다면
				return (d->max - d->front) + idx;
			}
			return idx - d->front;
		}
	}
	return -1;    // 검색 실패
}

void Print(const IntDeck *d) {    // 모든 data 출력
	int i;
	for(i = 0; i < d->num; i++) {
		printf("\tque[%d] : %d\n", (i + d->front) % d->max, d->deck[(i + d->front) % d->max]);
	}
	putchar('\n');
}

void Terminate(IntDeck *d) {    // Queue 종료
	if(d->deck != NULL) { free(d->deck); }    // Queue가 차있으면 배열 que를 free
	d->max = d->num = d->front = d->rear = 0;
}