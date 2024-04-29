#ifndef ROW_CHECKER_H
#define ROW_CHECKER_H

typedef struct {
    int (*sol)[9];
    int (*row)[9];
    int (*sub)[9];
    int i;
} RowCheckerParams;

void* row_checker (void* ptr);

int isValidRow(int row[9]);

#endif
