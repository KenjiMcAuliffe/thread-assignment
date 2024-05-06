#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#include"col_checker.h"

void* col_checker (void* ptr) {

    ColCheckerParams* params = (ColCheckerParams*)ptr;
    int c, correctCount = 0;

    for(c = 0; c < 9; c++) {
        int isValid = is_valid_col(params->sol, c);
        correctCount += isValid;
        (*(params->col))[c] = isValid;
        usleep(params->iterationDelay * 1000000);
    }

    pthread_mutex_lock(params->counterMutex);
    *(params->counter) += correctCount;
    pthread_mutex_unlock(params->counterMutex);

    pthread_mutex_lock(params->finishedCountMutex);
    *(params->finishedCount) += 1;
    if(*(params->finishedCount) == 4) {
        printf("Thread ID-4 is the last thread.\n");
    }
    pthread_mutex_unlock(params->finishedCountMutex);

    return NULL;

}

int is_valid_col(int (*sol)[9], int colIndex) {

    int isValid = 1;
    int seen[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int r;

    for(r = 0; r < 9; r++) {
        int (*row)[9] = &sol[r];
        int val = (*row)[colIndex];

        if(seen[val - 1] == 1) {
            isValid = 0;
        }

        seen[val - 1] = 1;
    }

    return isValid;
}
