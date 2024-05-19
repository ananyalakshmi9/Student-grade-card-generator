
#ifndef STUDENT_H
#define STUDENT_H

#define NUM_SUBJECTS 5

struct Student {
    int rollNumber;
    char name[100];
    int isa1[NUM_SUBJECTS];
    int isa2[NUM_SUBJECTS];
    int ESA[NUM_SUBJECTS];
};

int readStudentDataFromCSV(const char *filename, struct Student students[]);
void writeStudentDataToCSV(const char *filename, struct Student students[], int *numStudents);
char calculateGrade(int marks);
double calculateAverage(int marks[]);
void addStudent(struct Student students[], int *numStudents);
void updateStudent(struct Student students[], int *numStudents);
void deleteStudent(struct Student students[], int *numStudents);
void viewFinalGradeCardOfStudent(struct Student students[], int numStudents);
void viewGradeCardForSingleStudent(struct Student students[], int numStudents);
void viewFinalGradesOfAllStudents(struct Student students[], int numStudents);

#endif 

