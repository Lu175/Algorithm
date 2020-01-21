// __________Get only last N data__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10

int main(void) {
	int i, retry;
	int a[N];    // input data 저장
	int count = 0;    // input data 수

	puts("정수를 입력하세요.");
	do {
		printf("%2d번째 정수 : ", count + 1);
		scanf("%d", &a[count++ % N]);    // Ring buffer process
		printf("계속할까요?  (Yes... 1 / No... 0) : ");
		scanf("%d", &retry);
	} while(retry == 1);

	i = count - N;
	if(i < 0) { i = 0; }
	for(; i < count; i++) {
		printf("%2d번째 정수 = %d\n", i +1, a[i % N]);
	}
	return 0;
}