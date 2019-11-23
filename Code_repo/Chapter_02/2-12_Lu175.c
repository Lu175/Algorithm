// __________ 한 해의 지난 날 수 구하기__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isLeap(int year);
int countDays(int year, int month, int date);

// 각 달의 날 수
int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    // 평년 (365일)

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
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);    // 윤년: 1 | 평년: 0
}

// 1월 1일부터 지난 날짜 count
int countDays(int year, int month, int date) {
	int i;
	int days = date;
	for (i = 1; i < month; i++) {
		days += mdays[i - 1];
	}
	return days + isLeap(year);    // 윤년이면 +1일
}