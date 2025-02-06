#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct Node* constructBSTUtil(int postorder[], int* postIndex, int min, int max) {
    if (*postIndex < 0) return NULL;

    int key = postorder[*postIndex];

    if (key < min || key > max) return NULL;

    struct Node* root = newNode(key);
    *postIndex -= 1;

    root->right = constructBSTUtil(postorder, postIndex, key, max);
    root->left = constructBSTUtil(postorder, postIndex, min, key);
    return root;
}

struct Node* constructBST(int postorder[], int size) {
    int postIndex = size - 1;
    return constructBSTUtil(postorder, &postIndex, INT_MIN, INT_MAX);
}

void printInOrder(struct Node* node) {
    if (node == NULL) return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int postorder[n];

    printf("Enter the postorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    struct Node* root = constructBST(postorder, n);
    printf("InOrder Traversal of the constructed BST: ");
    printInOrder(root);
    printf("\n");
    return 0;
}
