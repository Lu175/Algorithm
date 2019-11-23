// _________배열 요소의 최댓값 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n);

int main(void) {
	int i;
	int* height;
	int number;

	printf("사람 수: ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int));
	if (height == NULL) {
		puts("메모리 확보 실패 !");
	}
	else {
		printf("%d 사람의 키를 입력하세요.\n", number);
		for (i = 0; i < number; i++) {
			printf("height[%d]: ", i);
			scanf("%d", &height[i]);
		}
		printf("최대값은 %d입니다.\n", maxof(height, number));
		free(height);
	}

	return 0;
}

int maxof(const int a[], int n) {
	int i;
	int max = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > max) { max = a[i]; }
	}
	return max;
}