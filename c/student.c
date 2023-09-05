/*
This project is a basic gradebook management system. This program will allow you to create, update, and display student records.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    char name[50]; // ban than hnn cung la mot con tro 
    int roll_number;
    float grades[5]; // Assuming 5 courses

};

// Function to add a new student ro the gradebook

void addStudent(struct Student student[], int *numStudents){

    if (*numStudents>=100){
        printf("Gradebook is full.");
        return;
    }

    struct Student newStudent;
    printf("Enter student's name: ");
    scanf("%s", newStudent.name);

    printf("Enter student roll number: ");
    scanf("%d", &newStudent.roll_number);

    for (int i = 0; i< 5; i++){
        printf("Enter  grade for course %d: ", i);
        scanf("%f", &newStudent.grades[i]);
    }

    student[*numStudents] = newStudent;
    *numStudents +=1;

    printf("Student added successfully!\n");
}

// function to display all students and their grades

void displayStudents(struct Student student[], int numStudent){
    if (numStudent == 0){
        printf("No student in the gradebook\n");

        return;
    }

    printf("Student\tRoll Number\tCourse 1\tCourse 2\tCourse 3\tCourse 4\tCourse 5\n");

    for(int i = 0; i < numStudent; i++){
        printf("%s\t%d\t", student[i].name, student[i].roll_number);
        for (int j =0; j< 5; j++){
            printf("%.2f\t", student[i].grades[j]);
            
        }
        printf("\n");
    }
}

int main(){

    struct Student students[100];
    int numStudents = 0;
    int choice;

    do{
        printf("\nStudent Gradebook Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(students, &numStudents);
            break;
        case 2:
            displayStudents(students, numStudents);
            break;
        case 3: 
            printf("Exting the program. Bye!\n");
            break;

        default:
            printf("Invalide choice");
            break;
        }
    }while(choice!=3);

    return 0; 
    
}