#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 15
// return the index of the parent node
int parent(int i){
    return (i-1)/2;
}
int leff_child(int i){
    return 2*i +1;
}
int right_child(int i){
    return 2*i +2;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// insert the item

void insert(int a[], int data, int *n){
    if(*n > MAX_SIZE){
        printf("%s\n", "The heap is full, can not insert");
        return;
    }
    a[*n] = data;
    *n = *n+1;
    

    //move up until the heap property satisfies
    int i = *n-1;
    while(i!=0 && a[parent(i)<a[i]]){
        swap(&a[parent(i)], &a[i]);
        i = parent(i);
    }

}
void print_heap(int a[], int n){
    for(int i =0; i<=n; i++){
        printf("%d   ", a[i]);
    }
    printf("\n");
}

//moves the item at position of array a
//into its appropriate position 
void max_heapify(int a[], int i, int n){
    int left = leff_child(i);
    int right = right_child(i);
    int largest = i;
    //check the left node is larger than current node 
    if (left<=n && a[left]>a[largest]){
        largest = left;
    }
    //right node is larger than current node

    if (right<=n && a[right]>a[largest]){
        largest = right;
    }

    // swap the largest node with the current node
    //and repeat this process until the current node is larger than the 
    //right and the left node
    if (largest!=i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }

}

// convert an array to a heap
void build_max_heap(int a[], int n){
    int i;
    for (i = n/2; i>=0;i--){
        max_heapify(a,i,n);
    }

}

//extract max
int get_max(int a[]){
    return a[0];
}
//delete the max-item and return

int extract_max(int a[], int *n){
    int max_item = get_max(a);
    //replace the first item with the last item
    a[0] = a[*n-1];
    *n = *n-1;

    max_heapify(a, 0, *n);
    return max_item;
}
void print_i_parent_childrens(int a[], int i){
    if (i==0){
        printf("The root: %d\n", a[0]);
        printf("left_child: %d right_child: %d", a[leff_child(i)], a[right_child(i)]);
    }
    printf("Parent of %d is %d\n", i, a[parent(i)]);
    printf("left_child: %d right_child: %d", a[leff_child(i)], a[right_child(i)]);
    printf("\n");
}
int main() {
    int n = 10;
    int a[MAX_SIZE];
    a[1] = 1000; a[2] = 12; a[3] = 9; a[4] = 78; a[5] = 33; a[6] = 21; a[7] = 35; a[8] = 29; a[9] = 5; a[10] = 66;
    build_max_heap(a, n);
    insert(a, 55, &n);
    insert(a, 56, &n);
    insert(a, 57, &n);
    insert(a, 58, &n);
    insert(a, 100, &n);
    //insert(a, 2, &n);
    print_heap(a, n);
    //print_i_parent_childrens(a, 1);
    printf("get max = %d", get_max(a));
    return 0;
}

// you have to be very familiar with this kind of code if you want to get a good job in the future
// think about iut
// practice make perfect 
// more time more effort 
// understand the mechanism behind 