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
//	} while(deck_size <= 0);    // 0 이하로 작성하면 retry
//
//	if(Initialize(&d, deck_size) == -1) {
//		puts("deck 생성 실패");
//		return 1;
//	}
//
//	while(1) {
//		int menu1, menu2, x;
//		putchar('\n');
//		printf("현재 data 수 : %d / %d\n", Size(&d), Capacity(&d));
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
//				if(F_Enque(&d, x) == -1) { puts("\a오류 : F_Enque 실패"); }
//				break;
//			}
//			if(menu2 == 2) {    // Rear
//				printf("Input data: ");
//				scanf("%d", &x);
//				if(R_Enque(&d, x) == -1) { puts("\a오류 : R_Enque 실패"); }
//				break;
//			}
//
//		case 2:    // Deque
//			if(menu2 == 1) {    // Front
//				if(F_Deque(&d, &x) == -1) { puts("\a오류 : F_Deque 실패"); }
//				else { printf("F_Deque data는 %d 입니다.\n", x); }
//				break;
//			}
//			if(menu2 == 2) {    // Rear
//				if(R_Deque(&d, &x) == -1) { puts("\a오류 : R_Deque 실패"); }
//				else { printf("R_Deque data는 %d 입니다.\n", x); }
//				break;
//			}
//
//		case 3:    // Peek
//			if(menu2 == 1) {    // Front
//				if(F_Peek(&d, &x) == -1) { puts("\a오류 : F_Peek 실패"); }
//				else { printf("F_Peek data는 %d 입니다.\n", x); }
//				break;
//			}
//			if(menu2 == 2) {    // Rear
//				if(R_Peek(&d, &x) == -1) { puts("\a오류 : R_Peek 실패"); }
//				else { printf("R_Peek data는 %d 입니다.\n", x); }
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
//			if(idx == -1) { puts("\a오류 : Search 실패"); }
//			else { printf("Search data는 que[%d]에 있습니다.\n", idx); }
//			break;
//
//		case 6:    // Search2
//			printf("Search2 data: ");
//			scanf("%d", &x);
//			int distance = Search2(&d, x);
//			if(distance == -1) { puts("\a오류 : Search 실패"); }
//			else { printf("Search2 data는 Front에서 %d 번째에 있습니다.\n", distance +1); }
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
//		if(IsEmpty(&d) == 1) { puts("Deck이 비어있습니다."); }
//		if(IsFull(&d) == 1) { puts("Deck이 가득 차있습니다."); }
//		printf("\n");
//	}
//	Terminate(&d);
//	return 0;
//}