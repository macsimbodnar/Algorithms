#ifndef MAIN_ALGORITHMS_H_
#define MAIN_ALGORITHMS_H_

#include <stdio.h>
#include <stdlib.h>
#include "runner.h"
#include "util.h"


#define TYPE_SORTING 1
#define TOT_SORT_ALG 5

#define MERGE 6

typedef enum {INSERTION_SORT, MERGE_SORT, BUBBLE_SORT, BUBBLE_SORT_V2, BUBBLE_SORT_V3} sortingAlgType;

typedef void (*sorting_alg_function)(int *, int);

typedef struct SORTING_ALG
{
    sorting_alg_function execute;
    char* name;
}
sortingAlg;


void init_algorithms();
void print_help();
void list_algorithms();
void list_sort_alg();
void run_algorithm();
void run_sorting_alg();


#endif
