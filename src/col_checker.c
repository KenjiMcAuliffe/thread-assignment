#include<stdio.h>
#include<pthread.h>

#include"col_checker.h"

void* col_checker (void* ptr) {

    /* ---------------------------- BEGIN ----------------------------- */

    /* -------------------- VARIABLE DECLARATIONS --------------------- */

    int c;
    int (*sol)[9];
    int (*col)[9];
    int* counter;
    pthread_mutex_t* mutex;

    /* ---------------------- INITIALIZATION -------------------------- */

    sol = ((ColCheckerParams*)ptr)->sol;
    col = ((ColCheckerParams*)ptr)->col;
    counter = ((ColCheckerParams*)ptr)->counter;
    mutex = ((ColCheckerParams*)ptr)->mutex;

    /* ------------------------- CHECKING ----------------------------- */

    for(c = 0; c < 9; c++) {
        int isValid = is_valid_col(sol, c);

        pthread_mutex_lock(mutex);
        *counter += isValid;
        pthread_mutex_unlock(mutex);

        (*col)[c] = isValid;
    }

    /* --------------------------- END -------------------------------- */

    return NULL;

}

int is_valid_col(int (*sol)[9], int colIndex) {

    /* ---------------------------- BEGIN ----------------------------- */

    /* -------------------- VARIABLE DECLARATIONS --------------------- */

    int isValid;
    int seen[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int r;

    /* ---------------------- INITIALIZATION -------------------------- */

    isValid = 1;

    /* ------------------------- CHECKING ----------------------------- */

    for(r = 0; r < 9; r++) {
        int (*row)[9] = &sol[r];
        int val = (*row)[colIndex];

        if(seen[val - 1] == 1) {
            isValid = 0;
        }

        seen[val - 1] = 1;
    }

    /* --------------------------- END -------------------------------- */

    return isValid;
}
