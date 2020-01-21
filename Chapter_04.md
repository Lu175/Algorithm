# 자료구조와 함께 배우는 알고리즘 입문 (C언어 편)
+ 2020.01.21.
+ Chapter 4 (pp. 130-163)
* * *
## Table of contents

* [p.142](#p142)
    - [Q1: Use IntStack](#q1)
      + [IntStack.c](#intstackc)
      + [IntStack.h](#intstackh)
      + [main.c](#mainc)
    - [Q2: Use IntStack2](#q2)
      + [IntStack2.c](#intstack2c)
      + [IntStack2.h](#intstack2h)
      + [main.c](#mainc-1)
* [p.144](#p144)
    - [Q3: Use ArrayIntQueue](#q3)
      + [ArrayIntQueue.c](#arrayintqueuec)
      + [ArrayIntQueue.h](#arrayintqueueh)
      + [main.c](#mainc-2)
* [p.160](#p160)
    - [Q4, Q5: Add Search2 function to IntQueue](#q4--q5)
      + [IntQueue.c](#intqueuec)
      + [IntQueue.h](#intqueueh)
      + [main.c](#mainc-3)
    - [Q6: Deck: double ended queue](#q6)
      + [IntDeck.c](#intdeckc)
      + [IntDeck.h](#intdeckh)
      + [main.c](#mainc-4)
      
* * *
## p.142
>#### Q1
#### IntStack.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/IntStack.c)
#### IntStack.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/IntStack.h)
```C
#pragma once
#ifndef _INT_STACK
#define _INT_STACK

typedef struct {
	int max;    // Stack 용량 (배열 stk의 요소 개수)
	int ptr;    // Stack 포인터 (stack에 쌓여있는 data 개수)
	int *stk;    // Stack 첫 요소에 대한 포인터
} IntStack;

int Initialize(IntStack *s, int max);    // Stack 초기화
int Push(IntStack *s, int x);    // Stack에 data를 push
int Pop(IntStack *s, int *x);    // Stack에서 data를 pop
int Peek(const IntStack *s, int *x);    // Stack에서 data를 peek
void Clear(IntStack *s);    // Stack 비우기
int Capacity(const IntStack *s);    // Stack의 최대 용량
int Size(const IntStack *s);    // Stack의 data 개수
int IsEmpty(const IntStack *s);    // Stack이 비어있는가?
int IsFull(const IntStack *s);    // Stack이 가득 차있는가?
int Search(const IntStack *s, int x);    // Stack에서 검색
void Print(const IntStack *s);    // 모든 data 출력
void Terminate(IntStack *s);    // Stack 종료
#endif _INT_STACK
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/4-Q1.c)
```C
// __________Use IntStack__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

int main(void) {
	IntStack s;
	int stack_size;

	do {
		printf("Stack size: ");
		scanf("%d", &stack_size);
	} while(stack_size <= 0);    // 0 이하로 작성하면 retry

	if(Initialize(&s, stack_size) == -1) {
		puts("stack 생성 실패");
		return 1;
	}

	while(1) {
		int menu, x;
		printf("현재 data 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)Push (2)Pop (3)Peek (4)Print (5)Search (6)Clear (0)Terminate : ");
		scanf("%d", &menu);

		if(menu == 0) { break; }    // For 'Terminate'

		switch(menu) {
		case 1:    // Push
			printf("Input data: ");
			scanf("%d", &x);
			if(Push(&s, x) == -1) { puts("\a오류 : Push 실패"); }
			break;

		case 2:    // Pop
			if(Pop(&s, &x) == -1) { puts("\a오류 : Pop 실패"); }
			else { printf("Pop data는 %d 입니다.\n", x); }
			break;

		case 3:    // Peek
			if(Peek(&s, &x) == -1) { puts("\a오류 : Peek 실패"); }
			else { printf("Peek data는 %d 입니다.\n", x); }
			break;

		case 4:    // Print
			printf("Stack :  (Bottom ~ Top)  ");
			Print(&s);
			break;

		case 5:    // Search
			printf("Search data: ");
			scanf("%d", &x);
			int idx = Search(&s, x);
			if(idx == -1) { puts("\a오류 : Search 실패"); }
			else { printf("Search data는 top에서 %d 번째에 있습니다.\n", Size(&s) - idx); }
			break;

		case 6:    // Clear
			Clear(&s);
			puts("Stack cleared");
			break;

		default:
			break;
		}

		if(IsEmpty(&s) == 1) { puts("Stack이 비어있습니다."); }
		if(IsFull(&s) == 1) { puts("Stack이 가득 차있습니다."); }
		printf("\n");
	}
	Terminate(&s);
	return 0;
}
```
>#### Q2
#### IntStack2.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/IntStack2.c)
#### IntStack2.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/IntStack2.h)
```C
#pragma once
#ifndef _Lu175_INT_STACK_2
#define _Lu175_INT_STACK_2

typedef struct {
	int max;    // Stack 용량 (배열 stk의 요소 개수)
	int A_ptr;    // Stack A 포인터 (stack A에 쌓여있는 data 개수)
	int B_ptr;    // Stack B 포인터 (stack B에 쌓여있는 data 개수)
	int *stk;    // Stack 첫 요소에 대한 포인터
} IntStack2;

int Initialize(IntStack2 *s, int max);    // Stack 초기화

int A_Push(IntStack2 *s, int x);    // Stack A에 data를 push
int B_Push(IntStack2 *s, int x);    // Stack B에 data를 push

int A_Pop(IntStack2 *s, int *x);    // Stack A에서 data를 pop
int B_Pop(IntStack2 *s, int *x);    // Stack B에서 data를 pop

int A_Peek(const IntStack2 *s, int *x);    // Stack A에서 data를 peek
int B_Peek(const IntStack2 *s, int *x);    // Stack B에서 data를 peek

void A_Clear(IntStack2 *s);    // Stack A 비우기
void B_Clear(IntStack2 *s);    // Stack B 비우기

int Capacity(const IntStack2 *s);    // Stack의 최대 용량

int A_Size(const IntStack2 *s);    // Stack A의 data 개수
int B_Size(const IntStack2 *s);    // Stack B의 data 개수

int A_IsEmpty(const IntStack2 *s);    // Stack A가 비어있는가?
int B_IsEmpty(const IntStack2 *s);    // Stack B가 비어있는가?

int IsFull(const IntStack2 *s);    // Stack이 가득 차있는가?

int A_Search(const IntStack2 *s, int x);    // Stack A에서 검색
int B_Search(const IntStack2 *s, int x);    // Stack B에서 검색

void A_Print(const IntStack2 *s);    // Stack A의 모든 data 출력
void B_Print(const IntStack2 *s);    // Stack B의 모든 data 출력

void Terminate(IntStack2 *s);    // Stack 종료
#endif _INT_STACK_2
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/4-Q2.c)
```C
// __________Use IntStack2__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack2.h"

int main(void) {
	IntStack2 s;
	int stack_Size;

	do {
		printf("Stack size: ");
		scanf("%d", &stack_Size);
	} while(stack_Size <= 0);    // 0 이하로 작성하면 retry

	if(Initialize(&s, stack_Size) == -1) {
		puts("stack 생성 실패");
		return 1;
	}

	while(1) {
		int menu1, menu2, x;
		printf("\n");
		printf("Stack A : %d / %d\n", A_Size(&s), Capacity(&s) - B_Size(&s));
		printf("Stack B : %d / %d\n", B_Size(&s), Capacity(&s) - A_Size(&s));
		printf("[Menu 1]  (1)Stack A (2)Stack B (3)Print stacks (0)Terminate: ");
		scanf("%d", &menu1);

		if(menu1 == 0) { break; }    // For 'Terminate'

		if(menu1 == 1) {    // Stack A
			printf("In Stack A...");
			printf("[Menu 2]  (1)Push (2)Pop (3)Peek (4)Search (5)Clear (0)Go to [Menu 1] : ");
			scanf("%d", &menu2);

			if(menu2 == 0) { continue; }    // For 'Go to Menu 1'

			switch(menu2) {
			case 1:    // Push A
				printf("Input data: ");
				scanf("%d", &x);
				if(A_Push(&s, x) == -1) { puts("\a오류 : Push 실패"); }
				break;

			case 2:    // Pop A
				if(A_Pop(&s, &x) == -1) { puts("\a오류 : Pop 실패"); }
				else { printf("Pop data는 %d 입니다.\n", x); }
				break;

			case 3:    // Peek A
				if(A_Peek(&s, &x) == -1) { puts("\a오류 : Peek 실패"); }
				else { printf("Stack A의 Peek data는 %d 입니다.\n", x); }
				break;

			case 4:    // Search A
				printf("Search data: ");
				scanf("%d", &x);
				int idx = A_Search(&s, x);
				if(idx == -1) { puts("\a오류 : Search 실패"); }
				else { printf("Stack A의 top에서 %d 번째에 있습니다.\n", idx); }
				break;

			case 5:    // Clear A
				A_Clear(&s);
				puts("Stack A cleared");
				break;
			}
		}

		if(menu1 == 2) {    // Stack B
			printf("In Stack B...");
			printf("[Menu 2]  (1)Push (2)Pop (3)Peek (4)Search (5)Clear (0)Go to [Menu 1] : ");
			scanf("%d", &menu2);

			if(menu2 == 0) { continue; }    // For 'Go to Menu 1'

			switch(menu2) {
			case 1:    // Push B
				printf("Input data: ");
				scanf("%d", &x);
				if(B_Push(&s, x) == -1) { puts("\a오류 : Push 실패"); }
				break;

			case 2:    // Pop B
				if(B_Pop(&s, &x) == -1) { puts("\a오류 : Pop 실패"); }
				else { printf("Pop data는 %d 입니다.\n", x); }
				break;

			case 3:    // Peek B
				if(B_Peek(&s, &x) == -1) { puts("\a오류 : Peek 실패"); }
				else { printf("Stack B의 Peek data는 %d 입니다.\n", x); }
				break;

			case 4:    // Search B
				printf("Search data: ");
				scanf("%d", &x);
				int idx = B_Search(&s, x);
				if(idx == -1) { puts("\a오류 : Search 실패"); }
				else { printf("Stack B의 top에서 %d 번째에 있습니다.\n", idx); }
				break;

			case 5:    // Clear B
				B_Clear(&s);
				puts("Stack B cleared");
				break;

			default:
				break;
			}
		}

		if(menu1 == 3) {    // Print stacks
			printf("Stack A :  (Bottom ~ Top)  ");
			A_Print(&s);
			printf("Stack B :  (Top ~ Bottom)  ");
			B_Print(&s);
		}

		if(A_IsEmpty(&s) == 1) { puts("Stack A가 비어있습니다."); }
		if(B_IsEmpty(&s) == 1) { puts("Stack B가 비어있습니다."); }
		if(IsFull(&s) == 1) { puts("Stack이 가득 차있습니다."); }
	}

	Terminate(&s);
	return 0;
}
```
## p.144
>#### Q3
#### ArrayIntQueue.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/ArrayIntQueue.c)
#### ArrayIntQueue.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/ArrayIntQueue.h)
```C
#pragma once
#ifndef _Lu175_ARRAY_INT_QUEUE
#define _Lu175_ARRAY_INT_QUEUE

typedef struct {
	int max;    // Queue의 용량
	int num;    // 현재 data 수
	int *que;    // Queue의 첫 요소에 대한 포인터
}ArrayIntQueue;

int Initialize(ArrayIntQueue *q, int max);    // Queue 초기화
int Enque(ArrayIntQueue *q, int x);    // Queue에 data를 enqueue
int Deque(ArrayIntQueue *q, int *x);    // Queue에서 data를 dequeue
int Peek(const ArrayIntQueue *q, int *x);    // Queue에서 data를 peak
void Clear(ArrayIntQueue *q);    // 모든 data 삭제
int Capacity(const ArrayIntQueue *q);    // Queue의 최대 용량
int Size(const ArrayIntQueue *q);    // Queue에 저장된 data 수
int IsEmpty(const ArrayIntQueue *q);    // Queue가 비어있는가?
int IsFull(const ArrayIntQueue *q);    // Queue가 가득 차있는가?
int Search(const ArrayIntQueue *q, int x);    // Queue에서 검색
void Print(const ArrayIntQueue *q);    // 모든 data 출력
void Terminate(ArrayIntQueue *q);    // Queue 종료
#endif _Lu175_ARRAY_INT_QUEUE
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/4-Q3.c)
```C
// __________Use ArrayIntQueue__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ArrayIntQueue.h"

int main(void) {
	ArrayIntQueue q;
	int queue_size;

	do {
		printf("Queue size: ");
		scanf("%d", &queue_size);
	} while(queue_size <= 0);    // 0 이하로 작성하면 retry

	if(Initialize(&q, queue_size) == -1) {
		puts("queue 생성 실패");
		return 1;
	}

	while(1) {
		int menu, x;
		printf("현재 data 수 : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)Enque (2)Deque (3)Peek (4)Print (5)Search (6)Clear (0)Terminate : ");
		scanf("%d", &menu);

		if(menu == 0) { break; }    // For 'Terminate'

		switch(menu) {
		case 1:    // Enque
			printf("Input data: ");
			scanf("%d", &x);
			if(Enque(&q, x) == -1) { puts("\a오류 : Enque 실패"); }
			break;

		case 2:    // Deque
			if(Deque(&q, &x) == -1) { puts("\a오류 : Deque 실패"); }
			else { printf("Deque data는 %d 입니다.\n", x); }
			break;

		case 3:    // Peek
			if(Peek(&q, &x) == -1) { puts("\a오류 : Peek 실패"); }
			else { printf("Peek data는 %d 입니다.\n", x); }
			break;

		case 4:    // Print
			printf("Queue :  (Front ~ Rear)  ");
			Print(&q);
			break;

		case 5:    // Search
			printf("Search data: ");
			scanf("%d", &x);
			int idx = Search(&q, x);
			if(idx == -1) { puts("\a오류 : Search 실패"); }
			else { printf("Search data는 Front에서 %d 번째에 있습니다.\n", idx +1); }
			break;

		case 6:    // Clear
			Clear(&q);
			puts("Queue cleared");
			break;

		default:
			break;
		}

		if(IsEmpty(&q) == 1) { puts("Queue가 비어있습니다."); }
		if(IsFull(&q) == 1) { puts("Queue가 가득 차있습니다."); }
		printf("\n");
	}
	Terminate(&q);
	return 0;
}
```
## p.160
>#### Q4, Q5
#### IntQueue.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/IntQueue.c)
#### IntQueue.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/IntQueue.h)
```C
#pragma once
#ifndef _Lu175_INT_QUEUE
#define _Lu175_INT_QUEUE

typedef struct {
	int max;    // Queue의 용량
	int num;    // 현재 data 수
	int front;    // 논리적인 순서에서 첫번째 index
	int rear;    // 논리적인 순서에서 마지막 요소 다음의 index
	int *que;    // Queue의 첫 요소에 대한 포인터
}IntQueue;

int Initialize(IntQueue *q, int max);    // Queue 초기화
int Enque(IntQueue *q, int x);    // Queue에 data를 enqueue
int Deque(IntQueue *q, int *x);    // Queue에서 data를 dequeue
int Peek(const IntQueue *q, int *x);    // Queue에서 data를 peak
void Clear(IntQueue *q);    // 모든 data 삭제
int Capacity(const IntQueue *q);    // Queue의 최대 용량
int Size(const IntQueue *q);    // Queue에 저장된 data 수
int IsEmpty(const IntQueue *q);    // Queue가 비어있는가?
int IsFull(const IntQueue *q);    // Queue가 가득 차있는가?

int Search(const IntQueue *q, int x);    // Queue에서 검색    // index 반환
int Search2(const IntQueue *q, int x);    // Queue에서 검색    // Front로부터 상대적 위치 반환

void Print(const IntQueue *q);    // 모든 data 출력
void Terminate(IntQueue *q);    // Queue 종료
#endif _Lu175_INT_QUEUE
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/4-Q5.c)
```C
// __________Add Search2 function to IntQueue__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntQueue.h"

int main(void) {
	IntQueue q;
	int queue_size;

	do {
		printf("Queue size: ");
		scanf("%d", &queue_size);
	} while(queue_size <= 0);    // 0 이하로 작성하면 retry

	if(Initialize(&q, queue_size) == -1) {
		puts("queue 생성 실패");
		return 1;
	}

	while(1) {
		int menu, x;
		printf("현재 data 수 : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)Enque (2)Deque (3)Peek (4)Print (5)Search (6)Search2 (7)Clear (0)Terminate : ");
		scanf("%d", &menu);

		if(menu == 0) { break; }    // For 'Terminate'

		switch(menu) {
		case 1:    // Enque
			printf("Input data: ");
			scanf("%d", &x);
			if(Enque(&q, x) == -1) { puts("\a오류 : Enque 실패"); }
			break;

		case 2:    // Deque
			if(Deque(&q, &x) == -1) { puts("\a오류 : Deque 실패"); }
			else { printf("Deque data는 %d 입니다.\n", x); }
			break;

		case 3:    // Peek
			if(Peek(&q, &x) == -1) { puts("\a오류 : Peek 실패"); }
			else { printf("Peek data는 %d 입니다.\n", x); }
			break;

		case 4:    // Print
			printf("Queue :  (Front ~ Rear)\n");
			Print(&q);
			break;

		case 5:    // Search
			printf("Search data: ");
			scanf("%d", &x);
			int idx = Search(&q, x);
			if(idx == -1) { puts("\a오류 : Search 실패"); }
			else { printf("Search data는 que[%d]에 있습니다.\n", idx); }
			break;

		case 6:    // Search2
			printf("Search2 data: ");
			scanf("%d", &x);
			int distance = Search2(&q, x);
			if(distance == -1) { puts("\a오류 : Search 실패"); }
			else { printf("Search2 data는 Front에서 %d 번째에 있습니다.\n", distance +1); }
			break;

		case 7:    // Clear
			Clear(&q);
			puts("Queue cleared");
			break;

		default:
			break;
		}

		if(IsEmpty(&q) == 1) { puts("Queue가 비어있습니다."); }
		if(IsFull(&q) == 1) { puts("Queue가 가득 차있습니다."); }
		printf("\n");
	}
	Terminate(&q);
	return 0;
}
```
>#### Q6
#### IntDeck.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/IntDeck.c)
#### IntDeck.h
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/IntDeck.h)
```C
#pragma once
#ifndef _Lu175_INT_DECK
#define _Lu175_INT_DECK

typedef struct {
	int max;    // Queue의 용량
	int num;    // 현재 data 수
	int front;    // 논리적인 순서에서 첫번째 index
	int rear;    // 논리적인 순서에서 마지막 요소 다음의 index
	int *deck;    // Queue의 첫 요소에 대한 포인터
}IntDeck;

int Initialize(IntDeck *d, int max);    // Queue 초기화

int R_Enque(IntDeck *d, int x);    // Rear에서 data를 enqueue
int F_Enque(IntDeck *d, int x);    // Front에서 data를 enqueue

int F_Deque(IntDeck *d, int *x);    // Front에서 data를 dequeue
int R_Deque(IntDeck *d, int *x);    // Rear에서 data를 dequeue

int F_Peek(const IntDeck *d, int *x);    // Front에서 data를 peak
int R_Peek(const IntDeck *d, int *x);    // Rear에서 data를 peak

void Clear(IntDeck *d);    // 모든 data 삭제
int Capacity(const IntDeck *d);    // Queue의 최대 용량
int Size(const IntDeck *d);    // Queue에 저장된 data 수
int IsEmpty(const IntDeck *d);    // Queue가 비어있는가?
int IsFull(const IntDeck *d);    // Queue가 가득 차있는가?

int Search(const IntDeck *d, int x);    // Queue에서 검색    // index 반환
int Search2(const IntDeck *d, int x);    // Queue에서 검색    // Front로부터 상대적 위치 반환

void Print(const IntDeck *d);    // 모든 data 출력
void Terminate(IntDeck *d);    // Queue 종료
#endif _Lu175_INT_DECK
```
#### main.c
#### [Code link](https://github.com/Lu175/Algorithm/blob/master/Code_repo/Chapter_04/4-Q6.c)
```C
// __________Deck: double ended queue__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntDeck.h"

int main(void) {
	IntDeck d;
	int deck_size;

	do {
		printf("Deck size: ");
		scanf("%d", &deck_size);
	} while(deck_size <= 0);    // 0 이하로 작성하면 retry

	if(Initialize(&d, deck_size) == -1) {
		puts("deck 생성 실패");
		return 1;
	}

	while(1) {
		int menu1, menu2, x;
		putchar('\n');
		printf("현재 data 수 : %d / %d\n", Size(&d), Capacity(&d));
		printf("[Menu 1]   (1)Enque (2)Deque (3)Peek (4)Print (5)Search (6)Search2 (7)Clear (0)Terminate : ");
		scanf("%d", &menu1);

		if(menu1 == 0) { break; }    // For 'Terminate'
		else if(menu1 == 1 || menu1 == 2 || menu1 == 3) {
			printf("[Menu 2]   (1)Front (2)Rear (0)Go to [Menu 1] : ");
			scanf("%d", &menu2);
			if(menu2 == 0) { continue; }    // Go to Menu 1
		}

		switch(menu1) {
		case 1:    // Enque
			if(menu2 == 1) {    // Front
				printf("Input data: ");
				scanf("%d", &x);
				if(F_Enque(&d, x) == -1) { puts("\a오류 : F_Enque 실패"); }
				break;
			}
			if(menu2 == 2) {    // Rear
				printf("Input data: ");
				scanf("%d", &x);
				if(R_Enque(&d, x) == -1) { puts("\a오류 : R_Enque 실패"); }
				break;
			}

		case 2:    // Deque
			if(menu2 == 1) {    // Front
				if(F_Deque(&d, &x) == -1) { puts("\a오류 : F_Deque 실패"); }
				else { printf("F_Deque data는 %d 입니다.\n", x); }
				break;
			}
			if(menu2 == 2) {    // Rear
				if(R_Deque(&d, &x) == -1) { puts("\a오류 : R_Deque 실패"); }
				else { printf("R_Deque data는 %d 입니다.\n", x); }
				break;
			}

		case 3:    // Peek
			if(menu2 == 1) {    // Front
				if(F_Peek(&d, &x) == -1) { puts("\a오류 : F_Peek 실패"); }
				else { printf("F_Peek data는 %d 입니다.\n", x); }
				break;
			}
			if(menu2 == 2) {    // Rear
				if(R_Peek(&d, &x) == -1) { puts("\a오류 : R_Peek 실패"); }
				else { printf("R_Peek data는 %d 입니다.\n", x); }
				break;
			}

		case 4:    // Print
			printf("Deck :  (Front ~ Rear)\n");
			Print(&d);
			break;

		case 5:    // Search
			printf("Search data: ");
			scanf("%d", &x);
			int idx = Search(&d, x);
			if(idx == -1) { puts("\a오류 : Search 실패"); }
			else { printf("Search data는 que[%d]에 있습니다.\n", idx); }
			break;

		case 6:    // Search2
			printf("Search2 data: ");
			scanf("%d", &x);
			int distance = Search2(&d, x);
			if(distance == -1) { puts("\a오류 : Search 실패"); }
			else { printf("Search2 data는 Front에서 %d 번째에 있습니다.\n", distance +1); }
			break;

		case 7:    // Clear
			Clear(&d);
			puts("Deck cleared");
			break;

		default:
			break;
		}

		if(IsEmpty(&d) == 1) { puts("Deck이 비어있습니다."); }
		if(IsFull(&d) == 1) { puts("Deck이 가득 차있습니다."); }
		printf("\n");
	}
	Terminate(&d);
	return 0;
}
```
