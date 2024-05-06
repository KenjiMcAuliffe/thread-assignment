#include<stdlib.h>

void parse_arguments(int argc, char* argv[], int* iterationDelay, char** fileName) {
    *iterationDelay = atoi(argv[1]);
    *fileName = argv[2];
}
