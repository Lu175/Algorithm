// _________�迭 ����� ��� ���ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double avgof(const int set[], int elementNum);

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
		printf("��� Ű�� ���� %f�Դϴ�.\n", avgof(height, number));
		free(height);
	}

	return 0;
}

double avgof(const int set[], int elementNum) {
	int i;
	int sum = set[0];
	int avg;
	for (i = 1; i < elementNum; i++) {
		sum += set[i];
	}
	avg = sum / elementNum;
	return avg;
}