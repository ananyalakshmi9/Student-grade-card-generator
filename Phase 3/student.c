#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

int readStudentDataFromCSV(const char *filename, struct Student students[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    int numStudents = 0;
    char line[256]; // Assuming maximum line length

    // Skip the first header lines
    fgets(line, sizeof(line), file); // Skip Roll Number, Student name, ISA1, ..., ESA
    while (fgets(line, sizeof(line), file)) {
        char *token;
        token = strtok(line, ",");
        
        if (token == NULL) {
            continue; // Skip empty lines
        }

        students[numStudents].rollNumber = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            continue; // Skip improperly formatted lines
        }
        strcpy(students[numStudents].name, token);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            token = strtok(NULL, ",");
            students[numStudents].isa1[j] = atoi(token);
        }

                for (int j = 0; j < NUM_SUBJECTS; j++) {
            token = strtok(NULL, ",");
            students[numStudents].isa2[j] = atoi(token);
        }

                for (int j = 0; j < NUM_SUBJECTS; j++) {
            token = strtok(NULL, ",");
            students[numStudents].ESA[j] = atoi(token);
        }

        numStudents++;
    }

    fclose(file);
    return numStudents;
}


void writeStudentDataToCSV(const char *filename, struct Student students[], int *numStudents) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write header row
    fprintf(file, "Roll Number,Name,");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        fprintf(file, "ISA1_Subject%d,", j + 1);
    }
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        fprintf(file, "ISA2_Subject%d,", j + 1);
    }
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        fprintf(file, "ESA_Subject%d,", j + 1);
    }
    fprintf(file, "\n");
    for (int i = 0; i < *numStudents; i++) {
        fprintf(file, "%d,%s,", students[i].rollNumber, students[i].name);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            fprintf(file, "%d,", students[i].isa1[j]);
        }
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            fprintf(file, "%d,", students[i].isa2[j]);
        }
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            fprintf(file, "%d,", students[i].ESA[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

char calculateGrade(int marks) {
    if (marks >= 90)
        return 'A';
    else if (marks >= 80)
        return 'B';
    else if (marks >= 70)
        return 'C';
    else if (marks >= 60)
        return 'D';
    else
        return 'F';
}

double calculateAverage(int marks[]) {
    int sum = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        sum += marks[i];
    }
    return sum / (double)NUM_SUBJECTS;
}

void addStudent(struct Student students[], int *numStudents) {
    printf("Adding a new student...\n");

    printf("Enter name for the new student: ");
    scanf("%s", students[*numStudents].name);

    printf("Enter roll number for the new student: ");
    scanf("%d", &students[*numStudents].rollNumber);

    printf("Enter marks for ISA 1 for the new student (%d subjects):\n", NUM_SUBJECTS);
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("Enter marks for Subject %d: ", j + 1);
        scanf("%d", &students[*numStudents].isa1[j]);
    }

    printf("Enter marks for ISA 2 for the new student (%d subjects):\n", NUM_SUBJECTS);
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("Enter marks for Subject %d: ", j + 1);
        scanf("%d", &students[*numStudents].isa2[j]);
    }

    printf("Enter marks for ESA for the new student (%d subjects):\n", NUM_SUBJECTS);
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("Enter marks for Subject %d: ", j + 1);
        scanf("%d", &students[*numStudents].ESA[j]);
    }
    (*numStudents)++;

    // Write new student data to CSV file
    writeStudentDataToCSV("studentdata.csv", students, &(*numStudents));
}

void updateStudent(struct Student students[], int *numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to update: ");
    scanf("%d", &rollNumber);
    int index = -1;
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
    printf("Enter new name for the student: ");
    scanf("%s", students[index].name);

    printf("Enter new roll number for the student: ");
    scanf("%d", &students[index].rollNumber);

    printf("Enter new marks for ISA 1 for the student (%d subjects):\n", NUM_SUBJECTS);
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("Enter marks for Subject %d: ", j + 1);
        scanf("%d", &students[index].isa1[j]);
    }

    printf("Enter new marks for ISA 2 for the student (%d subjects):\n", NUM_SUBJECTS);
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("Enter marks for Subject %d: ", j + 1);
        scanf("%d", &students[index].isa2[j]);
    }

    printf("Enter new marks for ESA for the student (%d subjects):\n", NUM_SUBJECTS);
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("Enter marks for Subject %d: ", j + 1);
        scanf("%d", &students[index].ESA[j]);
    }

    // Update student data in CSV file
    writeStudentDataToCSV("studentdata.csv", students, &(*numStudents));
}

void deleteStudent(struct Student students[], int *numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollNumber);
    int index = -1;
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
  
    for (int i = index; i < *numStudents - 1; i++) {
        students[i] = students[i + 1];
    }
    (*numStudents)--;

    // Debugging information
    printf("Debug: Writing updated data to CSV file.\n");
    FILE *file = fopen("studentdata.csv", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fclose(file);

    // Write updated student data to CSV file
    writeStudentDataToCSV("studentdata.csv", students, numStudents);
}
void viewFinalGradeCardOfStudent(struct Student students[], int numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to view final grade card: ");
    scanf("%d", &rollNumber);
    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
    double finalMarks = 0.25 * calculateAverage(students[index].isa1) + 0.25 * calculateAverage(students[index].isa2) + 0.5 * calculateAverage(students[index].ESA);
    printf("\n------------------ Final Grade Card for %s ------------------\n", students[index].name);
    printf("Roll No: %d\n", students[index].rollNumber);
    printf("Final Grade: %c\n", calculateGrade(finalMarks));
}

void viewGradeCardForSingleStudent(struct Student students[], int numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to view grade card: ");
    scanf("%d", &rollNumber);
    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
    printf("\n------------------ Grade Card for %s ------------------\n", students[index].name);
    printf("Roll No\tName\t\t\tSubject1\tSubject2\tSubject3\tSubject4\tSubject5\tFinal Grade\n");
    printf("%d\t%s\t\t", students[index].rollNumber, students[index].name);

    printf("ISA 1: ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d(%c)\t\t", students[index].isa1[j], calculateGrade(students[index].isa1[j]));
    }

    printf("\n");

    printf("\t\t\tISA 2: ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d(%c)\t\t", students[index].isa2[j], calculateGrade(students[index].isa2[j]));
    }

    printf("\n");

    printf("\t\t\tESA:   ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d(%c)\t\t", students[index].ESA[j], calculateGrade(students[index].ESA[j]));
    }

    double finalMarks = 0.25 * calculateAverage(students[index].isa1) + 0.25 * calculateAverage(students[index].isa2) + 0.5 * calculateAverage(students[index].ESA);
    printf("%c\n", calculateGrade(finalMarks));
}

void viewFinalGradesOfAllStudents(struct Student students[], int numStudents) {
    printf("\n------------------ Final Grades of All Students ------------------\n");
    printf("Roll No\tName\t\t\tFinal Grade\n");
    for (int i = 0; i < numStudents; i++) {
        double finalMarks = 0.25 * calculateAverage(students[i].isa1) + 0.25 * calculateAverage(students[i].isa2) + 0.5 * calculateAverage(students[i].ESA);
        printf("%d\t%s\t\t\t%c\n", students[i].rollNumber, students[i].name, calculateGrade(finalMarks));
    }
}


