#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* ratings;
    int totalScore;
} Employee;

void inputEmployees(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
        printf("Enter ratings for employee %d across %d periods (1 to 10):\n", i + 1, numPeriods);

        for (int j = 0; j < numPeriods; j++) {
            while (1) {
                printf("Period %d: ", j + 1);
                scanf("%d", &ratings[i][j]);

                if (ratings[i][j] >= 1 && ratings[i][j] <= 10) {
                    break;
                } else {
                    printf("Invalid input! Rating must be between 1 and 10. Try again.\n");
                }
            }
        }
    }
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d ratings:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("Period %d: %d\n", j + 1, ratings[i][j]);
        }
    }
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) {
    int bestEmployeeIndex = -1;
    float highestAverage = 0.0;

    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        float average = (float)total / numPeriods;

        if (average > highestAverage) {
            highestAverage = average;
            bestEmployeeIndex = i;
        }
    }
    return bestEmployeeIndex;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
    int bestPeriodIndex = -1;
    float highestAverage = 0.0;

    for (int j = 0; j < numPeriods; j++) {
        int total = 0;
        for (int i = 0; i < numEmployees; i++) {
            total += ratings[i][j];
        }
        float average = (float)total / numEmployees;

        if (average > highestAverage) {
            highestAverage = average;
            bestPeriodIndex = j;
        }
    }
    return bestPeriodIndex;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) {
    int worstEmployeeIndex = -1;
    float lowestAverage = 11.0;

    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        float average = (float)total / numPeriods;

        if (average < lowestAverage) {
            lowestAverage = average;
            worstEmployeeIndex = i;
        }
    }
    return worstEmployeeIndex;
}

int main() {
    int numEmployees, numPeriods;

    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int** ratings = (int**)malloc(numEmployees * sizeof(int*));

    if (ratings == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    inputEmployees(ratings, numEmployees, numPeriods);
    printf("Employee Performance\n");
    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the Year: Employee %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Evaluation Period: Period %d\n", highestRatedPeriod + 1);

    int worstPerformingEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstPerformingEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
