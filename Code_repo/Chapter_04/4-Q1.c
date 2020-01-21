//// __________Use IntStack__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include "IntStack.h"
//
//int main(void) {
//	IntStack s;
//	int stack_size;
//
//	do {
//		printf("Stack size: ");
//		scanf("%d", &stack_size);
//	} while(stack_size <= 0);    // 0 이하로 작성하면 retry
//
//	if(Initialize(&s, stack_size) == -1) {
//		puts("stack 생성 실패");
//		return 1;
//	}
//
//	while(1) {
//		int menu, x;
//		printf("현재 data 수 : %d / %d\n", Size(&s), Capacity(&s));
//		printf("(1)Push (2)Pop (3)Peek (4)Print (5)Search (6)Clear (0)Terminate : ");
//		scanf("%d", &menu);
//
//		if(menu == 0) { break; }    // For 'Terminate'
//
//		switch(menu) {
//		case 1:    // Push
//			printf("Input data: ");
//			scanf("%d", &x);
//			if(Push(&s, x) == -1) { puts("\a오류 : Push 실패"); }
//			break;
//
//		case 2:    // Pop
//			if(Pop(&s, &x) == -1) { puts("\a오류 : Pop 실패"); }
//			else { printf("Pop data는 %d 입니다.\n", x); }
//			break;
//
//		case 3:    // Peek
//			if(Peek(&s, &x) == -1) { puts("\a오류 : Peek 실패"); }
//			else { printf("Peek data는 %d 입니다.\n", x); }
//			break;
//
//		case 4:    // Print
//			printf("Stack :  (Bottom ~ Top)  ");
//			Print(&s);
//			break;
//
//		case 5:    // Search
//			printf("Search data: ");
//			scanf("%d", &x);
//			int idx = Search(&s, x);
//			if(idx == -1) { puts("\a오류 : Search 실패"); }
//			else { printf("Search data는 top에서 %d 번째에 있습니다.\n", Size(&s) - idx); }
//			break;
//
//		case 6:    // Clear
//			Clear(&s);
//			puts("Stack cleared");
//			break;
//
//		default:
//			break;
//		}
//
//		if(IsEmpty(&s) == 1) { puts("Stack이 비어있습니다."); }
//		if(IsFull(&s) == 1) { puts("Stack이 가득 차있습니다."); }
//		printf("\n");
//	}
//	Terminate(&s);
//	return 0;
//}