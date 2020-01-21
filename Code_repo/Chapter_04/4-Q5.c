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