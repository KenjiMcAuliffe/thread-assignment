#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include"argument_parser.h"
#include"file_parser.h"
#include"row_checker.h"
#include"col_checker.h"
#include"print_results.h"

int main(int argc, char* argv[]) {

    char* solutionFileName;
    int iterationDelay;
    int sol[9][9];
    int row[9];
    int col[9];
    int sub[9];
    int counter = 0;
    int finishedCount = 0;
    pthread_t rowThreads[3];
    RowCheckerParams rowCheckerParams[3];
    pthread_t colThread;
    ColCheckerParams colCheckerParams;
    pthread_mutex_t counterMutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t finishedCountMutex = PTHREAD_MUTEX_INITIALIZER;
    int i;

    parse_arguments(argc, argv, &iterationDelay, &solutionFileName);
    parse_solution_file(solutionFileName, sol);

    /* ------------------------- THREAD CREATION --------------------------- */

    for(i = 0; i < 3; i++) {
        rowCheckerParams[i].i = i;
        rowCheckerParams[i].sol = (int(*)[9])sol;
        rowCheckerParams[i].row = (int(*)[9])row;
        rowCheckerParams[i].sub = (int(*)[9])sub;
        rowCheckerParams[i].counter = &counter;
        rowCheckerParams[i].iterationDelay = iterationDelay;
        rowCheckerParams[i].counterMutex = &counterMutex;
        rowCheckerParams[i].finishedCount = &finishedCount;
        rowCheckerParams[i].finishedCountMutex = &finishedCountMutex;
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
    colCheckerParams.counterMutex = &counterMutex;
    colCheckerParams.iterationDelay = iterationDelay;
    colCheckerParams.finishedCount = &finishedCount;
    colCheckerParams.finishedCountMutex = &finishedCountMutex;
    pthread_create(&colThread, NULL, col_checker, (void*)&colCheckerParams);

    /* ------------------------------ CLEANUP ------------------------------ */

    for(i = 0; i < 3; i++) {
        pthread_join(rowThreads[i], NULL);
    }
    pthread_join(colThread, NULL);

    /* ------------------------------- OUTPUT ------------------------------ */

    print_results(row, sub, col, counter);

    /* ------------------------------- END --------------------------------- */

    return 0;
}
