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

struct Node* createAlmostCompleteBinaryTree(int index, int totalNodes) {
    if (index >= totalNodes) return NULL;

    struct Node* node = newNode(index + 1);
    node->left = createAlmostCompleteBinaryTree(2 * index + 1, totalNodes);
    node->right = createAlmostCompleteBinaryTree(2 * index + 2, totalNodes);
    
    return node;
}

void printInOrder(struct Node* node) {
    if (node == NULL) return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    int totalNodes;
    printf("Enter the total number of nodes: ");
    scanf("%d", &totalNodes);
    
    struct Node* root = createAlmostCompleteBinaryTree(0, totalNodes);
    printf("InOrder Traversal of the Almost Complete Binary Tree: ");
    printInOrder(root);
    printf("\n");
    return 0;
}
