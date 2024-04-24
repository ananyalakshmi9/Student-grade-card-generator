#ifndef STUDENT_H
#define STUDENT_H

#define NUM_STUDENTS 50
#define NUM_SUBJECTS 5

struct Student {
    char name[50];
    int rollNumber;
    int isa1[NUM_SUBJECTS];
    int isa2[NUM_SUBJECTS];
    int ESA[NUM_SUBJECTS];
};

void addStudent(struct Student students[], int *numStudents);
void updateStudent(struct Student students[], int numStudents);
void deleteStudent(struct Student students[], int *numStudents);
void viewFinalGradeCardOfStudent(struct Student students[], int numStudents);
void viewGradeCardForSingleStudent(struct Student students[], int numStudents);
void viewFinalGradesOfAllStudents(struct Student students[], int numStudents);

#endif /* STUDENT_H */