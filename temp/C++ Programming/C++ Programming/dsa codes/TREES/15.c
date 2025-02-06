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

struct Node* constructBSTUtil(int preorder[], int* preIndex, int key, int min, int max, int size) {
    if (*preIndex >= size) return NULL;

    struct Node* root = NULL;

    if (key > min && key < max) {
        root = newNode(key);
        *preIndex += 1;

        if (*preIndex < size) {
            root->left = constructBSTUtil(preorder, preIndex, preorder[*preIndex], min, key, size);
            root->right = constructBSTUtil(preorder, preIndex, preorder[*preIndex], key, max, size);
        }
    }
    return root;
}

struct Node* constructBST(int preorder[], int size) {
    int preIndex = 0;
    return constructBSTUtil(preorder, &preIndex, preorder[0], INT_MIN, INT_MAX, size);
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
    int preorder[n];

    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    struct Node* root = constructBST(preorder, n);
    printf("InOrder Traversal of the constructed BST: ");
    printInOrder(root);
    printf("\n");
    return 0;
}
