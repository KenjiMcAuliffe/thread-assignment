#ifndef COL_CHECKER_H
#define COL_CHECKER_H

typedef struct {
    int (*sol)[9];
    int (*col)[9];
} ColCheckerParams;

void* col_checker (void* ptr);

int is_valid_col(int (*sol)[9], int colIndex);

#endif
