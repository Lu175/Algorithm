// __________ �� ���� ���� �� �� ���ϱ�__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isLeap(int year);
int countDays(int year, int month, int date);

// �� ���� �� ��
int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    // ��� (365��)

int main(void) {
	int year, month, date;
	int retryFlag;

	do {
		printf("���� ��¥�� �Է��ϼ���.\n");
		printf("��: "); scanf("%d", &year);
		printf("��: "); scanf("%d", &month);
		printf("��: "); scanf("%d", &date);
		printf("������ %d���� %d��°�Դϴ�.\n", year, countDays(year, month, date));
		printf("�ٽ� �ұ��? (1...��/0...�ƴϿ�): ");
		scanf("%d", &retryFlag);
	} while (retryFlag);

	return 0;
}


// ���� test
int isLeap(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);    // ����: 1 | ���: 0
}

// 1�� 1�Ϻ��� ���� ��¥ count
int countDays(int year, int month, int date) {
	int i;
	int days = date;
	for (i = 1; i < month; i++) {
		days += mdays[i - 1];
	}
	return days + isLeap(year);    // �����̸� +1��
}