#pragma once
#ifndef _LU175_BINARY_SEARCH2
#define _LU175_BINARY_SEARCH2

int binSearch2(const int a[], int n, int key, int* ptr) {
	int pl = 0;
	int pr = n - 1;
	int pc, pc_shift;
	int shift = 0;
	int* count = ptr;

	do {
		pc = (pl + pr) / 2;
		if ((*count)++, (a[pc] == key)) {    // �˻� success
// [Start] ������ ���� ��Ұ� �˻�
			while (1) {
				pc_shift = pc - ++shift;    // pc�� �������� �̵�
				if (a[pc_shift] != key) { return pc; }
				pc = pc_shift;
			}
// [End] ������ ���� ��Ұ� �˻�
		}
		else if ((*count)++, (a[pc] < key)) { pl = pc + 1; }    // �˻� ������ ���� limit ���̱�
		else { pr = pc - 1; }    // �˻� ������ ������ limit ���̱�
	} while (pl <= pr);
	return -1;    // �˻� fail
}
#endif //_LU175_BINARY_SEARCH2