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

#include "main.h"

static char global_command;
static unsigned int global_running;
static sortingAlg global_sortAlg[TOT_SORT_ALG];
static unsigned int global_inputSize;
static int* global_input;
static unsigned int global_rerun;

int main(int argc, char* argv[])
{
    init_algorithms();
    global_running = 1;
    global_command = 0;
    global_inputSize = 0;
    global_input = 0;
    global_rerun = 0;

    print_wellcome_message();

	while(global_running) {
		puts("\n\"q\" for quit \n\"h\" for help \n\"r\" for run algorithm:");
		scanf(" %c", &global_command);

        switch(global_command) {
            
            case 'Q':
            case 'q':
                global_running = 0;
                break;

            case 'H':
            case 'h':
                print_help();
                break;

            case 'L':
            case 'l':
                list_algorithms();
                break;

            case 'R':
            case 'r':
                run_algorithm();
                break;

            default:
            	print_help();
                break;
        }

		printf("\n\n");
		print_separator();
	}
}


void run_algorithm()
{
	int algType = 0;

    print_separator();
    list_algorithms();
	
    puts("\nselect algorithm type:");
	scanf("%d", &algType);

	switch(algType) {

		case TYPE_SORTING:
		    run_sorting_alg();
			break;

		default:
			puts("\nno such algorithm type :(");
			run_algorithm();
			break;

	}
}


void run_sorting_alg()
{
    do {
        int algorithm = 0;
        int inputSize = 0;
        int * input = 0;

        // select algorithm 
        while (!algorithm) {
            puts("\nselect algorithm:");
            scanf("%d", &algorithm);
            
            if (algorithm <= 0 || algorithm > sizeof(global_sortAlg) / sizeof(global_sortAlg[0])) {
                puts("\nno such algorithm :(");
                list_sort_alg();
                algorithm = 0;
            }
        } 
        
        // decrement because list algortihm and algorithm array are shifted by one
        algorithm--;
        printf("\nyou select %s", global_sortAlg[algorithm].name);
        
        if (global_inputSize <= 0 || global_input == 0) {
            global_rerun = 0;
        }
        
        if (global_rerun) {
            inputSize = global_inputSize;
            input = (int *) malloc(global_inputSize * sizeof(int));
            if (input == 0) {
                puts("\nerror in allocation of memory!");
                return;
            }

            copy_array(global_input, input, global_inputSize);

        } else {
            
            // select input size
            while (!inputSize) {
                puts("\nselect input[array of random generated integer] size:");
                scanf(" %d", &inputSize);

                if (inputSize <= 0) {
                    puts("\nsize must be greater than one!");
                }
            }
     
            // alloc input memory
            input = (int *) malloc(inputSize * sizeof(int));
            if (input == 0) {
                puts("\nerror in allocation of memory!");
                return;
            }

            populate_array(input, inputSize);
            
            free(global_input);
            global_input = (int *) malloc(inputSize * sizeof(int));
            if (global_input == 0) {
                puts("\nerror in allocation of memory!");
                return;
            }
            
            global_inputSize = inputSize;
            copy_array(input, global_input, inputSize);
        }


        global_sortAlg[algorithm].execute(input, inputSize);
        
        free(input);

        puts("\ndo you want to run another sorting algorithm with the same input? [y - n]");
        scanf(" %c", &global_command);
        if (global_command == 'y' || global_command == 'Y') {
            global_rerun = 1;
        } else {
            global_rerun = 0;
        }

    } while (global_rerun);
}


void print_help()
{

}


void list_algorithms()
{
    printf("\n%d - Sorting algorithms: ", TYPE_SORTING);
    list_sort_alg();
}


void list_sort_alg() 
{
    for (int i = 0; i < sizeof(global_sortAlg)/sizeof(global_sortAlg[0]); i++) {
        printf("\n  %d - %s", i + 1, global_sortAlg[i].name);
    }
}


void init_algorithms()
{
   global_sortAlg[INSERTION_SORT].name = "Insertion Sort";
   global_sortAlg[INSERTION_SORT].execute = &run_insertion_sort;
   
   global_sortAlg[MERGE_SORT].name = "Merge Sort";
   global_sortAlg[MERGE_SORT].execute = &run_merge_sort;

   global_sortAlg[BUBBLE_SORT].name = "Bubble Sort";
   global_sortAlg[BUBBLE_SORT].execute = &run_bubble_sort;

   global_sortAlg[BUBBLE_SORT_V2].name = "Bubble Sort v2";
   global_sortAlg[BUBBLE_SORT_V2].execute = &run_bubble_sort_v2;
   
   global_sortAlg[BUBBLE_SORT_V3].name = "Bubble Sort v3";
   global_sortAlg[BUBBLE_SORT_V3].execute = &run_bubble_sort_v3;
}
