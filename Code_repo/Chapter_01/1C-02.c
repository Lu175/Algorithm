 __________2자리 양수로 제한하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int no;

	printf("2자리 정수를 입력하세요.\n");
	do {
		printf("수는: ");
		scanf("%d", &no);
	} while (no < 10 || no > 99);
	printf("변수 no값은 %d이 되었습니다.\n", no);

	return 0;
}