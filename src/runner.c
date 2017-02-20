#include <stdio.h>
#include <time.h>

#include "runner.h"
#include "algorithms.h"
#include "util.h"


void run_insertion_sort(int *array, int size) {
	double time_spent;
	clock_t begin, end;

	print_separator();
	puts("runnig insertion sort");
	printf("\ninput size: %d", size);

	begin = clock();

	insertion_sort(array, size);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nexec time: %f", time_spent);
	print_separator();
}
