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

struct Node* createCompleteBinaryTree(int* arr, int index, int n) {
    if (index >= n) return NULL;

    struct Node* node = newNode(arr[index]);
    node->left = createCompleteBinaryTree(arr, 2 * index + 1, n);
    node->right = createCompleteBinaryTree(arr, 2 * index + 2, n);
    
    return node;
}

void printInOrder(struct Node* node) {
    if (node == NULL) return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    int n;
    printf("Enter the number of nodes in the Complete Binary Tree: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter the nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = createCompleteBinaryTree(arr, 0, n);
    printf("InOrder Traversal of the Complete Binary Tree: ");
    printInOrder(root);
    printf("\n");
    
    free(arr);
    return 0;
}
