#include <stdio.h>
#include <string.h>
#include "student.h"

// Function to input student data
void inputStudentData(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", &names[i]);

        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &rollNumbers[i]);

        printf("Enter marks for ISA 1 for student %d (5 subjects): ", i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &isa1[i][j]);
        }

        printf("Enter marks for ISA 2 for student %d (5 subjects): ", i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &isa2[i][j]);
        }

        printf("Enter marks for ESA for student %d (5 subjects): ", i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &ESA[i][j]);
        }
    }
}

// Function to calculate grade using switch-case
char calculateGrade(int marks) {
    char grade;
    switch (marks / 10) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
    }
    return grade;
}

// Function to calculate average marks
double calculateAverage(int marks[]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += marks[i];
    }
    return sum / 5.0;
}


// Function to generate final grade card
void generateFinalGradeCard(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents) {
    printf("\n------------------ Final Grade Card ------------------\n");
    printf("Roll No\tName\tFinal Grade\n");
    for (int i = 0; i < numStudents; i++) {
        double finalMarks = 0.25 * calculateAverage(isa1[i]) + 0.25 * calculateAverage(isa2[i]) + 0.5 * calculateAverage(ESA[i]);
        printf("%d\t%s\t%c\n", rollNumbers[i], names[i], calculateGrade(finalMarks));
    }
}

// Function to add a new student
void addStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int *numStudents) {
    printf("Adding a new student...\n");
    printf("Enter name for the new student: ");
    scanf("%s", names[*numStudents]);

    printf("Enter roll number for the new student: ");
    scanf("%d", &rollNumbers[*numStudents]);

    printf("Enter marks for ISA 1 for the new student (5 subjects): ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &isa1[*numStudents][j]);
    }

    printf("Enter marks for ISA 2 for the new student (5 subjects): ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &isa2[*numStudents][j]);
    }

    printf("Enter marks for ESA for the new student (5 subjects): ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &ESA[*numStudents][j]);
    }
    (*numStudents)++;
}

// Function to update student details
void updateStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to update: ");
    scanf("%d", &rollNumber);
    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (rollNumbers[i] == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
    printf("Enter new name for the student: ");
    scanf("%s", names[index]);

    printf("Enter new roll number for the student: ");
    scanf("%d", &rollNumbers[index]);

    printf("Enter new marks for ISA 1 for the student (5 subjects): ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &isa1[index][j]);
    }

    printf("Enter new marks for ISA 2 for the student (5 subjects): ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &isa2[index][j]);
    }

    printf("Enter new marks for ESA for the student (5 subjects): ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &ESA[index][j]);
    }
}

// Function to delete a student
void deleteStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int *numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollNumber);
    int index = -1;
    for (int i = 0; i < *numStudents; i++) {
        if (rollNumbers[i] == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
    // Shift remaining elements to fill the gap
    for (int i = index; i < *numStudents - 1; i++) {
        strcpy(names[i], names[i + 1]);
        rollNumbers[i] = rollNumbers[i + 1];
        for (int j = 0; j < 5; j++) {
            isa1[i][j] = isa1[i + 1][j];
            isa2[i][j] = isa2[i + 1][j];
            ESA[i][j] = ESA[i + 1][j];
        }
    }
    (*numStudents)--;
}

// Function to view final grade card of a specific student
void viewFinalGradeCardOfStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to view final grade card: ");
    scanf("%d", &rollNumber);
    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (rollNumbers[i] == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
    double finalMarks = 0.25 * calculateAverage(isa1[index]) + 0.25 * calculateAverage(isa2[index]) + 0.5 * calculateAverage(ESA[index]);
    printf("\n------------------ Final Grade Card for %s ------------------\n", names[index]);
    printf("Roll No: %d\n", rollNumbers[index]);
    printf("Final Grade: %c\n", calculateGrade(finalMarks));
}

// Function to view grade card for ISA 1, ISA 2, and ESA for a single student using roll number
void viewGradeCardForSingleStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to view grade card: ");
    scanf("%d", &rollNumber);
    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (rollNumbers[i] == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
    printf("\n------------------ Grade Card for %s ------------------\n", names[index]);
    printf("Roll No\tName\tSubject1\tSubject2\tSubject3\tSubject4\tSubject5\tFinal Grade\n");
    printf("%d\t%s\t", rollNumbers[index], names[index]);
    
    printf("ISA 1: ");
    for (int j = 0; j < 5; j++) {
        printf("%d(%c)\t\t", isa1[index][j], calculateGrade(isa1[index][j]));
    }
    
    printf("\n");
    printf("\t\tISA 2: ");
    for (int j = 0; j < 5; j++) {
        printf("%d(%c)\t\t", isa2[index][j], calculateGrade(isa2[index][j]));
    }
    
    printf("\n");
    printf("\t\tESA: ");
    for (int j = 0; j < 5; j++) {
        printf("%d(%c)\t\t", ESA[index][j], calculateGrade(ESA[index][j]));
    }

    double finalMarks = 0.25 * calculateAverage(isa1[index]) + 0.25 * calculateAverage(isa2[index]) + 0.5 * calculateAverage(ESA[index]);
    printf("%c\n", calculateGrade(finalMarks));
}