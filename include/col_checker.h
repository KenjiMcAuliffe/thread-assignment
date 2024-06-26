#ifndef COL_CHECKER_H
#define COL_CHECKER_H

#include<pthread.h>

typedef struct {
    int (*sol)[9];
    int (*col)[9];
    int* counter;
    int* finishedCount;
    int iterationDelay;
    pthread_mutex_t* counterMutex;
    pthread_mutex_t* finishedCountMutex;
} ColCheckerParams;

void* col_checker (void* ptr);

int is_valid_col(int (*sol)[9], int colIndex);

#endif
