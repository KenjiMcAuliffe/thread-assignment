#include<stdio.h>

#include"config.h"

void parse_solution_file(int sol[9][9]) {

    FILE *file = fopen(SOLUTION_FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // Read each integer from the file
            fscanf(file, "%d", &sol[i][j]);
        }
    }

    fclose(file);

}

void print_sol(int sol[9][9]) {

    int r, c;

    for(r = 0; r < 9; r++) {
        for(c = 0; c < 9; c++) {
            printf("%d ", sol[r][c]);
        }
        printf("\n");
    }

}

