#include<stdio.h>
#include<pthread.h>

#include"file_parser.h"
#include"row_checker.h"
#include"col_checker.h"

int main(void) {

    /* ------------------ VARIABLE DECLARATIONS ----------------------- */

    int sol[9][9];
    int row[9];
    int col[9];
    int sub[9];
    int counter;
    pthread_t rowThreads[3];
    pthread_t colThread;
    int i;
    int thread_indices[3] = {0, 1, 2};


    /* ---------------------- INITIALIZATION -------------------------- */

    parse_solution_file(sol);
    counter = 0;

    printf("Analysing the following sudoku solution:\n");
    print_sol(sol);
    printf("\n");

    /* --------------------- THREAD CREATION -------------------------- */

    for(i = 0; i < 3; i++) {
        pthread_create(
            &rowThreads[i],
            NULL,
            row_checker,
            (void*)&thread_indices[i]
        );
    }

    pthread_create(&colThread, NULL, col_checker, NULL);

    /* -------------------------- CLEANUP ----------------------------- */

    for(i = 0; i < 3; i++) {
        pthread_join(rowThreads[i], NULL);
    }
    pthread_join(colThread, NULL);

    return 0;

}
