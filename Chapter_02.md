# 자료구조와 함께 배우는 알고리즘 입문 (C언어 편)
+ 2019.11.24.
+ Chapter 2  (pp. 42-93)

* * *
## p.74
>#### Q1
```C
// _________배열 요소의 최솟값 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int minof(const int set[], int elementNum);

int main(void) {
	int i;
	int* height;
	int number;

	printf("사람 수: ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int));
	if (height == NULL) {
		puts("메모리 확보 실패 !");
	}
	else {
		printf("%d 사람의 키를 입력하세요.\n", number);
		for (i = 0; i < number; i++) {
			printf("height[%d]: ", i);
			scanf("%d", &height[i]);
		}
		printf("최솟값은 %d입니다.\n", minof(height, number));
		free(height);
	}

	return 0;
}

int minof(const int set[], int elementNum) {
	int i;
	int min = set[0];
	for (i = 1; i < elementNum; i++) {
		if (set[i] < min) { min = set[i]; }
	}
	return min;
}
```
>#### Q2
```C
// _________배열 요소의 합 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sumof(const int set[], int elementNum);

int main(void) {
	int i;
	int* height;
	int number;

	printf("사람 수: ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int));
	if (height == NULL) {
		puts("메모리 확보 실패 !");
	}
	else {
		printf("%d 사람의 키를 입력하세요.\n", number);
		for (i = 0; i < number; i++) {
			printf("height[%d]: ", i);
			scanf("%d", &height[i]);
		}
		printf("모든 키의 합은 %d입니다.\n", sumof(height, number));
		free(height);
	}

	return 0;
}

int sumof(const int set[], int elementNum) {
	int i;
	int sum = set[0];
	for (i = 1; i < elementNum; i++) {
		sum += set[i];
	}
	return sum;
}
```


