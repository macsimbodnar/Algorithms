#ifndef UTIL_ALGORITHMS_H_
#define UTIL_ALGORITHMS_H_


#define MAX_RAND_VALUE 1000

#define SEPARATOR_LENGHT 40
#define SEPARATOR_1 '-'


void print_separator();

int show_input(char *message, int *array, int size);

void print_array(int *array, int size);

void init_array(int *array, int size);

void copy_array(int *array1, int *array2, int size);

void swap(int *array, int i, int j);


#endif
