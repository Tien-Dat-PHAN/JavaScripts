#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void insert(struct LinkedList* list, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete(struct LinkedList* list, int data) {
    if (list->head == NULL) {
        return;
    }

    if (list->head->data == data) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    struct Node* current = list->head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

int search(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList linked_list;
    linked_list.head = NULL;

    insert(&linked_list, 5);
    insert(&linked_list, 10);
    insert(&linked_list, 15);
    display(&linked_list); // Output: 5 -> 10 -> 15 -> NULL
    
    delete(&linked_list, 10);
    display(&linked_list); // Output: 5 -> 15 -> NULL
    
    printf("%d\n", search(&linked_list, 5)); // Output: 1 (True)
    printf("%d\n", search(&linked_list, 10)); // Output: 0 (False)

    return 0;
}
