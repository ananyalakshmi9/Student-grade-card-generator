
#ifndef STUDENT_H
#define STUDENT_H

void addStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int *numStudents);
void updateStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents);
void deleteStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int *numStudents);
void viewGradeCardForSingleStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents);
void generateFinalGradeCard(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents);
double calculateAverage(int marks[]);

#endif
