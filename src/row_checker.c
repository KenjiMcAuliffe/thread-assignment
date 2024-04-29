#include<stdio.h>

#include"row_checker.h"

void* row_checker (void* ptr) {

    /* --------------------------- BEGIN ------------------------------ */

    /* -------------------- VARIABLE DECLARATIONS --------------------- */

    int myIndex;
    int startRowIndex;
    int startSubIndex;
    int (*sol)[9];
    int (*row)[9];
    int (*sub)[9];
    int i;

    /* ------------------------ INITIALZATION ------------------------ */

    myIndex = ((RowCheckerParams*)ptr)->i;
    startRowIndex = myIndex * 3;
    startSubIndex = myIndex * 3;
    row = ((RowCheckerParams*)ptr)->row;
    sol = ((RowCheckerParams*)ptr)->sol;
    sub = ((RowCheckerParams*)ptr)->sub;

    /* -------------------------- CHECK ROWS -------------------------- */

    for(i = startRowIndex; i < startRowIndex + 3; i++) {
        (*row)[i] = is_valid_row(sol[i]);
    }

    /* ------------------------ CHECK SUBGRIDS ------------------------ */

    for(i = startSubIndex; i < startSubIndex + 3; i++) {
        (*sub)[i] = is_valid_sub(sol, i);
    }

    /* ----------------------------- END ------------------------------ */

    return NULL;

}

int is_valid_row(int row[9]) {

    /* --------------------------- BEGIN ------------------------------ */

    /* -------------------- VARIABLE DECLARATIONS --------------------- */

    int isValid;
    int seen[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;

    /* ------------------------ INITIALZATION ------------------------ */

    isValid = 1;

    /* --------------------------- CHECKING -------------------------- */

    for(i = 0; i < 9; i++) {
        int num = row[i];
        if(seen[num - 1] == 1) {
            isValid = 0;
        }
        seen[num - 1] = 1;
    }

    /* -----------------------------  END ---------------------------- */

    return isValid;

}

int is_valid_sub(int (*sol)[9], int subIndex) {

    /* --------------------------- BEGIN ------------------------------ */

    /* -------------------- VARIABLE DECLARATIONS --------------------- */

    int isValid;
    int seen[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int startRowIndex;
    int startColIndex;
    int r;
    int c;

    /* ------------------------ INITIALZATION ------------------------ */

    isValid = 1;
    startRowIndex = subIndex - (subIndex % 3);
    startColIndex = (subIndex % 3) * 3;

    /* --------------------------- CHECKING -------------------------- */

    for(r = startRowIndex; r < startRowIndex + 3; r++) {
        for(c = startColIndex; c < startColIndex + 3; c++) {
            int curVal = sol[r][c];
            if(seen[curVal - 1] == 1) {
                isValid = 0;
            }
            seen[curVal - 1] = 1;
        }
    }

    /* -----------------------------  END ---------------------------- */

    return isValid;

}
