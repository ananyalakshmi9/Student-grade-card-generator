/*#include <stdio.h>
#include <string.h>
#include "student.h"

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

double calculateAverage(int marks[]) {
    int sum = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        sum += marks[i];
    }
    return sum / (double)NUM_SUBJECTS;
}

void generateFinalGradeCard(struct Student students[], int numStudents) {
    printf("\n------------------ Final Grade Card ------------------\n");
    printf("Roll No\tName\tFinal Grade\n");
    for (int i = 0; i < numStudents; i++) {
        double finalMarks = 0.25 * calculateAverage(students[i].isa1) + 0.25 * calculateAverage(students[i].isa2) + 0.5 * calculateAverage(students[i].ESA);
        printf("%d\t%s\t%c\n", students[i].rollNumber, students[i].name, calculateGrade(finalMarks));
    }
}

void addStudent(struct Student students[], int *numStudents) {
    printf("Adding a new student...\n");
    printf("Enter name for the new student: ");
    fflush(stdin); // Clear input buffer
    fgets(students[*numStudents].name, sizeof(students[*numStudents].name), stdin);
    strtok(students[*numStudents].name, "\n"); // Remove trailing newline character
    
    printf("Enter roll number for the new student: ");
    scanf("%d", &students[*numStudents].rollNumber);
    printf("Subject 1->Engineering Physics\nSubject 2->Progamming with C\nSubject 3->Mathematics\nSubject 4->Elements of Electrical Engineering\nSubject 5->Mechanical Engineering Science\n")

    printf("Enter marks for ISA 1 for the new student (5 subjects): ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        scanf("%d", &students[*numStudents].isa1[j]);
    }

    printf("Enter marks for ISA 2 for the new student (5 subjects): ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        scanf("%d", &students[*numStudents].isa2[j]);
    }

    printf("Enter marks for ESA for the new student (5 subjects): ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        scanf("%d", &students[*numStudents].ESA[j]);
    }
    (*numStudents)++;
}

void updateStudent(struct Student students[], int numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to update: ");
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
    printf("Enter new name for the student: ");
    scanf("%s", &students[index].name);

    printf("Enter new roll number for the student: ");
    scanf("%d", &students[index].rollNumber);

    printf("Enter new marks for ISA 1 for the student (5 subjects): ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        scanf("%d", &students[index].isa1[j]);
    }

    printf("Enter new marks for ISA 2 for the student (5 subjects): ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        scanf("%d", &students[index].isa2[j]);
    }

    printf("Enter new marks for ESA for the student (5 subjects): ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        scanf("%d", &students[index].ESA[j]);
    }
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
    // Shift remaining elements to fill the gap
    for (int i = index; i < *numStudents - 1; i++) {
        students[i] = students[i + 1];
    }
    (*numStudents)--;
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
    printf("Roll No\tName\t\tSubject1\tSubject2\tSubject3\tSubject4\tSubject5\tFinal Grade\n");
    printf("%d\t%s\t", students[index].rollNumber, students[index].name);
    
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
    printf("\t\t\tESA: ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d(%c)\t\t", students[index].ESA[j], calculateGrade(students[index].ESA[j]));
    }

    double finalMarks = 0.25 * calculateAverage(students[index].isa1) + 0.25 * calculateAverage(students[index].isa2) + 0.5 * calculateAverage(students[index].ESA);
    printf("%c\n", calculateGrade(finalMarks));
}

void viewFinalGradesOfAllStudents(struct Student students[], int numStudents) {
    printf("\n------------------ Final Grades of All Students ------------------\n");
    printf("Roll No\tName\tFinal Grade\n");
    for (int i = 0; i < numStudents; i++) {
        double finalMarks = 0.25 * calculateAverage(students[i].isa1) + 0.25 * calculateAverage(students[i].isa2) + 0.5 * calculateAverage(students[i].ESA);
        printf("%d\t%s\t%c\n", students[i].rollNumber, students[i].name, calculateGrade(finalMarks));
    }
}*/
#include <stdio.h>
#include <string.h>
#include "student.h"

void inputStudentData(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &students[i].rollNumber);

        printf("Enter marks for ISA 1 for student %d (%d subjects):\n", i + 1, NUM_SUBJECTS);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%d", &students[i].isa1[j]);
        }

        printf("Enter marks for ISA 2 for student %d (%d subjects):\n", i + 1, NUM_SUBJECTS);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%d", &students[i].isa2[j]);
        }

        printf("Enter marks for ESA for student %d (%d subjects):\n", i + 1, NUM_SUBJECTS);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%d", &students[i].ESA[j]);
        }
    }
}

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
printf("Subject 1->Engineering Physics\nSubject 2->Progamming with C\nSubject 3->Mathematics\nSubject 4->Elements of Electrical Engineering\nSubject 5->Mechanical Engineering Science\n");


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
}

void updateStudent(struct Student students[], int numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to update: ");
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
    // Shift remaining elements to fill the gap
    for (int i = index; i < *numStudents - 1; i++) {
        students[i] = students[i + 1];
    }
    (*numStudents)--;
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
    printf("Roll No\tName\tSubject1\tSubject2\tSubject3\tSubject4\tSubject5\tFinal Grade\n");
    printf("%d\t%s\t", students[index].rollNumber, students[index].name);
    
    printf("ISA 1: ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d(%c)\t\t", students[index].isa1[j], calculateGrade(students[index].isa1[j]));
    }
    
    printf("\n");
    printf("\t\tISA 2: ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d(%c)\t\t", students[index].isa2[j], calculateGrade(students[index].isa2[j]));
    }
    
    printf("\n");
    printf("\t\tESA: ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d(%c)\t\t", students[index].ESA[j], calculateGrade(students[index].ESA[j]));
    }

    double finalMarks = 0.25 * calculateAverage(students[index].isa1) + 0.25 * calculateAverage(students[index].isa2) + 0.5 * calculateAverage(students[index].ESA);
    printf("%c\n", calculateGrade(finalMarks));
}

void viewFinalGradesOfAllStudents(struct Student students[], int numStudents) {
    printf("\n------------------ Final Grades of All Students ------------------\n");
    printf("Roll No\tName\tFinal Grade\n");
    for (int i = 0; i < numStudents; i++) {
        double finalMarks = 0.25 * calculateAverage(students[i].isa1) + 0.25 * calculateAverage(students[i].isa2) + 0.5 * calculateAverage(students[i].ESA);
        printf("%d\t%s\t%c\n", students[i].rollNumber, students[i].name, calculateGrade(finalMarks));
    }
}