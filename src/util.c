#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "util.h"


void print_separator() {
	int i;
	printf("\n");
	for(i = 0; i < SEPARATOR_LENGHT; i++) {
		printf("%c", SEPARATOR_1);
		printf(" ");
	}
	printf("\n");
}

int show_input(char *message, int *array, int size) {
	char command;
	int i, quit = 0;

	printf("%s", message);
	scanf(" %c", &command);
	if(command == 'y') {
		printf("\n");
		for(i = 0; i < size; i++) {
			printf("%d ", array[i]);
		}
	} else if (command == 'q') {
		quit = 1;
	}

	return quit;
}

void print_array(int *array, int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d ", array[i]);
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
