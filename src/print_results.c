#include<stdio.h>
#include"print_results.h"

void print_results(int row[9], int sub[9], int col[9], int counter) {
    print_row_threads_results(row, sub);
    print_col_thread_results(col);
    printf("There are in total %d valid rows, columns, and sub-grids, and the solution is ", counter);
    printf(counter == 27 ? "valid." : "invalid." );
    printf("\n");
}

void print_col_thread_results(int col[9]) {
    int i;
    int invalidCount = 0;

    printf("Thread ID-4: ");

    for(i = 0; i < 9; i++) {
        if(col[i] == 0) {
            if(invalidCount != 0) {
                printf(", ");
            }
            printf("col %d", i);
            invalidCount++;
        }
    }

    print_result_end(invalidCount);
}

void print_row_threads_results(int row[9], int sub[9]) {
    int i;

    for(i = 0; i < 3; i++) {
        print_row_thread_results(row, sub, i);
    }
}

void print_row_thread_results(int row[9], int sub[9], int threadIndex) {
    int i;
    int startIndex = threadIndex * 3;
    int invalidCount = 0;

    printf("Thread ID-%d: ", (threadIndex + 1));

    for(i = startIndex; i < startIndex + 3; i++) {
        if(row[i] == 0) {
            if(invalidCount != 0) {
                printf(", ");
            }
            printf("row %d", i);
            invalidCount++;
        }

        if(sub[i] == 0) {
            if(invalidCount != 0) {
                printf(", ");
            }
            printf("sub %d", i);
            invalidCount++;
        }
    }

    print_result_end(invalidCount);
}

void print_result_end(int invalidCount) {
    if(invalidCount == 0) {
        printf("valid");
    }
    else if(invalidCount == 1) {
        printf(" is invalid");
    }
    else {
        printf(" are invalid");
    }
    printf("\n");
}
