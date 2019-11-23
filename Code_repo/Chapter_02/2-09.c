// _________¼Ò¼ö ³ª¿­ÇÏ±â__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INPUT_NUM 1000

int main(void) {
	int tNum, mNum;    // test Num, mod Num
	unsigned int modCount = 0;

	for (tNum = 2; tNum <= INPUT_NUM; tNum++) {
		for (mNum = 2; mNum < tNum; mNum++) {
			modCount++;
			if ((tNum % mNum) == 0) { break; }
		}
		if (tNum == mNum) { printf("%d\n", tNum); }
	}
	printf("³ª´°¼ÀÀ» ½ÇÇàÇÑ È½¼ö: %d", modCount);

	return 0;
}