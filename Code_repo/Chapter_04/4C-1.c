// __________Get only last N data__________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10

int main(void) {
	int i, retry;
	int a[N];    // input data ����
	int count = 0;    // input data ��

	puts("������ �Է��ϼ���.");
	do {
		printf("%2d��° ���� : ", count + 1);
		scanf("%d", &a[count++ % N]);    // Ring buffer process
		printf("����ұ��?  (Yes... 1 / No... 0) : ");
		scanf("%d", &retry);
	} while(retry == 1);

	i = count - N;
	if(i < 0) { i = 0; }
	for(; i < count; i++) {
		printf("%2d��° ���� = %d\n", i +1, a[i % N]);
	}
	return 0;
}