#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include"file_parser.h"
#include"row_checker.h"
#include"col_checker.h"

int main(void) {

    /* ---------------------------- BEGIN ----------------------------- */

    /* -------------------- VARIABLE DECLARATIONS --------------------- */

    int sol[9][9];
    int row[9];
    int col[9];
    int sub[9];
    int counter;

    pthread_t rowThreads[3];
    RowCheckerParams rowCheckerParams[3];

    pthread_t colThread;
    ColCheckerParams colCheckerParams;

    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    int i;

    /* ---------------------- INITIALIZATION -------------------------- */

    parse_solution_file(sol);
    counter = 0;

    /* --------------------- THREAD CREATION -------------------------- */

    for(i = 0; i < 3; i++) {
        rowCheckerParams[i].i = i;
        rowCheckerParams[i].sol = (int(*)[9])sol;
        rowCheckerParams[i].row = (int(*)[9])row;
        rowCheckerParams[i].sub = (int(*)[9])sub;
        rowCheckerParams[i].counter = &counter;
        rowCheckerParams[i].mutex = &mutex;
        pthread_create(
            &rowThreads[i],
            NULL,
            row_checker,
            (void*)&rowCheckerParams[i]
        );
    }

    colCheckerParams.sol = (int(*)[9])sol;
    colCheckerParams.col = (int(*)[9])col;
    colCheckerParams.counter = &counter;
    colCheckerParams.mutex = &mutex;
    pthread_create(&colThread, NULL, col_checker, (void*)&colCheckerParams);

    /* -------------------------- CLEANUP ----------------------------- */

    for(i = 0; i < 3; i++) {
        pthread_join(rowThreads[i], NULL);
    }
    pthread_join(colThread, NULL);

    /* --------------------------- OUTPUT ----------------------------- */

    printf("Rows: ");
    for(i = 0; i < 9; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");

    printf("Cols: ");
    for(i = 0; i < 9; i++) {
        printf("%d ", col[i]);
    }
    printf("\n");

    printf("Subs: ");
    for(i = 0; i < 9; i++) {
        printf("%d ", sub[i]);
    }
    printf("\n");

    printf("Counter: %d\n", counter);

    /* ----------------------------- END ------------------------------ */

    return 0;

}
