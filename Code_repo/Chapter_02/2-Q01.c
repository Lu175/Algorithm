// _________�迭 ����� �ּڰ� ���ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int minof(const int set[], int elementNum);

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
		printf("�ּڰ��� %d�Դϴ�.\n", minof(height, number));
		free(height);
	}

	return 0;
}

int minof(const int set[], int elementNum) {
	int i;
	int min = set[0];
	for (i = 1; i < elementNum; i++) {
		if (set[i] < min) { min = set[i]; }
	}
	return min;
}