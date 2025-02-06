#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert function for BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Find the minimum node in the BST (used for finding successor)
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Find the maximum node in the BST (used for finding predecessor)
struct Node* findMax(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

// Find the Inorder Predecessor and Successor
void findPredecessorSuccessor(struct Node* root, struct Node** predecessor, struct Node** successor, int data) {
    if (root == NULL) return;

    if (root->data == data) {
        if (root->left != NULL)
            *predecessor = findMax(root->left);
        if (root->right != NULL)
            *successor = findMin(root->right);
    } else if (data < root->data) {
        *successor = root;
        findPredecessorSuccessor(root->left, predecessor, successor, data);
    } else {
        *predecessor = root;
        findPredecessorSuccessor(root->right, predecessor, successor, data);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, target;
    struct Node *predecessor = NULL, *successor = NULL;

    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Enter the value to find its Inorder Predecessor and Successor: ");
    scanf("%d", &target);

    findPredecessorSuccessor(root, &predecessor, &successor, target);

    if (predecessor != NULL)
        printf("Inorder Predecessor of %d is %d\n", target, predecessor->data);
    else
        printf("Inorder Predecessor of %d does not exist\n", target);

    if (successor != NULL)
        printf("Inorder Successor of %d is %d\n", target, successor->data);
    else
        printf("Inorder Successor of %d does not exist\n", target);

    return 0;
}
