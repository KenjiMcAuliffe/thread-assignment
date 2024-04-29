#include<stdio.h>

#include"col_checker.h"

void* col_checker (void* ptr) {

    int c;
    int (*sol)[9];
    int (*col)[9];

    sol = ((ColCheckerParams*)ptr)->sol;
    col = ((ColCheckerParams*)ptr)->col;

    for(c = 0; c < 9; c++) {
        (*col)[c] = is_valid_col(sol, c);
    }

    return NULL;

}

int is_valid_col(int (*sol)[9], int colIndex) {

    int isValid;
    int seen[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int r;

    isValid = 1;

    for(r = 0; r < 9; r++) {
        int (*row)[9] = sol[r];
        int val = (*row)[colIndex];

        if(seen[val - 1] == 1) {
            isValid = 0;
        }

        seen[val - 1] = 1;
    }

    return isValid;
}
