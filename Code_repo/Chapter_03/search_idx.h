#pragma once
#ifndef _LU175_SEARCH_IDX
#define _LU175_SEARCH_IDX

int search_idx(const int a[], int n, int key, int target_idx[], int* ptr) {
	int i, j, k, num_target;
	int* idx_buffer;
	int count_idx = 0;
	int* count = ptr;

	idx_buffer = calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		(*count)++;
		if (a[i] == key) {
			idx_buffer[i] = 1;
		}
		else {
			idx_buffer[i] = 0;
		}
	}
	for (j = 0; j < n; j++) {
		if (idx_buffer[j] == 1) {
			target_idx[count_idx] = idx_buffer[j];
			count_idx++;
		}
	}
	for (k = 0; k < n; k++) {
		if (target_idx[k] == 0) {
			break;
		}
	}
	free(idx_buffer);
	num_target = k;
	return (num_target == 0) ? -1 : num_target;    // target이 없으면 -> 검색 fail
}
#endif //_LU175_SEARCH_IDX