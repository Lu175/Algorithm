// _________���簢�� ����ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j, h, w;

	puts("���簢���� ����մϴ�.");
	i = 0; j = 0;
	do {
		if (i) puts("����� �Է��ϼ���!!");
		printf("����: ");
		scanf("%d", &h);
		i++;
	} while (h <= 0);
	do {
		if (j) puts("����� �Է��ϼ���!!");
		printf("�ʺ�: ");
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