#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Utility function to check for dead end
int isDeadEnd(struct Node* root, int min, int max) {
    if (root == NULL) return 0;
    if (min == max) return 1;
    return isDeadEnd(root->left, min, root->data - 1) || isDeadEnd(root->right, root->data + 1, max);
}

int main() {
    struct Node* root = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    if (isDeadEnd(root, 1, 1000))
        printf("The BST contains a dead end.\n");
    else
        printf("The BST does not contain any dead end.\n");

    return 0;
}
