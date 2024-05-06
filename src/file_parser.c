#include<stdio.h>

void parse_solution_file(char* fileName, int sol[9][9]) {

    FILE *file = fopen(fileName, "r");
    int i, j;

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
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
