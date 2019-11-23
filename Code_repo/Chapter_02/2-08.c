// _________기수 변환하기__________
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

	puts("10진수를 기수 변환합니다.");
	do {
		printf("변환하는 음이 아닌 정수: ");
		scanf("%u", &originNum);
		do {
			printf("어떤 진수로 변환할까요?(2-36): ");
			scanf("%d", &convBase);
		} while ((convBase < 2) || (convBase > 36));
		convNum_digits = baseConvert_r(originNum, convBase, restBuffer);
		printf("%d진수로는", convBase);
		for (i = convNum_digits - 1; i >= 0; i--) {
			printf("%c", restBuffer[i]);
		}
		printf("입니다.\n");
		printf("한 번 더 할까요?(1...예 / 0...아니오) : ");
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

	return digits;    // 변환된 수의 자릿수 반환
}