#pragma once
#ifndef _LU175_BINARY_SEARCH_PRINT_PROCESS
#define _LU175_BINARY_SEARCH_PRINT_PROCESS

int binSearch_print(const int a[], int n, int key, int* ptr) {
	int i;
	int edgeFlag = 0;
	int pl = 0;
	int pr = n -1;
	int pc;
	int* count = ptr;

// [Start] index ����
	printf("\n    |");
	for (i = 0; i < n; i++) {
		printf("%4d", i);
	}
	printf("\n----+");
	for (i = 0; i < n; i++) {
		printf("----");
	}
	puts("");
// [End] index ����

// [Start] test �κ� print
	do {
		//edgeFlag = 0;    // Reset edgeFlag
		pc = (pl + pr) / 2;
		// <- : �˻� ���� lower limit    // pl
		//  + : �˻� ���� center         // pc
		// -> : �˻� ���� upper limit    // pr
		if (pr - pl > 1) {    // pc�� �˻� ������ �߰��� �ִٸ�
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index ��� pl ������ ���� ���
			printf(" <- ");    // pl ���
			for (i = 0; i < pc - pl - 1; i++) { printf("    "); }    // pl�� pc ������ ���� ���
			printf("  + ");    // pc ���
			for (i = 0; i < pr - pc - 1; i++) { printf("    "); }    // pc�� pr ������ ���� ���
			printf("  ->\n");    // pr ���
			printf("%4d|", pc);    // ���� test index �� (pc) ���
		}
		else if (pc == pl) {    // pc�� �˻� ������ ���� ��(pl)�� �ִٸ�
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index ��� pl ������ ���� ���
			printf(" <-+");    // pl, pc ���
			printf("  ->\n");    // pr ���
			printf("%4d|", pc);    // ���� test index �� (pc) ���
			if (a[pc] < key) { edgeFlag = 1; }    // key�� �˻� ������ ���� �ι�° ��Ҷ�� -> Special case
		}
		else {    // pc�� �˻� ������ ������ ��(pr)�� �ִٸ�
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index ��� pl ������ ���� ���
			printf(" <- ");    // pl ���
			printf(" +->\n");    // pc, pr ���
			printf("%4d|", pc);    // ���� test index �� (pc) ���
			if (a[pc] > key) { edgeFlag = 2; }    // key�� �˻� ������ ������ �ι�° ��Ҷ�� -> Special case
		}

		for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // �˻� ��Ұ��� ǥ�� (�迭 ǥ��)
		puts("");

// [Start] Special case
		if (edgeFlag == 1) {
			pc += 1;
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index ��� pl ������ ���� ���
			printf(" <- ");    // pl ���
			printf(" +->\n");    // pc, pr ���
			printf("%4d|", pc);    // ���� test index �� (pc) ���
			for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // �˻� ��Ұ��� ǥ�� (�迭 ǥ��)
			puts("");
		}
		if (edgeFlag == 2) {
			pc += 1;
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index ��� pl ������ ���� ���
			printf(" <-+");    // pl, pc ���
			printf("  ->\n");    // pr ���
			printf("%4d|", pc);    // ���� test index �� (pc) ���
			for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // �˻� ��Ұ��� ǥ�� (�迭 ǥ��)
			puts("");
		}
// [End] Special case

// [Start] test logic
		if ((*count)++, (a[pc] == key)) { return pc; }    // �˻� success
		else if ((*count)++, (a[pc] < key)) { pl = pc +1; }    // �˻� ������ ���� limit ���̱�
		else { pr = pc -1; }    // �˻� ������ ������ limit ���̱�
// [END] test logic

		if (edgeFlag != 0) { break; };
	} while (pl <= pr);
// [End] test �κ� print

	return -1;    // �˻� fail
}
#endif //_LU175_BINARY_SEARCH_PRINT_PROCESS