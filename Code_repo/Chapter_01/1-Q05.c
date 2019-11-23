// __________�� ���� �߾Ӱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ----------------------------------------
//  �� �ڵ��� med3�Լ��� �ּ� 7���� �񱳸� �ϴ� �ݸ�,
//	1C-1.c�� med3�Լ��� �ִ� 3���� �񱳸� �ϱ� ������
//	�� �ڵ��� med3�Լ��� ��ȿ�����̴�.
// ----------------------------------------

int med3(int a, int b, int c) {
	if ((b >= a && c <= a) || (b <= a && c >= a))
		return a;
	else if ((a > b && c < b) || (a < b && c > b))
		return b;
	else
		return c;
}

int main(void) {
	printf("med3(%d, %d, %d) = %d\n", 3, 2, 1, med3(3, 2, 1));
	printf("med3(%d, %d, %d) = %d\n", 3, 2, 2, med3(3, 2, 2));
	printf("med3(%d, %d, %d) = %d\n", 3, 1, 2, med3(3, 1, 2));
	printf("med3(%d, %d, %d) = %d\n", 3, 2, 3, med3(3, 2, 3));
	printf("med3(%d, %d, %d) = %d\n", 2, 1, 3, med3(2, 1, 3));
	printf("med3(%d, %d, %d) = %d\n", 3, 3, 2, med3(3, 3, 2));
	printf("med3(%d, %d, %d) = %d\n", 3, 3, 3, med3(3, 3, 3));
	printf("med3(%d, %d, %d) = %d\n", 2, 2, 3, med3(2, 2, 3));
	printf("med3(%d, %d, %d) = %d\n", 2, 3, 1, med3(2, 3, 1));
	printf("med3(%d, %d, %d) = %d\n", 2, 3, 2, med3(2, 3, 2));
	printf("med3(%d, %d, %d) = %d\n", 1, 3, 2, med3(1, 3, 2));
	printf("med3(%d, %d, %d) = %d\n", 2, 3, 3, med3(2, 3, 3));
	printf("med3(%d, %d, %d) = %d\n", 1, 2, 3, med3(1, 2, 3));

	return 0;
}