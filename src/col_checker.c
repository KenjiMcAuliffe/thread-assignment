#include<stdio.h>

#include"col_checker.h"

void* col_checker (void* ptr) {

    int (*sol)[9];

    printf("Col Checker Started.\n");

    sol = ((ColCheckerParams*)ptr)->sol;

    /* Check Columns */

    printf("Col Checker Finished.\n");

    return NULL;

}
