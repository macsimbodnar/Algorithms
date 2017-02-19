/*-
 * MIT License
 *
 * Copyright (c) 2017 Maksym Bodnar
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <stdio.h>
#include "runner.h"

#define INSERTION_SORT 1
#define FIRST_TYPE_END 1
#define TOTAL_ALGORITHMS 1

#define MAX_ARRAY_SIZE 100000
#define MAX_RAND_VALUE 100


void print_help();
void list_algorithms();
void list_first_type();
void run_algorithm();
void run_first_type(int id, int *default_input, int default_input_size);
void init_array(int *array, int size);
void copy_array(int *array1, int *array2, int size);


int main(int argc, char* argv[]) {
	char command;
	int quit = 0;

	printf("Welcome to MazerFaker's Algorithms Factory");
	while(quit == 0) {
		printf("\n\"q\" for quit, \"h\" for help, \"r\" for run algorithm: \n");
		scanf(" %c", &command);
		if (command == 'q') {
			quit = 1;
		} else if (command == 'h') {
			print_help();
		} else if (command == 'l') {
			list_algorithms();
		} else if (command == 'r') {
			list_algorithms();
			run_algorithm();
		}
	}
}


void run_algorithm() {
	int algorithm = 0;

	printf("\n- - - - - - - - - - - - -\nselect algorithm:\n");
	scanf("%d", &algorithm);

	if(algorithm > 0 && algorithm <= FIRST_TYPE_END) {
		run_first_type(algorithm, NULL, -1);
	} else {
		printf("\nno such algorithm :(");
		list_algorithms();
		run_algorithm();
	}
}

void run_first_type(int id, int *default_input, int default_input_size) {
	char command;
	int input[MAX_ARRAY_SIZE];
	int input_copy[MAX_ARRAY_SIZE];
	int size = 0, i;

	if(default_input == NULL) {
		printf("\nselect input[array of random generated integer] size[MAX SIZE %d]:\n", MAX_ARRAY_SIZE);
		do {
			scanf("%d", &size);
			if(size == -1) {
				return;
			}
		} while(size < 0 || size > MAX_ARRAY_SIZE);
		init_array(input, size);
	} else {
		copy_array(default_input, input, default_input_size);
		size = default_input_size;
	}
	copy_array(input, input_copy, size);

	printf("\nshow input [y - n]? \n");
	scanf(" %c", &command);
	if(command == 'y') {
		printf("\n");
		for(i = 0; i < size; i++) {
			printf("%d ", input[i]);
		}
	} else if (command == 'q') {
		return;
	}

	if(id == INSERTION_SORT) {
		run_insertion_sort(input, size);
	}

	printf("\nshow output [y - n]?\n");
	scanf(" %c", &command);
	if(command == 'y') {
		printf("\n");
		for(i = 0; i < size; i++) {
			printf("%d ", input[i]);
		}

	} else if (command == 'q') {
		return;
	}

	printf("\n\ndo you want to run another alorithm with same input [y - n]?\n");
	scanf(" %c", &command);
	if(command == 'y') {
		list_first_type();
		printf("\nchoose one [\"-1\" for quit]: \n");
		do {
			scanf("%d", &id);
			if(id == -1) {
				return;
			}
		} while (id < 0 || id > FIRST_TYPE_END);
		run_first_type(id, input_copy, size);
	}
}

void init_array(int *array, int size) {
	int i;
	srand(time(NULL));
	for(i = 0; i < size; i++) {
		array[i] = ( rand() % MAX_RAND_VALUE );
	}
}

void copy_array(int *array1, int *array2, int size) {
	int i;
	for(i = 0; i < size; i++) {
		array2[i] = array1[i];
	}
}

void print_help() {
	printf("\n\"l\" to list available algorithms");
	printf("\n\"r\" to run algorithm");

	printf("\n    in run mode: ");
	printf("\n      \"-1\" to exit run mode");
}

void list_algorithms() {
	list_first_type();
}

void list_first_type() {
	printf("\n%d - Insertion Sort", INSERTION_SORT);
}
