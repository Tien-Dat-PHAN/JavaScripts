
#include<stdio.h>
#include "../include/module1.h"

int main(void){
    int choice;
    struct teacher t1;
    printf("Welcome!\n");
    printf("1. Set Name\n2. Set Group\n3.Check Time\4.Display\5.Quit\n");
    printf("Enter your choice: "); scanf("%d", &choice);
    switch (choice)
    {
    case 1 /* set the name */:
        setname(&t1);
        break;
    case 2 /* set the group */:
        setgroup(&t1);
        break;
    case 3:
        printf("The size of folder is %d\n", getsize(&t1));

    case 4 /* Display */:
        printf("Name: %s\n", t1.name);
        printf("Group: %s\n", t1.group);
        time(&t1.tval);
        printf("Last modification %s\n", ctime(&t1.tval));
        setname(&t1);
        break;
    case 5:
        // Quite game
    default:
        printf("Invalid choice!\n");
        break;
    }while(choice!=5);

    return 0;
}