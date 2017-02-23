#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "util.h"


void insertion_sort(int *array, int size) {
	int i, j, key;

	for(j = 1; j < size; j++) {
		key = array[j];
		i = j - 1;
		while(i >= 0 && array[i] > key) {
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
}


/*
 * @require p <= q < r
 */
void merge(int *array, int p, int q, int r) {
	int n1 = q - p;
	int n2 = r - q + 1;

	int *left = malloc(n1 * sizeof(int));
	int *right = malloc(n2 * sizeof(int));

	int i, j, k;

	for(i = 0; i < n1; i++) {
		left[i] = array[p + i];
	}
	for(j = 0; j < n2; j++) {
		right[j] = array[q + j];
	}

	i = j = 0;
	k = p;
	while(i < n1 && j < n2) {
		if(left[i] <= right[j]) {
			array[k] = left[i];
			i++;
		} else {
			array[k] = right[j];
			j++;
		}
		k++;
	}

	if(i == n1) {
		while(k <= r) {
			array[k] = right[j];
			k++;
			j++;
		}
	} else {
		while(k <= r) {
			array[k] = left[i];
			k++;
			i++;
		}
	}
}


void merge_sort(int *array, int p, int r) {
	int q;

	if(p < r) {
		q = (int) ((p + r) / 2);
		q++;
		merge_sort(array, p, q - 1);
		merge_sort(array, q, r);
		merge(array, p, q, r);
	}
}
