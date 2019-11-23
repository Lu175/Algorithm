// _________직사각형 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j, h, w;

	puts("직사각형을 출력합니다.");
	i = 0; j = 0;
	do {
		if (i) puts("양수를 입력하세요!!");
		printf("높이: ");
		scanf("%d", &h);
		i++;
	} while (h <= 0);
	do {
		if (j) puts("양수를 입력하세요!!");
		printf("너비: ");
		scanf("%d", &w);
		j++;
	} while (w <= 0);

	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			printf(" *");
		}
		putchar('\n');
	}

	return 0;
}