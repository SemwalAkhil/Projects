#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* createStrictlyBinaryTree() {
    int data;
    printf("Enter node value (-1 to stop): ");
    scanf("%d", &data);
    
    if (data == -1) return NULL;

    struct Node* node = newNode(data);
    printf("Enter left child of %d:\n", data);
    node->left = createStrictlyBinaryTree();
    printf("Enter right child of %d:\n", data);
    node->right = createStrictlyBinaryTree();
    
    return node;
}

void printInOrder(struct Node* node) {
    if (node == NULL) return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    struct Node* root = createStrictlyBinaryTree();
    printf("InOrder Traversal of the Strictly Binary Tree: ");
    printInOrder(root);
    printf("\n");
    return 0;
}
