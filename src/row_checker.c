#include<stdio.h>

void* row_checker (void* ptr) {

    int myIndex = *((int*)ptr);

    printf("Row Checker %d Started\n", myIndex);

    return NULL;

}
