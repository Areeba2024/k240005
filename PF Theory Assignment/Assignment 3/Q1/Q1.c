#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    char dateOfJoining[20];
};

void assign(struct Employee emp[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter details for Employee %d:\n", i + 1);

        printf("Enter Employee Code: ");
        scanf("%d", &emp[i].employeeCode);
        getchar();

        printf("Enter Employee Name: ");
        fgets(emp[i].employeeName, 50, stdin);
        strtok(emp[i].employeeName, "\n");

        printf("Enter Date of Joining (YYYY-MM-DD): ");
        fgets(emp[i].dateOfJoining, 20, stdin);
        strtok(emp[i].dateOfJoining, "\n");
    }
}

void calculateTenure(struct Employee emp[], int size) {
    char currentDate[20];
    int count = 0;

    printf("\nEnter the current date (YYYY-MM-DD): ");
    fgets(currentDate, 20, stdin);
    strtok(currentDate, "\n");

    printf("\nEmployees with more than 3 years of tenure:\n");
    printf("\n");

    for (int i = 0; i < size; i++) {
        int joinYear, currentYear;

        sscanf(emp[i].dateOfJoining, "%d", &joinYear);
        sscanf(currentDate, "%d", &currentYear);

        int tenure = currentYear - joinYear;

        if (tenure > 3) {
            printf("Employee Code: %d\n", emp[i].employeeCode);
            printf("Employee Name: %s\n", emp[i].employeeName);
            printf("Tenure: %d years\n", tenure);
            printf("\n");
            count++;
        }
    }

    printf("Total employees with more than 3 years of tenure: %d\n", count);
}

int main() {
    struct Employee emp[4];

    assign(emp, 4);

    calculateTenure(emp, 4);

    return 0;
}
