#include <stdio.h>
#include "student.h"

int main() {
    int numStudents = 0;
    char names[100][50];
    int rollNumbers[100];
    int isa1[100][5], isa2[100][5], ESA[100][5];

    int choice;
    do {
        printf("\nOptions:\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. View Grade Card for a Single Student\n");
        printf("5. Generate Final Grade Card\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(names, rollNumbers, isa1, isa2, ESA, &numStudents);
                break;
            case 2:
                updateStudent(names, rollNumbers, isa1, isa2, ESA, numStudents);
                break;
            case 3:
                deleteStudent(names, rollNumbers, isa1, isa2, ESA, &numStudents);
                break;
            case 4:
                viewGradeCardForSingleStudent(names, rollNumbers, isa1, isa2, ESA, numStudents);
                break;
            case 5:
                generateFinalGradeCard(names, rollNumbers, isa1, isa2, ESA, numStudents);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

