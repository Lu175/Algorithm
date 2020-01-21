//// __________Use IntStack2__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include "IntStack2.h"
//
//int main(void) {
//	IntStack2 s;
//	int stack_Size;
//
//	do {
//		printf("Stack size: ");
//		scanf("%d", &stack_Size);
//	} while(stack_Size <= 0);    // 0 이하로 작성하면 retry
//
//	if(Initialize(&s, stack_Size) == -1) {
//		puts("stack 생성 실패");
//		return 1;
//	}
//
//	while(1) {
//		int menu1, menu2, x;
//		printf("\n");
//		printf("Stack A : %d / %d\n", A_Size(&s), Capacity(&s) - B_Size(&s));
//		printf("Stack B : %d / %d\n", B_Size(&s), Capacity(&s) - A_Size(&s));
//		printf("[Menu 1]  (1)Stack A (2)Stack B (3)Print stacks (0)Terminate: ");
//		scanf("%d", &menu1);
//
//		if(menu1 == 0) { break; }    // For 'Terminate'
//
//		if(menu1 == 1) {    // Stack A
//			printf("In Stack A...");
//			printf("[Menu 2]  (1)Push (2)Pop (3)Peek (4)Search (5)Clear (0)Go to [Menu 1] : ");
//			scanf("%d", &menu2);
//
//			if(menu2 == 0) { continue; }    // For 'Go to Menu 1'
//
//			switch(menu2) {
//			case 1:    // Push A
//				printf("Input data: ");
//				scanf("%d", &x);
//				if(A_Push(&s, x) == -1) { puts("\a오류 : Push 실패"); }
//				break;
//
//			case 2:    // Pop A
//				if(A_Pop(&s, &x) == -1) { puts("\a오류 : Pop 실패"); }
//				else { printf("Pop data는 %d 입니다.\n", x); }
//				break;
//
//			case 3:    // Peek A
//				if(A_Peek(&s, &x) == -1) { puts("\a오류 : Peek 실패"); }
//				else { printf("Stack A의 Peek data는 %d 입니다.\n", x); }
//				break;
//
//			case 4:    // Search A
//				printf("Search data: ");
//				scanf("%d", &x);
//				int idx = A_Search(&s, x);
//				if(idx == -1) { puts("\a오류 : Search 실패"); }
//				else { printf("Stack A의 top에서 %d 번째에 있습니다.\n", idx); }
//				break;
//
//			case 5:    // Clear A
//				A_Clear(&s);
//				puts("Stack A cleared");
//				break;
//			}
//		}
//
//		if(menu1 == 2) {    // Stack B
//			printf("In Stack B...");
//			printf("[Menu 2]  (1)Push (2)Pop (3)Peek (4)Search (5)Clear (0)Go to [Menu 1] : ");
//			scanf("%d", &menu2);
//
//			if(menu2 == 0) { continue; }    // For 'Go to Menu 1'
//
//			switch(menu2) {
//			case 1:    // Push B
//				printf("Input data: ");
//				scanf("%d", &x);
//				if(B_Push(&s, x) == -1) { puts("\a오류 : Push 실패"); }
//				break;
//
//			case 2:    // Pop B
//				if(B_Pop(&s, &x) == -1) { puts("\a오류 : Pop 실패"); }
//				else { printf("Pop data는 %d 입니다.\n", x); }
//				break;
//
//			case 3:    // Peek B
//				if(B_Peek(&s, &x) == -1) { puts("\a오류 : Peek 실패"); }
//				else { printf("Stack B의 Peek data는 %d 입니다.\n", x); }
//				break;
//
//			case 4:    // Search B
//				printf("Search data: ");
//				scanf("%d", &x);
//				int idx = B_Search(&s, x);
//				if(idx == -1) { puts("\a오류 : Search 실패"); }
//				else { printf("Stack B의 top에서 %d 번째에 있습니다.\n", idx); }
//				break;
//
//			case 5:    // Clear B
//				B_Clear(&s);
//				puts("Stack B cleared");
//				break;
//
//			default:
//				break;
//			}
//		}
//
//		if(menu1 == 3) {    // Print stacks
//			printf("Stack A :  (Bottom ~ Top)  ");
//			A_Print(&s);
//			printf("Stack B :  (Top ~ Bottom)  ");
//			B_Print(&s);
//		}
//
//		if(A_IsEmpty(&s) == 1) { puts("Stack A가 비어있습니다."); }
//		if(B_IsEmpty(&s) == 1) { puts("Stack B가 비어있습니다."); }
//		if(IsFull(&s) == 1) { puts("Stack이 가득 차있습니다."); }
//	}
//
//	Terminate(&s);
//	return 0;
//}