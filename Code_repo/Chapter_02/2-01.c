// _________�迭__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 5

int main(void) {
	int i;
	int a[N];

	for (i = 0; i < N; i++) {
		printf("a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	puts("�� ����� ��");
	for (i = 0; i < N; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}