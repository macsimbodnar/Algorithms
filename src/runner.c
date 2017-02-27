#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "runner.h"
#include "algorithms.h"
#include "util.h"


void run_insertion_sort(int *array, int size) {
	double time_spent;
	clock_t begin, end;

	print_separator();
	puts("running insertion sort");
	printf("\ninput size: %d", size);

	begin = clock();

	insertion_sort(array, size);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nexec time: %f", time_spent);
	print_separator();
}


void run_merge() {
	double time_spent;
	clock_t begin, end;

	int p = 0;
	int q, r, size1, size2, size, i, k;
	char command;

	do {
		puts("\ndigit first array dim:");
		scanf("%d", &size1);
		if(size1 == -1) {
			return;
		} else if(size1 < 1) {
			puts("size must be greater than zero [-1 to exit]");
		}
	} while (size1 < 1);

	do {
		puts("\ndigit second array dim:");
		scanf("%d", &size2);
		if(size2 == -1) {
			return;
		} else if(size2 < 1) {
			puts("size must be greater than zero [-1 to exit]");
		}
	} while (size2 < 1);

	int *array1 = malloc(size1 * sizeof(int));
	init_array(array1, size1);
	insertion_sort(array1, size1);

	int *array2 = malloc(size2 * sizeof(int));
	init_array(array2, size2);
	insertion_sort(array2, size2);

	size = size1 + size2;
	int *array = malloc(size * sizeof(int));
	for(k = 0; k < size1; k++) {
		array[k] = array1[k];
	}
	q = k;
	for(i = 0; i < size2; i++) {
		array[k + i] = array2[i];
	}
	r = k + i - 1;


	puts("\nprint input [y - n]?");
	scanf(" %c", &command);
	if(command == 'y') {
		print_array(array1, size1);
		printf(" |  ");
		print_array(array2, size2);
		printf("\n");
		print_array(array, size);
	} else if(command == 'q') {
		return;
	}

	print_separator();
	puts("running merge");

	begin = clock();

	merge(array, p, q, r);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nexec time: %f", time_spent);
	print_separator();

	puts("\nprint result [y - n]?");
	scanf(" %c", &command);
	if(command == 'y') {
		print_array(array, size);
	} else if(command == 'q') {
		return;
	}
}


void run_merge_sort(int *array, int size) {
	double time_spent;
	clock_t begin, end;

	print_separator();
	puts("running merge sort");
	printf("\ninput size: %d", size);

	begin = clock();

	merge_sort(array, 0, size);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nexec time: %f", time_spent);
	print_separator();
}


void run_bubble_sort(int *array, int size) {
	double time_spent;
	clock_t begin, end;

	print_separator();
	puts("running bubble sort");
	printf("\ninput size: %d", size);

	begin = clock();

	bubble_sort(array, size);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nexec time: %f", time_spent);
	print_separator();
}


void run_bubble_sort_v2(int *array, int size) {
	double time_spent;
	clock_t begin, end;

	print_separator();
	puts("running bubble sort version 2");
	printf("\ninput size: %d", size);

	begin = clock();

	bubble_sort_v2(array, size);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nexec time: %f", time_spent);
	print_separator();
}
