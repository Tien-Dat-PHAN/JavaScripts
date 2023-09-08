#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "../include/module1.h"


void setname(struct teacher *t ){
    printf("Writre your first name: ");
    scanf("%d", &t->name);
}
void setgroup(struct teacher *t){
    printf("Write your GROUP name: ");
    scanf("%d", &t->group);

}
void getsize(struct teacher *t){
    
    printf("Size of file is %d\n", 10);

}
void timemod(struct teacher *t){
    time(t->tval);
    printf("The last modification is on %s", ctime(&t->tval));
}

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
        getsize(&t1);

    case 4 /* Display */:
        printf("Name: %d\n", t1.name);
        printf("Group: %d\n", t1.group);
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