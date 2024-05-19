#include <stdio.h>
#include "student.h"

#define MAX_STUDENTS 100

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    // Read student data from CSV file
    numStudents = readStudentDataFromCSV("studentdata.csv", students);
    if (numStudents == 0) {
        printf("No student records found or error reading file.\n");
    }

    int choice;
    do {
        printf("\n------------------ Student Management System ------------------\n");
        printf("1. Add a new student\n");
        printf("2. Update student information\n");
        printf("3. Delete a student\n");
        printf("4. View final grade card of a student\n");
        printf("5. View grade card of a single student\n");
        printf("6. View final grades of all students\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                updateStudent(students, &numStudents);
                break;
            case 3:
                deleteStudent(students, &numStudents);
                break;
            case 4:
                viewFinalGradeCardOfStudent(students, numStudents);
                break;
            case 5:
                viewGradeCardForSingleStudent(students, numStudents);
                break;
            case 6:
                viewFinalGradesOfAllStudents(students, numStudents);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }

    } while (choice != 7);

    return 0;
}