## p.75
>#### Q3
```C
// _________배열 요소의 평균 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double avgof(const int set[], int elementNum);

int main(void) {
	int i;
	int* height;
	int number;

	printf("사람 수: ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int));
	if (height == NULL) {
		puts("메모리 확보 실패 !");
	}
	else {
		printf("%d 사람의 키를 입력하세요.\n", number);
		for (i = 0; i < number; i++) {
			printf("height[%d]: ", i);
			scanf("%d", &height[i]);
		}
		printf("모든 키의 합은 %f입니다.\n", avgof(height, number));
		free(height);
	}

	return 0;
}

double avgof(const int set[], int elementNum) {
	int i;
	int sum = set[0];
	int avg;
	for (i = 1; i < elementNum; i++) {
		sum += set[i];
	}
	avg = sum / elementNum;
	return avg;
}
```
>#### Q4
```C
// _________난수 사용해서 배열 요솟값 설정하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n);

int main(void) {
	int i;
	int* height;
	int number;

	srand(time(NULL));
	number = 5 + rand() % 16;
	printf("사람 수: %d\n", number);
	height = calloc(number, sizeof(int));
	if (height == NULL) {
		puts("메모리 확보 실패 !");
	}
	else {
		for (i = 0; i < number; i++) {
			height[i] = 100 + rand() % 90;
			printf("height[%d] = %d\n", i, height[i]);
		}
		printf("최대값은 %d입니다.\n", maxof(height, number));
		free(height);
	}

	return 0;
}

int maxof(const int a[], int n) {
	int i;
	int max = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > max) { max = a[i]; }
	}
	return max;
}
```
>#### Q5
```C
// _________난수 사용해서 배열 요솟값 설정하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
void ary_reverse(int a[], int n);

int main(void) {
	int i;
	int* x;
	int nx;

	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	if (x == NULL) {
		puts("메모리 확보 실패 !");
	}
	else {
		srand(time(NULL));
		for (i = 0; i < nx; i++) {
			x[i] = rand() % 100;
			printf("x[%d] = %d\n", i, x[i]);
		}
		puts("");
		ary_reverse(x, nx);
		printf("\n배열의 요소를 역순으로 정렬했습니다.\n");
		for (i = 0; i < nx; i++) {
			printf("x[%d] = %d\n", i, x[i]);
		}
		free(x);
	}

	return 0;
}


void ary_reverse(int a[], int n) {
	int i, j;
	for (i = 0; i < (n / 2); i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[j]);
		}
		puts("");
		printf("a[%d]과 a[%d]를 교환합니다.\n", i, n - 1 - i);
		swap(int, a[i], a[n - 1 - i]);
	}
	for (j = 0; j < n; j++) {
		printf("%d ", a[j]);
	}
	puts("");
	puts("역순 정렬을 종료합니다.");
}
```
>#### Q6
```C
// _________기수 변환하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
int baseConvert(unsigned decimal, int convBase, char rest[]);

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
		convNum_digits = baseConvert(originNum, convBase, restBuffer);
		printf("%d진수로는", convBase);
		for (i = 0; i < convNum_digits; i++) {
			printf("%c", restBuffer[i]);
		}
		printf("입니다.\n");
		printf("한 번 더 할까요?(1...예 / 0...아니오) : ");
		scanf("%d", &retryFlag);
	} while (retryFlag == 1);

	return 0;
}


int baseConvert(unsigned decimal, int baseNum, char rest[]) {
	char dchar[] = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	int digits = 0;
	int i;

	if (decimal == 0) {
		rest[digits++] = dchar[0];
	}
	else {
		while (decimal) {
			rest[digits++] = dchar[decimal % baseNum];
			decimal /= baseNum;
		}
	}
	// ary_reverse loop
	for (i = 0; i < (digits / 2); i++) {
		swap(int, rest[i], rest[digits - 1 - i]);
	}

	return digits;    // 변환된 수의 자릿수 반환
}
```
>#### Q7
```C
// _________기수 변환과정 보여주기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
int baseConvert(unsigned decimal, int convBase, char rest[]);

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
		puts("");
		convNum_digits = baseConvert(originNum, convBase, restBuffer);
		printf("%d진수로는", convBase);
		for (i = 0; i < convNum_digits; i++) {
			printf("%c", restBuffer[i]);
		}
		printf("입니다.\n");
		printf("한 번 더 할까요?(1...예 / 0...아니오) : ");
		scanf("%d", &retryFlag);
	} while (retryFlag == 1);

	return 0;
}


int baseConvert(unsigned decimal, int baseNum, char rest[]) {
	char dchar[] = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	int digits = 0;
	int i;

	if (decimal == 0) {
		rest[digits++] = dchar[0];
	}
	else {
		while (decimal) {
			rest[digits] = dchar[decimal % baseNum];
			decimal /= baseNum;
			printf("%2d|%8d ... %c\n", baseNum, decimal, rest[digits++]);
			puts("  +--------");
		}
		printf("%11d\n", 0);
	}
	// ary_reverse loop
	for (i = 0; i < (digits / 2); i++) {
		swap(int, rest[i], rest[digits - 1 - i]);
	}

	return digits;    // 변환된 수의 자릿수 반환
}
```
>#### Q8
```C
// _________배열 복사__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

void aryCopy(int copy[], const int source[], int elementNum);

int main(void) {
	int i;
	int* s;
	int* c;
	int eleNum;

	printf("배열의 요소 수 : ");
	scanf("%d", &eleNum);
	s = calloc(eleNum, sizeof(int));
	c = calloc(eleNum, sizeof(int));

	// source의 요소를 난수로 생성
	srand(time(NULL));
	printf("source: ");
	for (i = 0; i < eleNum; i++) {
		s[i] = rand() % 100;
		printf("%d ", s[i]);
	}
	puts("");
	aryCopy(c, s, eleNum);

	return 0;
}


void aryCopy(int copy[], const int source[], int elementNum) {
	int i;
	printf("  copy: ");

	// 배열 복사
	for (i = 0; i < elementNum; i++) {
		copy[i] = source[i];
		printf("%d ", copy[i]);
	}
}
```
>#### Q9
```C
// _________배열 역순으로 복사__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

void aryCopy_R(int copy[], const int source[], int elementNum);

int main(void) {
	int i;
	int* s;
	int* c;
	int eleNum;

	printf("배열의 요소 수 : ");
	scanf("%d", &eleNum);
	s = calloc(eleNum, sizeof(int));
	c = calloc(eleNum, sizeof(int));

	// source의 요소를 난수로 생성
	srand(time(NULL));
	printf("source: ");
	for (i = 0; i < eleNum; i++) {
		s[i] = rand() % 100;
		printf("%d ", s[i]);
	}
	puts("");
	aryCopy_R(c, s, eleNum);

	return 0;
}


void aryCopy_R(int copy[], const int source[], int elementNum) {
	int i;
	printf("copy_R: ");

	// 배열 역순으로 복사
	for (i = 0; i < elementNum; i++) {
		copy[i] = source[elementNum - 1 - i];
		printf("%d ", copy[i]);
	}
}
```


