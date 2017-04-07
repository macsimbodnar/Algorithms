#ifndef UTIL_ALGORITHMS_H_
#define UTIL_ALGORITHMS_H_


#define MAX_RAND_VALUE 1000

#define SEPARATOR_LENGHT 40
#define SEPARATOR_1 '-'


void print_separator();

int show_input(char *p_message, int *p_array, int size);

void print_array(int *p_array, int size);

void init_array(int *p_array, int size);

void copy_array(int *p_array1, int *p_array2, int size);

void swap(int *p_array, int i, int j);


#endif
