#include <stdio.h>

#define MAX 50  // indicates maximum number of students

// Structure to store student data
struct Student {
    int id;
    char name[50];
    int age;
};

void addStudent(struct Student s[], int *count){
    if (*count >= MAX) {
        printf("Cannot add more students.\n Maximum limit reached.\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &s[*count].id);  // it is current student position (or) id number
    while(getchar() != '\n'); 

    printf("Enter Student Name: ");
    scanf("%[^\n]", s[*count].name);   // it is current student name
    // here %[^\n]  is used take whole string including spaces,except special character like new line
    
    printf("Enter Student Age: ");
    scanf("%d", &s[*count].age); // it is current student age
    while(getchar() != '\n');


    (*count)++;      // increment the student count after adding a new student
    printf("Student added successfully!\n");
}


void displayStudents(struct Student s[], int count);

void displayStudents(struct Student s[], int count){
    if (count == 0){
        printf("no students are registered yet.\n");
        return;
    }
    printf("\n----- Student Records -----\n");

    for(int i = 0; i< count; i++){     // it will go on and print data of the students
        printf("Student ID: %d\n", s[i].id);   
        printf("Student Name: %s\n", s[i].name);
        printf("Student Age: %d\n", s[i].age);
        printf("----------------------\n");
    }
}

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // clear input buffer
        printf(" you have choosen : %d\n",choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
         }

    } while (choice != 3);   // continues untill user enter 3(Exit)

    return 0;
}


