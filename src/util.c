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


int show_input(char *p_message, int *p_array, int size) {
	char command;
	int i, quit = 0;

	printf("%s", p_message);
	scanf(" %c", &command);
	if(command == 'y') {
		printf("\n");
		for(i = 0; i < size; i++) {
			printf("%d ", p_array[i]);
		}
	} else if (command == 'q') {
		quit = 1;
	}

	return quit;
}


void print_array(int *p_array, int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d ", p_array[i]);
	}
}


void init_array(int *p_array, int size) {
	int i;
	srand(time(NULL));
	for(i = 0; i < size; i++) {
		p_array[i] = ( rand() % MAX_RAND_VALUE );
	}
}


void copy_array(int *p_array1, int *p_array2, int size) {
	int i;
	for(i = 0; i < size; i++) {
		p_array2[i] = p_array1[i];
	}
}


/*
 * swap in array element on position j with element on position i
 */
void swap(int *p_array, int i, int j){
	int tmp = p_array[i];
	p_array[i] = p_array[j];
	p_array[j] = tmp;
}
