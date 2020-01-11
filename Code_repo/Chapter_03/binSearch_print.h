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

// [Start] index 나열
	printf("\n    |");
	for (i = 0; i < n; i++) {
		printf("%4d", i);
	}
	printf("\n----+");
	for (i = 0; i < n; i++) {
		printf("----");
	}
	puts("");
// [End] index 나열

// [Start] test 부분 print
	do {
		//edgeFlag = 0;    // Reset edgeFlag
		pc = (pl + pr) / 2;
		// <- : 검색 범위 lower limit    // pl
		//  + : 검색 범위 center         // pc
		// -> : 검색 범위 upper limit    // pr
		if (pr - pl > 1) {    // pc가 검색 범위의 중간에 있다면
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <- ");    // pl 출력
			for (i = 0; i < pc - pl - 1; i++) { printf("    "); }    // pl과 pc 사이의 공백 출력
			printf("  + ");    // pc 출력
			for (i = 0; i < pr - pc - 1; i++) { printf("    "); }    // pc과 pr 사이의 공백 출력
			printf("  ->\n");    // pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
		}
		else if (pc == pl) {    // pc가 검색 범위의 왼쪽 끝(pl)에 있다면
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <-+");    // pl, pc 출력
			printf("  ->\n");    // pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
			if (a[pc] < key) { edgeFlag = 1; }    // key가 검색 범위의 왼쪽 두번째 요소라면 -> Special case
		}
		else {    // pc가 검색 범위의 오른쪽 끝(pr)에 있다면
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <- ");    // pl 출력
			printf(" +->\n");    // pc, pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
			if (a[pc] > key) { edgeFlag = 2; }    // key가 검색 범위의 오른쪽 두번째 요소라면 -> Special case
		}

		for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // 검사 요소값들 표시 (배열 표시)
		puts("");

// [Start] Special case
		if (edgeFlag == 1) {
			pc += 1;
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <- ");    // pl 출력
			printf(" +->\n");    // pc, pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
			for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // 검사 요소값들 표시 (배열 표시)
			puts("");
		}
		if (edgeFlag == 2) {
			pc += 1;
			printf("    |");
			for (i = 0; i < pl; i++) { printf("    "); }    // test index 축과 pl 사이의 공백 출력
			printf(" <-+");    // pl, pc 출력
			printf("  ->\n");    // pr 출력
			printf("%4d|", pc);    // 현재 test index 값 (pc) 출력
			for (i = 0; i < n; i++) { printf("%4d", a[i]); }    // 검사 요소값들 표시 (배열 표시)
			puts("");
		}
// [End] Special case

// [Start] test logic
		if ((*count)++, (a[pc] == key)) { return pc; }    // 검색 success
		else if ((*count)++, (a[pc] < key)) { pl = pc +1; }    // 검색 범위의 왼쪽 limit 줄이기
		else { pr = pc -1; }    // 검색 범위의 오른쪽 limit 줄이기
// [END] test logic

		if (edgeFlag != 0) { break; };
	} while (pl <= pr);
// [End] test 부분 print

	return -1;    // 검색 fail
}
#endif //_LU175_BINARY_SEARCH_PRINT_PROCESS