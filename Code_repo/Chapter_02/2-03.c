// _________�޸� ���� �Ҵ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* x;
	x = calloc(1, sizeof(int));
	if (x == NULL) {
		puts("�޸� �Ҵ翡 �����߽��ϴ�.");
	}
	else {
		*x = 57;
		printf("*x = %d\n", *x);
		free(x);
	}

	return 0;
}