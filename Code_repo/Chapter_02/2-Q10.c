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