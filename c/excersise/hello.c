#include<stdio.h>
#include<stdlib.h>
int main(void){
    printf("Hi Mom\n");

    int *p;
    int a = 9;
    printf("The first value of a is: %d\n", a);
    p = (int*)malloc(15);
    p = &a;
    *p = 10;
    printf("Aftert value of a is %d", a);

}