#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "util.h"


void print_wellcome_message()
{
	puts("----------------------------------------------");
	puts("| Welcome to MazerFaker's Algorithms Factory |");
	puts("----------------------------------------------");
}


void print_separator() 
{
	int i;
	printf("\n");
	for(i = 0; i < SEPARATOR_LENGHT; i++) {
		printf("%c", SEPARATOR_1);
		printf(" ");
	}
	printf("\n");
}


void print_array(int *p_array, int size) 
{
	int i;
	for(i = 0; i < size; i++) {
		printf("%d ", p_array[i]);
	}
}


void populate_array(int *p_array, int size) 
{
	int i;
	srand(time(NULL));
	for(i = 0; i < size; i++) {
		p_array[i] = ( rand() % MAX_RAND_VALUE );
	}
}


void copy_array(int *p_array1, int *p_array2, int size) 
{
	int i;
	for(i = 0; i < size; i++) {
		p_array2[i] = p_array1[i];
	}
}


void swap(int *p_array, int i, int j)
{
	int tmp = p_array[i];
	p_array[i] = p_array[j];
	p_array[j] = tmp;
}
