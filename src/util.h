#ifndef UTIL_ALGORITHMS_H_
#define UTIL_ALGORITHMS_H_


#define MAX_RAND_VALUE 1000

#define SEPARATOR_LENGHT 40
#define SEPARATOR_1 '-'

void print_wellcome_message();

void print_separator();

void print_array(int *p_array, int size);

void populate_array(int *p_array, int size);

/*
 * copy array1 in array2
 */
void copy_array(int *p_array1, int *p_array2, int size);

/*
 * swap in array element on position j with element on position i
 */
void swap(int *p_array, int i, int j);


#endif
