#include<stdio.h>

#include"config.h"

void parse_solution_file(int sol[9][9]) {

    /* ---------------------------- BEGIN ----------------------------- */

    /* -------------------- VARIABLE DECLARATIONS --------------------- */

    FILE *file;

    /* ------------------------ INITIALZATION ------------------------- */

    file = fopen(SOLUTION_FILE_NAME, "r");

    /* ------------------------- FILE READING ------------------------- */

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

    /* ------------------------------ END ----------------------------- */

    fclose(file);

}
