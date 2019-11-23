// _________��� ��ȯ�ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int baseConvert_r(unsigned decimal, int convBase, char rest[]);

int main(void) {
	int i;
	unsigned originNum;
	int convBase;
	int convNum_digits;
	char restBuffer[512];
	int retryFlag;

	puts("10������ ��� ��ȯ�մϴ�.");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ����: ");
		scanf("%u", &originNum);
		do {
			printf("� ������ ��ȯ�ұ��?(2-36): ");
			scanf("%d", &convBase);
		} while ((convBase < 2) || (convBase > 36));
		convNum_digits = baseConvert_r(originNum, convBase, restBuffer);
		printf("%d�����δ�", convBase);
		for (i = convNum_digits - 1; i >= 0; i--) {
			printf("%c", restBuffer[i]);
		}
		printf("�Դϴ�.\n");
		printf("�� �� �� �ұ��?(1...�� / 0...�ƴϿ�) : ");
		scanf("%d", &retryFlag);
	} while (retryFlag == 1);

	return 0;
}


int baseConvert_r(unsigned decimal, int baseNum, char rest[]) {
	char dchar[] = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	int digits = 0;

	if (decimal == 0) {
		rest[digits++] = dchar[0];
	}
	else {
		while (decimal) {
			rest[digits++] = dchar[decimal % baseNum];
			decimal /= baseNum;
		}
	}

	return digits;    // ��ȯ�� ���� �ڸ��� ��ȯ
}