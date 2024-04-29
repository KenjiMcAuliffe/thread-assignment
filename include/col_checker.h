#ifndef COL_CHECKER_H
#define COL_CHECKER_H

typedef struct {
    int (*sol)[9];
} ColCheckerParams;

void* col_checker (void* ptr);

#endif