## p.76
>#### Q10
```C
// _________모든 배열 요소의 completeShuffle__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
void completeShuffle(int source[], int elementNum);

int main(void) {
	int i;
	int* s;
	int eleNum;

	printf("배열의 요소 수 : ");
	scanf("%d", &eleNum);
	s = calloc(eleNum, sizeof(int));

	// source의 요소를 난수로 생성
	srand(time(NULL));
	printf("source_array: ");
	for (i = 0; i < eleNum; i++) {
		s[i] = rand() % 100;
		printf("%3d", s[i]);
	}
	puts("");
	puts("");
	completeShuffle(s, eleNum);
	puts("complete shuffled array");
	printf("source_array: ");
	for (i = 0; i < eleNum; i++) {
		printf("%3d", s[i]);
	}
	puts("");

	return 0;
}


void completeShuffle(int source[], int elementNum) {
	int i, a, b;
	int* s_copy = calloc(elementNum, sizeof(int));
	int* indexFlag = calloc(elementNum, sizeof(int));
	int swapFlag;

	// 배열 복사
	for (i = 0; i < elementNum; i++) {
		s_copy[i] = source[i];
	}

	// 배열 모든 요소의 순서 임의로 바꾸기
	a = rand() % elementNum;
	do {
		b = rand() % elementNum;
	} while (a == b);
	do {
		swapFlag = 0;
		swap(int, source[a], source[b]);

		// 모든 요소 변화 확인
		for (i = 0; i < elementNum; i++) {
			if (s_copy[i] == source[i]) { indexFlag[i] = 1; }    // 요소 값이 안바뀐 index는 indexFlag = 1
			else { indexFlag[i] = 0; }
		}

		for (i = 0; i < elementNum; i++) {
			if (indexFlag[i]) {    // 요소값이 안바뀐 index가 하나라도 있으면 다시 swap
				swapFlag = 1;      // 
				a = i;             // 안바뀐 것이 감지된 요소 index
				do {
					b = rand() % elementNum;    // 다른 index
				} while (a == b);
				break;
			}
		}

	} while (swapFlag);    // 모든 index의 요소값이 바뀌면 do-while문 종료

}
```


## p.87
>#### Q11
```C
// __________ 한 해의 지난 날 수 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isLeap(int year);
int countDays(int year, int month, int date);

// 각 달의 날 수
int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    // 평년 (365일)
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}    // 윤년 (366일)
};

int main(void) {
	int year, month, date;
	int retryFlag;

	do {
		printf("현재 날짜를 입력하세요.\n");
		printf("년: "); scanf("%d", &year);
		printf("월: "); scanf("%d", &month);
		printf("일: "); scanf("%d", &date);
		printf("오늘은 %d년의 %d일째입니다.\n", year, countDays(year, month, date));
		printf("다시 할까요? (1...예/0...아니오): ");
		scanf("%d", &retryFlag);
	} while (retryFlag);

	return 0;
}


// 윤년 test
int isLeap(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

// 1월 1일부터 지난 날짜 count
int countDays(int year, int month, int date) {
	while (--month) {
		date += mdays[isLeap(year)][month - 1];
	}
	return date;
}
```


