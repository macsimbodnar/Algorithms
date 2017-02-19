#include "runner.h"
#include "algorithms.h"

#include <time.h>
#include <stdio.h>

void run_insertion_sort(int *array, int size) {
	int i;
	double time_spent;
	clock_t begin, end;

	printf("\n- - - - - - - - - - - - - - - - - -");
	printf("\nrunnig insertion sort");
	printf("\ninput size: %d", size);

	begin = clock();

	insertion_sort(array, size);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nexec time: %f", time_spent);
	printf("\n- - - - - - - - - - - - - - - - - -");
}
