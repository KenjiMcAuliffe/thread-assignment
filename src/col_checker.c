#include<stdio.h>

#include"col_checker.h"

void* col_checker (void* ptr) {

    ColCheckerParams* params;
    int (*sol)[9];

    printf("Col Checker Started\n");

    params = (ColCheckerParams*)ptr;
    sol = params->sol;

    return NULL;

}
