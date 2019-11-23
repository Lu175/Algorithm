// __________세 값의 중앙값__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ----------------------------------------
//  이 코드의 med3함수는 최소 7번의 비교를 하는 반면,
//	1C-1.c의 med3함수는 최대 3번의 비교를 하기 때문에
//	이 코드의 med3함수는 비효율적이다.
// ----------------------------------------

int med3(int a, int b, int c) {
	if ((b >= a && c <= a) || (b <= a && c >= a))
		return a;
	else if ((a > b && c < b) || (a < b && c > b))
		return b;
	else
		return c;
}

int main(void) {
	printf("med3(%d, %d, %d) = %d\n", 3, 2, 1, med3(3, 2, 1));
	printf("med3(%d, %d, %d) = %d\n", 3, 2, 2, med3(3, 2, 2));
	printf("med3(%d, %d, %d) = %d\n", 3, 1, 2, med3(3, 1, 2));
	printf("med3(%d, %d, %d) = %d\n", 3, 2, 3, med3(3, 2, 3));
	printf("med3(%d, %d, %d) = %d\n", 2, 1, 3, med3(2, 1, 3));
	printf("med3(%d, %d, %d) = %d\n", 3, 3, 2, med3(3, 3, 2));
	printf("med3(%d, %d, %d) = %d\n", 3, 3, 3, med3(3, 3, 3));
	printf("med3(%d, %d, %d) = %d\n", 2, 2, 3, med3(2, 2, 3));
	printf("med3(%d, %d, %d) = %d\n", 2, 3, 1, med3(2, 3, 1));
	printf("med3(%d, %d, %d) = %d\n", 2, 3, 2, med3(2, 3, 2));
	printf("med3(%d, %d, %d) = %d\n", 1, 3, 2, med3(1, 3, 2));
	printf("med3(%d, %d, %d) = %d\n", 2, 3, 3, med3(2, 3, 3));
	printf("med3(%d, %d, %d) = %d\n", 1, 2, 3, med3(1, 2, 3));

	return 0;
}