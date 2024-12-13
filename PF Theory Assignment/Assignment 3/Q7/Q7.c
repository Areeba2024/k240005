#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    double rating;
    int runtime;
    char encodingFormat[20];
} ContentMetadata;

double** initializeEngagementMatrix(int users, int categories) {
    double** matrix = (double**)malloc(users * sizeof(double*));
    for (int i = 0; i < users; i++) {
        matrix[i] = (double*)calloc(categories, sizeof(double));
    }
    return matrix;
}

char*** initializeDeviceMatrix(int users, int devices) {
    char*** matrix = (char***)malloc(users * sizeof(char**));
    for (int i = 0; i < users; i++) {
        matrix[i] = (char**)malloc(devices * sizeof(char*));
        for (int j = 0; j < devices; j++) {
            matrix[i][j] = (char*)calloc(100, sizeof(char));
            sprintf(matrix[i][j], "Default Resolution: 1080p");
        }
    }
    return matrix;
}

ContentMetadata** initializeContentMetadata(int categories, int itemsPerCategory) {
    ContentMetadata** matrix = (ContentMetadata**)malloc(categories * sizeof(ContentMetadata*));
    for (int i = 0; i < categories; i++) {
        matrix[i] = (ContentMetadata*)malloc(itemsPerCategory * sizeof(ContentMetadata));
        for (int j = 0; j < itemsPerCategory; j++) {
            sprintf(matrix[i][j].title, "Category %d - Item %d", i + 1, j + 1);
            matrix[i][j].rating = 5.0;
            matrix[i][j].runtime = 120;
            strcpy(matrix[i][j].encodingFormat, "H.264");
        }
    }
    return matrix;
}

void freeEngagementMatrix(double** matrix, int users) {
    for (int i = 0; i < users; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeDeviceMatrix(char*** matrix, int users, int devices) {
    for (int i = 0; i < users; i++) {
        for (int j = 0; j < devices; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

void freeContentMetadata(ContentMetadata** matrix, int categories) {
    for (int i = 0; i < categories; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int users = 3;
    int categories = 4;
    int devices = 2;
    int itemsPerCategory = 5;

    double** engagementMatrix = initializeEngagementMatrix(users, categories);
    char*** deviceMatrix = initializeDeviceMatrix(users, devices);
    ContentMetadata** contentMetadata = initializeContentMetadata(categories, itemsPerCategory);

    engagementMatrix[0][1] = 4.5;
    printf("Engagement Score for User 0, Category 1: %.1f\n", engagementMatrix[0][1]);

    strcpy(deviceMatrix[1][0], "Resolution: 4K");
    printf("Device Preference for User 1, Device 0: %s\n", deviceMatrix[1][0]);

    printf("Content Title: %s, Rating: %.1f, Runtime: %d mins, Format: %s\n",
           contentMetadata[2][3].title,
           contentMetadata[2][3].rating,
           contentMetadata[2][3].runtime,
           contentMetadata[2][3].encodingFormat);

    freeEngagementMatrix(engagementMatrix, users);
    freeDeviceMatrix(deviceMatrix, users, devices);
    freeContentMetadata(contentMetadata, categories);

    return 0;
}
