#include<stdio.h>

#include"row_checker.h"

void* row_checker (void* ptr) {

    int myIndex;
    int startRowIndex;
    int (*sol)[9];
    int (*row)[9];
    int i;

    myIndex = ((RowCheckerParams*)ptr)->i;
    printf("Row checker %d started.\n", myIndex);
    startRowIndex = (myIndex * 3);
    row = ((RowCheckerParams*)ptr)->row;
    sol = ((RowCheckerParams*)ptr)->sol;

    for(i = startRowIndex; i < startRowIndex + 3; i++) {
        (*row)[i] = is_valid_row(sol[i]);
    }

    /* Check subgrids */

    printf("Row checker %d finished.\n", myIndex);
    return NULL;

}

int is_valid_row(int row[9]) {

    int isValid;
    int seen[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;

    isValid = 1;

    for(i = 0; i < 9; i++) {
        int num = row[i];
        if(seen[num - 1] == 1) {
            isValid = 0;
        }
        seen[num - 1] = 1;
    }

    return isValid;

}
