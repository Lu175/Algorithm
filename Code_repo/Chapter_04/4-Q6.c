//// __________Deck: double ended queue__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include "IntDeck.h"
//
//int main(void) {
//	IntDeck d;
//	int deck_size;
//
//	do {
//		printf("Deck size: ");
//		scanf("%d", &deck_size);
//	} while(deck_size <= 0);    // 0 ���Ϸ� �ۼ��ϸ� retry
//
//	if(Initialize(&d, deck_size) == -1) {
//		puts("deck ���� ����");
//		return 1;
//	}
//
//	while(1) {
//		int menu1, menu2, x;
//		putchar('\n');
//		printf("���� data �� : %d / %d\n", Size(&d), Capacity(&d));
//		printf("[Menu 1]   (1)Enque (2)Deque (3)Peek (4)Print (5)Search (6)Search2 (7)Clear (0)Terminate : ");
//		scanf("%d", &menu1);
//
//		if(menu1 == 0) { break; }    // For 'Terminate'
//		else if(menu1 == 1 || menu1 == 2 || menu1 == 3) {
//			printf("[Menu 2]   (1)Front (2)Rear (0)Go to [Menu 1] : ");
//			scanf("%d", &menu2);
//			if(menu2 == 0) { continue; }    // Go to Menu 1
//		}
//
//		switch(menu1) {
//		case 1:    // Enque
//			if(menu2 == 1) {    // Front
//				printf("Input data: ");
//				scanf("%d", &x);
//				if(F_Enque(&d, x) == -1) { puts("\a���� : F_Enque ����"); }
//				break;
//			}
//			if(menu2 == 2) {    // Rear
//				printf("Input data: ");
//				scanf("%d", &x);
//				if(R_Enque(&d, x) == -1) { puts("\a���� : R_Enque ����"); }
//				break;
//			}
//
//		case 2:    // Deque
//			if(menu2 == 1) {    // Front
//				if(F_Deque(&d, &x) == -1) { puts("\a���� : F_Deque ����"); }
//				else { printf("F_Deque data�� %d �Դϴ�.\n", x); }
//				break;
//			}
//			if(menu2 == 2) {    // Rear
//				if(R_Deque(&d, &x) == -1) { puts("\a���� : R_Deque ����"); }
//				else { printf("R_Deque data�� %d �Դϴ�.\n", x); }
//				break;
//			}
//
//		case 3:    // Peek
//			if(menu2 == 1) {    // Front
//				if(F_Peek(&d, &x) == -1) { puts("\a���� : F_Peek ����"); }
//				else { printf("F_Peek data�� %d �Դϴ�.\n", x); }
//				break;
//			}
//			if(menu2 == 2) {    // Rear
//				if(R_Peek(&d, &x) == -1) { puts("\a���� : R_Peek ����"); }
//				else { printf("R_Peek data�� %d �Դϴ�.\n", x); }
//				break;
//			}
//
//		case 4:    // Print
//			printf("Deck :  (Front ~ Rear)\n");
//			Print(&d);
//			break;
//
//		case 5:    // Search
//			printf("Search data: ");
//			scanf("%d", &x);
//			int idx = Search(&d, x);
//			if(idx == -1) { puts("\a���� : Search ����"); }
//			else { printf("Search data�� que[%d]�� �ֽ��ϴ�.\n", idx); }
//			break;
//
//		case 6:    // Search2
//			printf("Search2 data: ");
//			scanf("%d", &x);
//			int distance = Search2(&d, x);
//			if(distance == -1) { puts("\a���� : Search ����"); }
//			else { printf("Search2 data�� Front���� %d ��°�� �ֽ��ϴ�.\n", distance +1); }
//			break;
//
//		case 7:    // Clear
//			Clear(&d);
//			puts("Deck cleared");
//			break;
//
//		default:
//			break;
//		}
//
//		if(IsEmpty(&d) == 1) { puts("Deck�� ����ֽ��ϴ�."); }
//		if(IsFull(&d) == 1) { puts("Deck�� ���� ���ֽ��ϴ�."); }
//		printf("\n");
//	}
//	Terminate(&d);
//	return 0;
//}