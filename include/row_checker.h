#ifndef ROW_CHECKER_H
#define ROW_CHECKER_H

#include<pthread.h>

typedef struct {
    int (*sol)[9];
    int (*row)[9];
    int (*sub)[9];
    int i;
    int* counter;
    pthread_mutex_t* mutex;
} RowCheckerParams;

void* row_checker (void* ptr);

int is_valid_row(int row[9]);

int is_valid_sub(int (*sol)[9], int subIndex);

#endif
