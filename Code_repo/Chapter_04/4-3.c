//// __________IntStack test__________
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include "IntStack.h"
//
//int main(void) {
//	IntStack s;
//	if(Initialize(&s, 64) == -1) {
//		puts("stack 생성 실패");
//		return 1;
//	}
//
//	while(1) {
//		int menu, x;
//		printf("현재 data 수 : %d / %d\n", Size(&s), Capacity(&s));
//		printf("(1)Push (2)Pop (3)Peek (4)Print (0)Terminate : ");
//		scanf("%d", &menu);
//
//		if(menu == 0) { break; }    // For 'Terminate'
//
//		switch(menu) {
//		case 1:    // Push
//			printf("data: ");
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
//			Print(&s);
//			break;
//		}
//		printf("\n");
//	}
//	Terminate(&s);
//	return 0;
//}