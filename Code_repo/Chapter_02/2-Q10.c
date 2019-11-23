// _________��� �迭 ����� completeShuffle__________
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
void completeShuffle(int source[], int elementNum);

int main(void) {
	int i;
	int* s;
	int eleNum;

	printf("�迭�� ��� �� : ");
	scanf("%d", &eleNum);
	s = calloc(eleNum, sizeof(int));

	// source�� ��Ҹ� ������ ����
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

	// �迭 ����
	for (i = 0; i < elementNum; i++) {
		s_copy[i] = source[i];
	}

	// �迭 ��� ����� ���� ���Ƿ� �ٲٱ�
	a = rand() % elementNum;
	do {
		b = rand() % elementNum;
	} while (a == b);
	do {
		swapFlag = 0;
		swap(int, source[a], source[b]);

		// ��� ��� ��ȭ Ȯ��
		for (i = 0; i < elementNum; i++) {
			if (s_copy[i] == source[i]) { indexFlag[i] = 1; }    // ��� ���� �ȹٲ� index�� indexFlag = 1
			else { indexFlag[i] = 0; }
		}

		for (i = 0; i < elementNum; i++) {
			if (indexFlag[i]) {    // ��Ұ��� �ȹٲ� index�� �ϳ��� ������ �ٽ� swap
				swapFlag = 1;      // 
				a = i;             // �ȹٲ� ���� ������ ��� index
				do {
					b = rand() % elementNum;    // �ٸ� index
				} while (a == b);
				break;
			}
		}

	} while (swapFlag);    // ��� index�� ��Ұ��� �ٲ�� do-while�� ����

}