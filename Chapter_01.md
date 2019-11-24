# 자료구조와 함께 배우는 알고리즘 입문 (C언어 편)
+ 2019.11.16.
+ Chapter 1 (pp. 13-40)

* * *
## Table of Contents

- [p.19](#p19)
    - [Q1: 네 값의 최댓값](#q1)
    - [Q2: 세 값의 최솟값](#q2)
    - [Q3: 네 값의 최솟값](#q3)
- [p.22](#p22)
    - [Q4: 세 값의 중앙값](#q4)
    - [Q5: 세 값의 중앙값](#q5)
- [p.29](#p29)
    - [Q6: 1부터 n까지의 정수 합 구하기](#q6)
- [p.31](#p31)
    - [Q7: 1부터 n까지의 정수 합 구하기](#q7)
    - [Q8: 1부터 n까지의 정수 합 구하기](#q8)
    - [Q9: A부터 B까지의 정수 합 구하기](#q9)
- [p.33](#p33)
    - [Q10: b-a 츨력하기](#q10)
    - [Q11: 양수 A의 자릿수 구하기](#q11)
- [p.38](#p38)
    - [Q12: 곱셈표 출력하기](#q12)
    - [Q13: 덧셈표 출력하기](#q13)
    - [Q14: 정사각형 출력하기](#q14)
    - [Q15: 직사각형 출력하기](#q15)
- [p.40](#p40)
    - [Q16: 직각 이등변 삼각형 출력하기](#q16)
    - [Q17: 피라미드 출력하기](#q17)
    - [Q18: 숫자 역피라미드 출력하기](#q18)

* * *
## p.19
>#### Q1
```C
// __________네 값의 최댓값__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max4(int a, int b, int c, int d) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}

int main(void) {
	printf("max4(%d, %d, %d, %d) = %d\n", 4, 3, 2, 1, max4(4, 3, 2, 1));
	printf("max4(%d, %d, %d, %d) = %d\n", 3, 3, 4, 1, max4(3, 3, 4, 1));
	printf("max4(%d, %d, %d, %d) = %d\n", 2, 1, 2, 3, max4(2, 1, 2, 3));

	return 0;
}
```
>#### Q2
```C
// __________세 값의 최솟값__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min3(int a, int b, int c) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}

int main(void) {
	printf("min3(%d, %d, %d) = %d\n", 3, 2, 1, min3(3, 2, 1));
	printf("min3(%d, %d, %d) = %d\n", 3, 2, 2, min3(3, 2, 2));
	printf("min3(%d, %d, %d) = %d\n", 3, 1, 2, min3(3, 1, 2));

	return 0;
}
```
>#### Q3
```C
// __________네 값의 최솟값__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min4(int a, int b, int c, int d) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;
	return min;
}

int main(void) {
	printf("min4(%d, %d, %d, %d) = %d\n", 4, 3, 2, 1, min4(4, 3, 2, 1));
	printf("min4(%d, %d, %d, %d) = %d\n", 3, 3, 4, 2, min4(3, 3, 4, 2));
	printf("min4(%d, %d, %d, %d) = %d\n", 3, 4, 4, 3, min4(3, 4, 4, 3));

	return 0;
}
```


## p.22
>#### Q4
```C
// __________세 값의 중앙값__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int med3(int a, int b, int c) {
	if (a >= b)
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
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
```
>#### Q5
```C
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
```


## p.29
>#### Q6
```C
// __________1부터 n까지의 정수 합 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, n;
	int sum;

	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값: ");
	scanf("%d", &n);

	sum = 0;
	i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);
	printf("현재의 i값은 %d입니다.", i);

	return 0;
}
```


## p.31
>#### Q7
```C
// __________1부터 n까지의 정수 합 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, n;
	int sum;

	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값: ");
	scanf("%d", &n);

	sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
		printf("%d", i);
		if (i < n)
			printf(" + ");
		else
			printf(" = ");
	}
	printf("%d\n", sum);

	return 0;
}
```
>#### Q8
```C
// __________1부터 n까지의 정수 합 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, n;
	int sum;

	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값: ");
	scanf("%d", &n);

	sum = 0;
	if (n % 2) {
		sum = n--;
	}
	sum += (1 + n) * (n / 2);

	printf("1부터 입력한 숫자까지의 합은 %d입니다.\n", sum);

	return 0;
}
```
>#### Q9
```C
// __________A부터 B까지의 정수 합 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumof(int a, int b);

int main(void) {
	int numA, numB;
	puts("A부터 B까지의 합을 구합니다. (모든 정수에서 가능)");
	printf("A의 값: ");
	scanf("%d", &numA);
	printf("B의 값: ");
	scanf("%d", &numB);

	if (numA > numB) {
		printf("%d부터 %d까지의 합은 %d입니다.\n", numB, numA, sumof(numA, numB));
	}
	else if (numA < numB) {
		printf("%d부터 %d까지의 합은 %d입니다.\n", numA, numB, sumof(numB, numA));
	}
	else
		printf("%d부터 %d까지의 합은 %d입니다.\n", numA, numB, 0);


	return 0;
}

int sumof(int numHigh, int numLow) {
	int sumHigh = 0;
	int sumLow = 0;
	numLow--;

	// 1부터 numHigh까지의 합 구하기
	if (numHigh % 2) {
		sumHigh = numHigh--;
	}
	sumHigh += (1 + numHigh) * (numHigh / 2);

	// 1부터 (numLow - 1)까지의 합 구하기
	if (numLow % 2) {
		sumLow = numLow--;
	}
	sumLow += (1 + numLow) * (numLow / 2);

	return sumHigh - sumLow;
}
```


## p.33
>#### Q10
```C
// __________b-a 츨력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, numA, numB;

	puts("(B - A)의 값을 구합니다.");
	do {
		printf("A의 값: ");
		scanf("%d", &numA);
	} while (numA < 0);
	i = 0;
	do {
		if (i++) printf("A보다 큰 값을 입력하세요!!\n");

		printf("B의 값: ");
		scanf("%d", &numB);
	} while ((numB - numA) <= 0);
	printf("(%d - %d)의 값은 %d입니다.", numB, numA, numB - numA);

	return 0;
}
```
>#### Q11
```C
// __________양수 A의 자릿수 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, numA, pow10, test;
	int numIndex;

	puts("양수 A의 자릿수를 구합니다.");
	do {
		printf("A의 값: ");
		scanf("%d", &numA);
	} while (numA <= 0);
	i = 0;
	do {
		pow10 = 1;
		// 10의 i제곱을 계산하는 내부 loop
		for (int j = 0; j <= i; j++) {
			pow10 *= 10;
		}

		test = (int)(numA / pow10);
		i++;
	} while (test);
	numIndex = i;

	printf("그 수는 %d자리입니다.", numIndex);

	return 0;
}
```


## p.38
>#### Q12
```C
// __________곱셈표 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j;

	puts("  |  1  2  3  4  5  6  7  8  9");
	printf("--+---------------------------\n");
	for (i = 1; i <= 9; i++) {
		printf("%d |", i);
		for (j = 1; j <= 9; j++) {
			printf("%3d", i * j);
		}
		putchar('\n');
	}

	return 0;
}
```
>#### Q13
```C
// __________덧셈표 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j;

	puts("  |  1  2  3  4  5  6  7  8  9");
	printf("--+---------------------------\n");
	for (i = 1; i <= 9; i++) {
		printf("%d |", i);
		for (j = 1; j <= 9; j++) {
			printf("%3d", i + j);
		}
		putchar('\n');
	}

	return 0;
}
```
>#### Q14
```C
// __________정사각형 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j, n;

	puts("정사각형을 출력합니다.");
	printf("입력할 수: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf(" *");
		}
		putchar('\n');
	}

	return 0;
}
```
>#### Q15
```C
// _________직사각형 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j, h, w;

	puts("직사각형을 출력합니다.");
	i = 0; j = 0;
	do {
		if (i) puts("양수를 입력하세요!!");
		printf("높이: ");
		scanf("%d", &h);
		i++;
	} while (h <= 0);
	do {
		if (j) puts("양수를 입력하세요!!");
		printf("너비: ");
		scanf("%d", &w);
		j++;
	} while (w <= 0);

	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			printf(" *");
		}
		putchar('\n');
	}

	return 0;
}
```


## p.40
>#### Q16
```C
// _________직각 이등변 삼각형 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void drawTriangleLB(int n);
void drawTriangleLU(int n);
void drawTriangleRB(int n);
void drawTriangleRU(int n);

int main(void) {
	int n;

	do {
		printf("몇 단 삼각형 입니까? : ");
		scanf("%d", &n);
	} while (n <= 0);
	drawTriangleLB(n);
	drawTriangleLU(n);
	drawTriangleRB(n);
	drawTriangleRU(n);

	return 0;
}


void drawTriangleLB(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) { printf(" *"); }
		putchar('\n');
	}
	putchar('\n');
}
void drawTriangleLU(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = n; j >= i; j--) { printf(" *"); }
		putchar('\n');
	}
	putchar('\n');
}
void drawTriangleRB(int n) {
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = n; j > i; j--) { printf("  "); }
		for (k = 1; k <= i; k++) { printf(" *"); }
		putchar('\n');
	}
	putchar('\n');
}
void drawTriangleRU(int n) {
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++) { printf("  "); }
		for (k = n; k >= i; k--) { printf(" *"); }
		putchar('\n');
	}
	putchar('\n');
}
```
>#### Q17
```C
// _________피라미드 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void spira(int n);

int main(void) {
	int n;

	do {
		printf("몇 단 피라미드 입니까? : ");
		scanf("%d", &n);
	} while (n <= 0);
	spira(n);

	return 0;
}


void spira(int n) {
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = n; j >= i; j--) { printf("  "); }
		for (k = 1; k < (2 * i); k++) { printf(" *"); }
		putchar('\n');
	}
	putchar('\n');
}
```
>#### Q18
```C
// _________숫자 역피라미드 출력하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void nrpira(int n);

int main(void) {
	int n;

	do {
		printf("몇 단 피라미드 입니까? : ");
		scanf("%d", &n);
	} while (n <= 0);
	nrpira(n);

	return 0;
}


void nrpira(int n) {
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) { printf("  "); }
		for (k = 0; k <= 2 * (n - i); k++) { printf(" %d", i % 10); }
		putchar('\n');
	}
	putchar('\n');
}
```
