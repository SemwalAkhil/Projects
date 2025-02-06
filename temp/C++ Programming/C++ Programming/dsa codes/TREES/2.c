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

void printLevelOrder(struct Node* root) {
    if (!root) return;

    struct Node* queue[100]; // Simple queue implementation
    int front = 0, rear = -1;

    queue[++rear] = root;

    while (front <= rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left) queue[++rear] = current->left;
        if (current->right) queue[++rear] = current->right;
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node* nodes[n];
    
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        nodes[i] = newNode(data);
    }

    for (int i = 0; i < n; i++) {
        int leftIndex, rightIndex;
        printf("Enter left and right children indices for node %d (-1 if no child): ", i + 1);
        scanf("%d %d", &leftIndex, &rightIndex);
        if (leftIndex != -1) nodes[i]->left = nodes[leftIndex - 1];
        if (rightIndex != -1) nodes[i]->right = nodes[rightIndex - 1];
    }

    printf("Level Order Traversal: ");
    printLevelOrder(nodes[0]);
    printf("\n");
    return 0;
}
