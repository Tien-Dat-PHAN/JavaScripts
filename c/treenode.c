#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// function to create a tree node 
struct TreeNode *createNode(int value){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert a newnode into the binary tree

struct TreeNode *insert(struct TreeNode *root, int value){
    if (root == NULL){
        return createNode(value);
    }

    if (value < root->data){
        root->left = insert(root->left, value);

    }
    else if (value > root->data){
        root->right = insert(root->right, value);
    }

    return root;
}

void inorderTraversal(struct TreeNode *root){
    if (root!= NULL){
        inorderTraversal(root->left);
        printf("%d->", root->data);
        inorderTraversal(root->right);
    }
}

void display(struct TreeNode *root){
    if (root != NULL){
        struct TreeNode *current = root;
        printf("%d\n", current->data);
        //printf("%d\t%d", current->left->data, current->right->data);
        
        display(current->left);
        display(current->right);

        
    }
}

int main(){

    struct TreeNode *root = NULL;

    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 9);
    printf("In-order Traversal\n");
    display(root);
    printf("\n");
}

