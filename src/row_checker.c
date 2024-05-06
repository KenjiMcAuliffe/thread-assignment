#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#include"row_checker.h"

void* row_checker (void* ptr) {

    RowCheckerParams* params = (RowCheckerParams*)ptr;
    int startIndex = (params->i) * 3;
    int i, correctCount = 0;

    for(i = startIndex; i < startIndex + 3; i++) {
        int isValid;

        isValid = is_valid_row(params->sol[i]);
        correctCount += isValid;
        (*(params->row))[i] = isValid;
        usleep(params->iterationDelay * 1000000);

        isValid = is_valid_sub(params->sol, i);
        correctCount += isValid;
        (*(params->sub))[i] = isValid;
        usleep(params->iterationDelay * 1000000);
    }

    pthread_mutex_lock(params->counterMutex);
    *(params->counter) += correctCount;
    pthread_mutex_unlock(params->counterMutex);

    pthread_mutex_lock(params->finishedCountMutex);
    *(params->finishedCount) += 1;
    if(*(params->finishedCount) == 4) {
        printf("Thread ID-%d is the last thread.\n", (params->i + 1));
    }
    pthread_mutex_unlock(params->finishedCountMutex);

    return NULL;

}

int is_valid_row(int row[9]) {

    int isValid = 1;
    int seen[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;

    for(i = 0; i < 9; i++) {
        int num = row[i];
        if(seen[num - 1] == 1) {
            isValid = 0;
        }
        seen[num - 1] = 1;
    }

    return isValid;

}

int is_valid_sub(int (*sol)[9], int subIndex) {

    int isValid = 1;
    int seen[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int startRowIndex = subIndex - (subIndex % 3);
    int startColIndex = (subIndex % 3) * 3;
    int r;
    int c;

    for(r = startRowIndex; r < startRowIndex + 3; r++) {
        for(c = startColIndex; c < startColIndex + 3; c++) {
            int curVal = sol[r][c];
            if(seen[curVal - 1] == 1) {
                isValid = 0;
            }
            seen[curVal - 1] = 1;
        }
    }

    return isValid;

}
