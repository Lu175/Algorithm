// _________�迭 ����� �ִ� ���ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n);

int main(void) {
	int i;
	int* height;
	int number;

	printf("��� ��: ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int));
	if (height == NULL) {
		puts("�޸� Ȯ�� ���� !");
	}
	else {
		printf("%d ����� Ű�� �Է��ϼ���.\n", number);
		for (i = 0; i < number; i++) {
			printf("height[%d]: ", i);
			scanf("%d", &height[i]);
		}
		printf("�ִ밪�� %d�Դϴ�.\n", maxof(height, number));
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