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