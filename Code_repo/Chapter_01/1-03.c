// __________���� �Ǵܰ� �б�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;

	printf("������ �Է��ϼ���: ");
	scanf("%d", &n);

	if (n > 0) {
		printf("�� ���� ����Դϴ�.\n");
	}
	else if (n < 0) {
		printf("�� ���� �����Դϴ�.\n");
	}
	else
		printf("�� ���� 0�Դϴ�.\n");

	return 0;
}