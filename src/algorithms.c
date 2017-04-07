#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "util.h"


void insertion_sort(int *p_array, int size) {
	int i, j, key;

	for(j = 1; j < size; j++) {
		key = p_array[j];
		i = j - 1;
		while(i >= 0 && p_array[i] > key) {
			p_array[i + 1] = p_array[i];
			i--;
		}
		p_array[i + 1] = key;
	}
}


/*
 * @require p <= q < r
 */
void merge(int *p_array, int p, int q, int r) {
	int n1 = q - p;
	int n2 = r - q + 1;

	int *left = malloc(n1 * sizeof(int));
	int *right = malloc(n2 * sizeof(int));

	int i, j, k;

	for(i = 0; i < n1; i++) {
		left[i] = p_array[p + i];
	}
	for(j = 0; j < n2; j++) {
		right[j] = p_array[q + j];
	}

	i = j = 0;
	k = p;
	while(i < n1 && j < n2) {
		if(left[i] <= right[j]) {
			p_array[k] = left[i];
			i++;
		} else {
			p_array[k] = right[j];
			j++;
		}
		k++;
	}

	if(i == n1) {
		while(k <= r) {
			p_array[k] = right[j];
			k++;
			j++;
		}
	} else {
		while(k <= r) {
			p_array[k] = left[i];
			k++;
			i++;
		}
	}
}


void merge_sort(int *p_array, int p, int r) {
	int q;

	if(p < r) {
		q = (int) ((p + r) / 2);
		q++;
		merge_sort(p_array, p, q - 1);
		merge_sort(p_array, q, r);
		merge(p_array, p, q, r);
	}
}


void bubble_sort(int *p_array, int size) {
	int i;
	int swapped = 1;

	while(swapped == 1) {
		swapped = 0;
		for(i = 0; i < size - 1; i++) {
			if(p_array[i] > p_array[i + 1]) {
				swap(p_array, i, i + 1);
				swapped = 1;
			}
		}
	}
}


void bubble_sort_v2(int *p_array, int size) {
	int i;
	int swapped = 1;

	size--;
	while(swapped == 1) {
		swapped = 0;
		for(i = 0; i < size; i++) {
			if(p_array[i] > p_array[i + 1]) {
				swap(p_array, i, i + 1);
				swapped = 1;
			}
		}
		size--;
	}
}


void bubble_sort_v3(int *p_array, int size) {
	int i;
	int last_swap = 1;

	size--;
	while(last_swap > 0) {
		last_swap = 0;
		for(i = 0; i < size; i++) {
			if(p_array[i] > p_array[i + 1]) {
				swap(p_array, i, i + 1);
				last_swap = i;
			}
		}
		size = last_swap;
	}
}


void max_heapfy(int *p_array) {
// todo
}

