// _________소수 나열하기 (계산량 줄이기)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INPUT_NUM 1000

int main(void) {
	int tNum, mNumIdx;    // test Num, mod Num Index
	int prime[500];
	int ptr = 0;       // 이미 얻은 소수의 개수
	unsigned int modCount = 0;

	prime[ptr++] = 2;
	for (tNum = 3; tNum <= INPUT_NUM; tNum += 2) {
		for (mNumIdx = 1; mNumIdx < ptr; mNumIdx++) {
			modCount++;
			if ((tNum % prime[mNumIdx]) == 0) { break; }    // 소수 X
		}
		if (ptr == mNumIdx) { prime[ptr++] = tNum; }
	}
	for (mNumIdx = 0; mNumIdx < ptr; mNumIdx++) {
		printf("%d\n", prime[mNumIdx]);
	}
	printf("나눗셈을 실행한 횟수: %d", modCount);

	return 0;
}