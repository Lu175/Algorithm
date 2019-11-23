// _________�Ҽ� �����ϱ� (��귮 ���̱�)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INPUT_NUM 1000

int main(void) {
	int tNum, mNumIdx;    // test Num, mod Num Index
	int prime[500];
	int ptr = 0;       // �̹� ���� �Ҽ��� ����
	unsigned int counter = 0;    // ������ �������� ������ Ƚ��

	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (tNum = 5; tNum <= INPUT_NUM; tNum += 2) {    // Ȧ���� ����
		int noPrimeFlag = 0;
		for (mNumIdx = 1; counter++, (prime[mNumIdx] * prime[mNumIdx]) <= tNum; mNumIdx++) {
			counter++;
			if ((tNum % prime[mNumIdx]) == 0) {    // �Ҽ� X��� ����
				noPrimeFlag = 1;
				break;
			}
		}
		if (!noPrimeFlag) { prime[ptr++] = tNum; }    // �Ҽ� O��� ����
	}
	for (mNumIdx = 0; mNumIdx < ptr; mNumIdx++) {
		printf("%d\n", prime[mNumIdx]);
	}
	printf("������ �������� ������ Ƚ��: %lu", counter);

	return 0;
}