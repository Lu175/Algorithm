// _________�Ҽ� �����ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int tNum, mNum, inNum;    // test Num, mod Num, input Num
	unsigned int modCount = 0;

	puts("����� �Ҽ��� ������ �����մϴ�.");
	do {
		printf("����: ");
		scanf("%d", &inNum);
	} while (inNum <= 0);
	printf("�ڿ��� �� %d������ �Ҽ��� ����մϴ�.\n\n", inNum);

	for (tNum = 2; tNum <= inNum; tNum++) {
		// tNum�� 2���� mNum-1���� ������ loop
		mNum = 2;
		while (1) {
			if (tNum == mNum) {
				printf("%d\n", tNum);
				break;
			}
			modCount++;
			if ((tNum % mNum) == 0) {    // �Ҽ� X
				break;
			}
			mNum++;
		}
	}
	printf("�������� ������ Ƚ��: %d", modCount);

	return 0;
}