#include<stdio.h>

#include"row_checker.h"

void* row_checker (void* ptr) {

    RowCheckerParams* params;
    int myIndex;
    int (*sol)[9];

    params = (RowCheckerParams*)ptr;
    myIndex = params->i;
    sol = params->sol;

    printf("Row Checker %d Started\n", params->i);

    return NULL;

}
