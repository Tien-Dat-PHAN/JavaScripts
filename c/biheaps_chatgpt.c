#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary heap
struct BinaryHeap {
    int *array; // Pointer to array that holds the elements of the heap
    int capacity; // Maximum number of elements the heap can hold
    int size; // Current number of elements in the heap
};

// Function to create a new binary heap
struct BinaryHeap *createHeap(int capacity) {
    struct BinaryHeap *heap = (struct BinaryHeap *)malloc(sizeof(struct BinaryHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int *)malloc(capacity * sizeof(int));
    return heap;
}

// Function to swap two elements in the heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property
void heapify(struct BinaryHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;
    
    if (right < heap->size && heap->array[right] < heap->array[smallest])
        smallest = right;
    
    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Function to insert a new element into the heap
void insert(struct BinaryHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }
    int index = heap->size;
    heap->array[index] = value;
    heap->size++;

    while (index > 0 && heap->array[(index - 1) / 2] > heap->array[index]) {
        swap(&heap->array[(index - 1) / 2], &heap->array[index]);
        index = (index - 1) / 2;
    }
}

// Function to extract the minimum element from the heap
int extractMin(struct BinaryHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int min = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return min;
}

// Function to print the elements of the heap
void printHeap(struct BinaryHeap *heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    struct BinaryHeap *heap = createHeap(10);

    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);
    insert(heap, 10);

    printf("Min element: %d\n", extractMin(heap));
    printf("Min element: %d\n", extractMin(heap));

    printHeap(heap);

    free(heap->array);
    free(heap);

    return 0;
}
