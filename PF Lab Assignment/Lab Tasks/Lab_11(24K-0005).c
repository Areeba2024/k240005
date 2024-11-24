//Q1
#include <stdio.h>
#include <string.h>

#define max_employees 100
#define max_departments 10

// Structure for Employee
typedef struct {
    char name[50];
    int id;
    int salary;
} Employee;

typedef struct {
    char name[50];
    Employee employees[max_employees];
    int numEmployees; // Keeps track of the number of employees in the department
} Department;


int calculateTotalSalary(Department *dept) {
    int totalSalary = 0;
    for (int i = 0; i < dept->numEmployees; i++) {
        totalSalary += dept->employees[i].salary;
    }
    return totalSalary;
}

int main() {
    
    Department departments[max_departments];
    int numDepartments = 2;

    strcpy(departments[0].name, "IT");
    departments[0].numEmployees = 2;

    strcpy(departments[0].employees[0].name, "Alice");
    departments[0].employees[0].id = 101;
    departments[0].employees[0].salary = 50000;

    strcpy(departments[0].employees[1].name, "Bob");
    departments[0].employees[1].id = 102;
    departments[0].employees[1].salary = 60000;

    strcpy(departments[1].name, "HR");
    departments[1].numEmployees = 2;

    strcpy(departments[1].employees[0].name, "Charlie");
    departments[1].employees[0].id = 103;
    departments[1].employees[0].salary = 45000;

    strcpy(departments[1].employees[1].name, "Diana");
    departments[1].employees[1].id = 104;
    departments[1].employees[1].salary = 48000;

    char targetDepartment[50];
    printf("Enter the department name to calculate total salary: ");
    scanf("%s", targetDepartment);

    int found = 0;
    for (int i = 0; i < numDepartments; i++) {
        if (strcmp(departments[i].name, targetDepartment) == 0) {
            int totalSalary = calculateTotalSalary(&departments[i]);
            printf("Total salary of the %s department: %d\n", targetDepartment, totalSalary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Department '%s' not found.\n", targetDepartment);
    }

    return 0;
}

//Q2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    int salary;
} Employee;

void addEmployeeRecords(const char *filename) {
    FILE *fptr = fopen(filename, "ab");
    if (!fptr) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    char choice;

    do {
        printf("\nEnter Employee Name: ");
        scanf(" %[^\n]", emp.name);
        printf("Enter Employee ID: ");
        scanf("%d", &emp.id);
        printf("Enter Employee Salary: ");
        scanf("%d", &emp.salary);

        fwrite(&emp, sizeof(Employee), 1, fptr);

        printf("Do you want to add another employee? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    fclose(fptr);
    printf("Employee records have been added successfully.\n");
}

void calculateTotalSalaryExpense(const char *filename) {
    FILE *fptr = fopen(filename, "rb");
    if (!fptr) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    int totalSalary = 0;

    printf("\nEmployee Records:\n");
    printf("%-20s %-10s %-10s\n", "Name", "ID", "Salary");

    while (fread(&emp, sizeof(Employee), 1, fptr)) {
        printf("%-20s %-10d %-10d\n", emp.name, emp.id, emp.salary);
        totalSalary += emp.salary;
    }

    printf("\nTotal Salary Expense: %d\n", totalSalary);

    fclose(fptr);
}

int main() {
    const char *filename = "employee_records.bin";
    int choice;

    do {
        printf("\nEmployee Salary Record Management");
        printf("\n1. Add Employee Records");
        printf("\n2. Calculate Total Salary Expense");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployeeRecords(filename);
                break;
            case 2:
                calculateTotalSalaryExpense(filename);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

//Q3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    char code[10];
    char instructor[50];
    int totalEnrolled; 
} Course;

typedef struct {
    char name[50];
    int rollNumber;
    char courses[MAX_COURSES][10]; 
    int numCourses;                
} Student;

void saveStudentEnrollment(const char *filename, Student students[], int studentCount) {
    FILE *fptr = fopen(filename, "wb");
    if (!fptr) {
        perror("Error opening file");
        return;
    }
    fwrite(students, sizeof(Student), studentCount, fptr);
    fclose(fptr);
    printf("Student enrollment data saved successfully.\n");
}

void loadStudentEnrollment(const char *filename, Student students[], int *studentCount) {
    FILE *fptr = fopen(filename, "rb");
    if (!fptr) {
        perror("Error opening file");
        return;
    }
    *studentCount = fread(students, sizeof(Student), MAX_STUDENTS, fptr);
    fclose(fptr);
}

void addStudent(Student students[], int *studentCount, Course courses[], int courseCount) {
    Student newStudent;
    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);

    printf("Available Courses:\n");
    for (int i = 0; i < courseCount; i++) {
        printf("%d. %s (%s) - %s\n", i + 1, courses[i].name, courses[i].code, courses[i].instructor);
    }

    printf("Enter the number of courses to enroll in: ");
    scanf("%d", &newStudent.numCourses);

    for (int i = 0; i < newStudent.numCourses; i++) {
        printf("Enter the course code for course %d: ", i + 1);
        scanf("%s", newStudent.courses[i]);

        for (int j = 0; j < courseCount; j++) {
            if (strcmp(newStudent.courses[i], courses[j].code) == 0) {
                courses[j].totalEnrolled++;
                break;
            }
        }
    }

    students[*studentCount] = newStudent;
    (*studentCount)++;
    printf("Student added successfully.\n");
}

void displayStudentCourses(Student students[], int studentCount) {
    int rollNumber;
    printf("\nEnter Roll Number to display courses: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student Name: %s\n", students[i].name);
            printf("Courses Enrolled:\n");
            for (int j = 0; j < students[i].numCourses; j++) {
                printf("%s\n", students[i].courses[j]);
            }
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNumber);
}

void generateCourseReport(Course courses[], int courseCount) {
    printf("\nCourse Enrollment Report:\n");
    for (int i = 0; i < courseCount; i++) {
        printf("%s (%s) - Instructor: %s, Total Enrolled: %d\n",
               courses[i].name, courses[i].code, courses[i].instructor, courses[i].totalEnrolled);
    }
}

void modifyEnrollment(Student students[], int studentCount, Course courses[], int courseCount) {
    int rollNumber;
    printf("\nEnter Roll Number to modify enrollment: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student Name: %s\n", students[i].name);
            printf("Current Courses:\n");
            for (int j = 0; j < students[i].numCourses; j++) {
                printf("%s\n", students[i].courses[j]);
            }

            printf("Enter the number of new courses to enroll in: ");
            int newCourseCount;
            scanf("%d", &newCourseCount);

            for (int j = 0; j < students[i].numCourses; j++) {
                for (int k = 0; k < courseCount; k++) {
                    if (strcmp(students[i].courses[j], courses[k].code) == 0) {
                        courses[k].totalEnrolled--;
                        break;
                    }
                }
            }

            students[i].numCourses = newCourseCount;
            for (int j = 0; j < newCourseCount; j++) {
                printf("Enter the course code for course %d: ", j + 1);
                scanf("%s", students[i].courses[j]);

                for (int k = 0; k < courseCount; k++) {
                    if (strcmp(students[i].courses[j], courses[k].code) == 0) {
                        courses[k].totalEnrolled++;
                        break;
                    }
                }
            }

            printf("Enrollment updated successfully.\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNumber);
}

int main() {
    Course courses[MAX_COURSES] = {
        {"Mathematics", "MATH101", "Dr. Smith", 0},
        {"Physics", "PHYS101", "Dr. Brown", 0},
        {"Chemistry", "CHEM101", "Dr. White", 0}};
    int courseCount = 3;

    Student students[MAX_STUDENTS];
    int studentCount = 0;

    const char *filename = "student_enrollment.bin";

    loadStudentEnrollment(filename, students, &studentCount);

    int choice;
    do {
        printf("\nStudent Course Enrollment System");
        printf("\n1. Add Student");
        printf("\n2. Display Courses by Student");
        printf("\n3. Generate Course Enrollment Report");
        printf("\n4. Modify Course Enrollment");
        printf("\n5. Save and Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount, courses, courseCount);
                break;
            case 2:
                displayStudentCourses(students, studentCount);
                break;
            case 3:
                generateCourseReport(courses, courseCount);
                break;
            case 4:
                modifyEnrollment(students, studentCount, courses, courseCount);
                break;
            case 5:
                saveStudentEnrollment(filename, students, studentCount);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

//Q4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 1000
#define MAX_FIELD_LENGTH 100

typedef struct {
    int passengerId;
    int pclass;
    char name[MAX_FIELD_LENGTH];
    char sex[MAX_FIELD_LENGTH];
    float age;
    int sibSp;
    int parch;
    char ticket[MAX_FIELD_LENGTH];
    float fare;
    char cabin[MAX_FIELD_LENGTH];
    char embarked[MAX_FIELD_LENGTH];
    int survived; // 1 = survived, 0 = did not survive
} Passenger;

void loadCSV(const char *filename, Passenger passengers[], int *count) {
    FILE *fptr = fopen(filename, "r");
    if (!fptr) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    fgets(line, sizeof(line), fptr); // Skip header

    *count = 0;
    while (fgets(line, sizeof(line), fptr)) {
        Passenger *p = &passengers[*count];
        sscanf(line, "%d,%d,%[^,],%[^,],%f,%d,%d,%[^,],%f,%[^,],%[^,],%d",
               &p->passengerId, &p->pclass, p->name, p->sex, &p->age,
               &p->sibSp, &p->parch, p->ticket, &p->fare, p->cabin,
               p->embarked, &p->survived);
        (*count)++;
    }
    fclose(fptr);
}

float calculateAverageAge(Passenger passengers[], int count) {
    float totalAge = 0;
    int ageCount = 0;
    for (int i = 0; i < count; i++) {
        if (passengers[i].age > 0) {
            totalAge += passengers[i].age;
            ageCount++;
        }
    }
    return (ageCount > 0) ? totalAge / ageCount : 0;
}

void calculateSurvivalRateBySex(Passenger passengers[], int count) {
    int maleSurvived = 0, maleTotal = 0;
    int femaleSurvived = 0, femaleTotal = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].sex, "male") == 0) {
            maleTotal++;
            if (passengers[i].survived) maleSurvived++;
        } else if (strcmp(passengers[i].sex, "female") == 0) {
            femaleTotal++;
            if (passengers[i].survived) femaleSurvived++;
        }
    }

    printf("Survival Rate (Male): %.2f%%\n", (maleTotal > 0) ? (maleSurvived * 100.0 / maleTotal) : 0);
    printf("Survival Rate (Female): %.2f%%\n", (femaleTotal > 0) ? (femaleSurvived * 100.0 / femaleTotal) : 0);
}

void displaySurvivors(Passenger passengers[], int count) {
    printf("\nSurvivors:\n");
    printf("%-10s %-30s %-5s %-10s\n", "ID", "Name", "Age", "Class");

    for (int i = 0; i < count; i++) {
        if (passengers[i].survived) {
            printf("%-10d %-30s %-5.1f %-10d\n",
                   passengers[i].passengerId,
                   passengers[i].name,
                   passengers[i].age,
                   passengers[i].pclass);
        }
    }
}

void displayMissingCabinPassengers(Passenger passengers[], int count) {
    printf("\nPassengers with Missing Cabin Details:\n");
    printf("%-10s %-30s %-5s\n", "ID", "Name", "Class");

    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].cabin, "") == 0) {
            printf("%-10d %-30s %-5d\n",
                   passengers[i].passengerId,
                   passengers[i].name,
                   passengers[i].pclass);
        }
    }
}

int main() {
    Passenger passengers[MAX_PASSENGERS];
    int passengerCount = 0;

    loadCSV("titanic.csv", passengers, &passengerCount);

    printf("Average Age of Passengers: %.2f\n", calculateAverageAge(passengers, passengerCount));
    calculateSurvivalRateBySex(passengers, passengerCount);
    displaySurvivors(passengers, passengerCount);
    displayMissingCabinPassengers(passengers, passengerCount);

    return 0;
}


