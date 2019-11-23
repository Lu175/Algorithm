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