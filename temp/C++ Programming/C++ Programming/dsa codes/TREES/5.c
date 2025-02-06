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

// Function to search for a value in the inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build the binary tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;
    
    struct Node* node = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, node->data);
    node->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return node;
}

// Function to print the inorder traversal of the tree
void printInorder(struct Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];
    printf("Enter the inorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter the postorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);

    return 0;
}
