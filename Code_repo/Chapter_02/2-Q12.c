// __________ ����ü �迭 __________
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define VMAX 21    // �ִ� �÷�: 21 / 10.0 = 2.1

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
		{ "������", 162, 0.3 },
		{ "������", 173, 0.7 },
		{ "������", 175, 2.0 },
		{ "ȫ����", 171, 1.5 },
		{ "�̼���", 168, 0.4 },
		{ "�迵��", 174, 1.2 },
		{ "David Stone", 169, 0.8 }
	};
	int pNum = sizeof(x) / sizeof(x[0]);
	int vision_dist[VMAX];

	puts("    === ��ü�˻� ǥ ===");
	puts("�̸�               Ű   �÷�");
	puts("---------------------------");
	for (i = 0; i < pNum; i++) {
		printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
	}
	printf("\n ��� Ű: %5.1f cm\n", avgHeight(x, pNum));
	distVision(x, pNum, vision_dist);
	printf("\n �÷º���\n");
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

// �÷� ����
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