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


int main(){

    struct TreeNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    printf("In-order Traversal\n");
    inorderTraversal(root);
    printf("\n");
}