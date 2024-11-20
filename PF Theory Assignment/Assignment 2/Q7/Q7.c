#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


void fillGrid(char grid[6][5], int id_digits[4]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = 'A' + (rand() % 26);
        }
    }
    for (int j = 0; j < 4; j++) {
        grid[5][j] = '0' + id_digits[j];
    }
    grid[5][4] = 'A' + (rand() % 26);
}


void showGrid(char grid[6][5]) {
    printf("---------------------\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
        printf("---------------------\n");
    }
}


int findString(char grid[6][5], char *str) {
    int len = strlen(str);

    for (int i = 0; i < 6; i++) { // Row-wise
        for (int j = 0; j <= 5 - len; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (grid[i][j + k] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
        }
    }

    for (int j = 0; j < 5; j++) { // Column-wise
        for (int i = 0; i <= 6 - len; i++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (grid[i + k][j] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
        }
    }

    return 0;
}

int main() {
    char grid[6][5];
    int id_digits[4] = {0, 0, 0, 5};
    int score = 0;
    char input[20];

    srand(time(0));

    fillGrid(grid, id_digits); 

    while (1) {
        showGrid(grid);

        printf("\nEnter a search string (or 'END' to exit): ");
        scanf("%s", input);

        for (int i = 0; input[i]; i++) 
        { 
            input[i] = toupper(input[i]);
        }

        if (strcmp(input, "END") == 0) 
        {
            fillGrid(grid, id_digits); 
            break;
        }

        if (findString(grid, input)) {
            score++;
            printf("%s is present. Score: %d\n", input, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", input, score);
        }
    }

    return 0;
}
