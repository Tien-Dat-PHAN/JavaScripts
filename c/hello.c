#include <stdio.h>
#include <stdlib.h>


float sum(int a, int b){
    return a+b;
}

int reg(int x){
    if (x == 1){
        return 1;
    }
    return x*reg(x-1);
}
// function pointer

void increment(int* p){
    *p +=1;
}

struct Student {
    int id;
    int age;
    char name[50];
};

void display(struct Student std){
    printf("ID: %d\t", std.id);
    printf("age: %d\t", std.age);
    printf("name: %s\n", std.name);

}
// the modificaiton inside the function are reflected in the caller function 
void login(struct Student* std){
    char temp;
   printf("input id: ");
   scanf("%d", &std->id);
   printf("input age: ");
   scanf("%d", &std->age);
   printf("input name: ");
   scanf("%c", &temp);
   scanf("%[^\n]", std->name);
}

// a very effective example of return multiple values with pointers
void calculate(int a, int b, int *sum, int *product){
    *sum = a+b;
    *product = a*b;
}

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

//To conclude, you should use pointer any times and any where

int main() {
    // Part4
   struct Student arr[3];
   int list[] = {1,2,3,4,5};

   for (int i = 0; i < 3; i++){
    // login(&arr[i]);
    // display(arr[i]);
    printf("%d", list[i]);
   }

    int a = 3, b =4;
    swap(&a,&b);
    printf("a = %d, b = %d",a,b);
    return 0;
}
