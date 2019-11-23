// _________���� ����ؼ� �迭 ��ڰ� �����ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
void ary_reverse(int a[], int n);

int main(void) {
	int i;
	int* x;
	int nx;

	printf("��� ����: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	if (x == NULL) {
		puts("�޸� Ȯ�� ���� !");
	}
	else {
		srand(time(NULL));
		for (i = 0; i < nx; i++) {
			x[i] = rand() % 100;
			printf("x[%d] = %d\n", i, x[i]);
		}
		ary_reverse(x, nx);
		printf("\n�迭�� ��Ҹ� �������� �����߽��ϴ�.\n");
		for (i = 0; i < nx; i++) {
			printf("x[%d] = %d\n", i, x[i]);
		}
		free(x);
	}

	return 0;
}


void ary_reverse(int a[], int n) {
	int i;
	for (i = 0; i < (n / 2); i++) {
		swap(int, a[i], a[n - 1 - i]);
	}
}