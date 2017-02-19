#include "algorithms.h"

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

