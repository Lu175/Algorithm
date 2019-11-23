// _________소수 나열하기 (계산량 줄이기)__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INPUT_NUM 1000

int main(void) {
	int tNum, mNumIdx;    // test Num, mod Num Index
	int prime[500];
	int ptr = 0;       // 이미 얻은 소수의 개수
	unsigned int counter = 0;    // 곱셈과 나눗셈을 실행한 횟수

	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (tNum = 5; tNum <= INPUT_NUM; tNum += 2) {    // 홀수만 조사
		int noPrimeFlag = 0;
		for (mNumIdx = 1; counter++, (prime[mNumIdx] * prime[mNumIdx]) <= tNum; mNumIdx++) {
			counter++;
			if ((tNum % prime[mNumIdx]) == 0) {    // 소수 X라면 실행
				noPrimeFlag = 1;
				break;
			}
		}
		if (!noPrimeFlag) { prime[ptr++] = tNum; }    // 소수 O라면 실행
	}
	for (mNumIdx = 0; mNumIdx < ptr; mNumIdx++) {
		printf("%d\n", prime[mNumIdx]);
	}
	printf("곱셈과 나눗셈을 실행한 횟수: %lu", counter);

	return 0;
}