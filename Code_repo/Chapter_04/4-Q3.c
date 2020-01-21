//// __________Use ArrayIntQueue__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include "ArrayIntQueue.h"
//
//int main(void) {
//	ArrayIntQueue q;
//	int queue_size;
//
//	do {
//		printf("Queue size: ");
//		scanf("%d", &queue_size);
//	} while(queue_size <= 0);    // 0 ���Ϸ� �ۼ��ϸ� retry
//
//	if(Initialize(&q, queue_size) == -1) {
//		puts("queue ���� ����");
//		return 1;
//	}
//
//	while(1) {
//		int menu, x;
//		printf("���� data �� : %d / %d\n", Size(&q), Capacity(&q));
//		printf("(1)Enque (2)Deque (3)Peek (4)Print (5)Search (6)Clear (0)Terminate : ");
//		scanf("%d", &menu);
//
//		if(menu == 0) { break; }    // For 'Terminate'
//
//		switch(menu) {
//		case 1:    // Enque
//			printf("Input data: ");
//			scanf("%d", &x);
//			if(Enque(&q, x) == -1) { puts("\a���� : Enque ����"); }
//			break;
//
//		case 2:    // Deque
//			if(Deque(&q, &x) == -1) { puts("\a���� : Deque ����"); }
//			else { printf("Deque data�� %d �Դϴ�.\n", x); }
//			break;
//
//		case 3:    // Peek
//			if(Peek(&q, &x) == -1) { puts("\a���� : Peek ����"); }
//			else { printf("Peek data�� %d �Դϴ�.\n", x); }
//			break;
//
//		case 4:    // Print
//			printf("Queue :  (Front ~ Rear)  ");
//			Print(&q);
//			break;
//
//		case 5:    // Search
//			printf("Search data: ");
//			scanf("%d", &x);
//			int idx = Search(&q, x);
//			if(idx == -1) { puts("\a���� : Search ����"); }
//			else { printf("Search data�� Front���� %d ��°�� �ֽ��ϴ�.\n", idx +1); }
//			break;
//
//		case 6:    // Clear
//			Clear(&q);
//			puts("Queue cleared");
//			break;
//
//		default:
//			break;
//		}
//
//		if(IsEmpty(&q) == 1) { puts("Queue�� ����ֽ��ϴ�."); }
//		if(IsFull(&q) == 1) { puts("Queue�� ���� ���ֽ��ϴ�."); }
//		printf("\n");
//	}
//	Terminate(&q);
//	return 0;
//}