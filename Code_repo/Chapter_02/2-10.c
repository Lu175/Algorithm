// _________�Ҽ� �����ϱ� (��귮 ���̱�)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INPUT_NUM 1000

int main(void) {
	int tNum, mNumIdx;    // test Num, mod Num Index
	int prime[500];
	int ptr = 0;       // �̹� ���� �Ҽ��� ����
	unsigned int modCount = 0;

	prime[ptr++] = 2;
	for (tNum = 3; tNum <= INPUT_NUM; tNum += 2) {
		for (mNumIdx = 1; mNumIdx < ptr; mNumIdx++) {
			modCount++;
			if ((tNum % prime[mNumIdx]) == 0) { break; }    // �Ҽ� X
		}
		if (ptr == mNumIdx) { prime[ptr++] = tNum; }
	}
	for (mNumIdx = 0; mNumIdx < ptr; mNumIdx++) {
		printf("%d\n", prime[mNumIdx]);
	}
	printf("�������� ������ Ƚ��: %d", modCount);

	return 0;
}