## p.93
>#### Q12
```C
// __________ 구조체 배열 __________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define VMAX 21    // 최대 시력: 21 / 10.0 = 2.1

typedef struct {
	char	name[20];
	int		height;
	double	vision;
}PhysCheck;

double avgHeight(const PhysCheck dat[], int pNum);
void distVision(const PhysCheck dat[], int pNum, int dist[]);

int main(void) {
	int i;
	PhysCheck x[] = {
		{ "박현규", 162, 0.3 },
		{ "함진아", 173, 0.7 },
		{ "최윤미", 175, 2.0 },
		{ "홍연의", 171, 1.5 },
		{ "이수진", 168, 0.4 },
		{ "김영준", 174, 1.2 },
		{ "David Stone", 169, 0.8 }
	};
	int pNum = sizeof(x) / sizeof(x[0]);
	int vision_dist[VMAX];

	puts("    === 신체검사 표 ===");
	puts("이름               키   시력");
	puts("---------------------------");
	for (i = 0; i < pNum; i++) {
		printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
	}
	printf("\n 평균 키: %5.1f cm\n", avgHeight(x, pNum));
	distVision(x, pNum, vision_dist);
	printf("\n 시력분포\n");
	for (i = 0; i < VMAX; i++) {
		printf("%3.1f ~ : ", i / 10.0);
		for (int j = 0; j < vision_dist[i]; j++) {
			printf("*");
		}
		puts("");
	}

	return 0;
}


double avgHeight(const PhysCheck dat[], int pNum) {
	int i;
	double sum = 0;
	for (i = 0; i < pNum; i++) {
		sum += dat[i].height;
	}
	return sum / pNum;
}

// 시력 분포
void distVision(const PhysCheck dat[], int pNum, int dist[]) {
	int i;
	for (i = 0; i < VMAX; i++) {
		dist[i] = 0;
	}
	for (i = 0; i < pNum; i++) {
		if ((dat[i].vision >= 0.0) && (dat[i].vision <= VMAX / 10.0)) {
			dist[(int)(dat[i].vision * 10)]++;
		}
	}
}
```
>#### Q13
```C
// __________ 구조체 배열 __________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int		y;
	int		m;
	int		d;
} Date;

Date DateOf(int y, int m, int d);
Date After(Date x, int n);
Date Before(Date x, int n);
int isLeap(int year);

// 각 달의 날 수
int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    // 평년 (365일)
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}    // 윤년 (366일)
};

int main(void) {
	int y, m, d, n;
	Date date;
	int AB_Flag;

	printf("현재 날짜를 입력하세요.\n");
	printf("년: "); scanf("%d", &y);
	printf("월: "); scanf("%d", &m);
	printf("일: "); scanf("%d", &d);
	date = DateOf(y, m, d);
	printf("어느 방향으로 날짜를 이동하시겠습니까? (1...전/0...후): ");
	scanf("%d", &AB_Flag);
	printf("며칠 이동하시겠습니까? : ");
	scanf("%d", &n);
	if (AB_Flag) { date = Before(date, n); }
	else { date = After(date, n); }
	printf("선택된 날짜는 %d년 %d월 %d일 입니다.\n", date.y, date.m, date.d);

	return 0;
}


Date DateOf(int y, int m, int d) {
	Date x = { y, m, d };
	return x;
}

Date After(Date x, int n) {
	if (x.d + n > mdays[isLeap(x.y)][x.m - 1]) {    // [x.m - 1]은 x.m 달의 index
		x.d += n - mdays[isLeap(x.y)][x.m - 1];
		x.m += 1;
	}
	else {
		x.d += n;
	}
	return x;
}

Date Before(Date x, int n) {
	if (x.d - n < 1) {
		x.d -= n - mdays[isLeap(x.y)][x.m - 2];    // [x.m - 2]는 x.m 전 달의 index
		x.m -= 1;
	}
	else {
		x.d -= n;
	}
	return x;
}

// 윤년 test
int isLeap(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
```
