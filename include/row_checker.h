#ifndef ROW_CHECKER_H
#define ROW_CHECKER_H

typedef struct {
    int (*sol)[9];
    int i;
} RowCheckerParams;

void* row_checker (void* ptr);

#endif
