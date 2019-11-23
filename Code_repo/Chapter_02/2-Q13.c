// __________ ����ü �迭 __________
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

// �� ���� �� ��
int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    // ��� (365��)
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}    // ���� (366��)
};

int main(void) {
	int y, m, d, n;
	Date date;
	int AB_Flag;

	printf("���� ��¥�� �Է��ϼ���.\n");
	printf("��: "); scanf("%d", &y);
	printf("��: "); scanf("%d", &m);
	printf("��: "); scanf("%d", &d);
	date = DateOf(y, m, d);
	printf("��� �������� ��¥�� �̵��Ͻðڽ��ϱ�? (1...��/0...��): ");
	scanf("%d", &AB_Flag);
	printf("��ĥ �̵��Ͻðڽ��ϱ�? : ");
	scanf("%d", &n);
	if (AB_Flag) { date = Before(date, n); }
	else { date = After(date, n); }
	printf("���õ� ��¥�� %d�� %d�� %d�� �Դϴ�.\n", date.y, date.m, date.d);

	return 0;
}


Date DateOf(int y, int m, int d) {
	Date x = { y, m, d };
	return x;
}

Date After(Date x, int n) {
	if (x.d + n > mdays[isLeap(x.y)][x.m - 1]) {    // [x.m - 1]�� x.m ���� index
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
		x.d -= n - mdays[isLeap(x.y)][x.m - 2];    // [x.m - 2]�� x.m �� ���� index
		x.m -= 1;
	}
	else {
		x.d -= n;
	}
	return x;
}

// ���� test
int isLeap(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}