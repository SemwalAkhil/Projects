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

void leftViewUtil(struct Node* root, int level, int* maxLevel) {
    if (!root) return;
    if (*maxLevel < level) {
        printf("%d ", root->data);
        *maxLevel = level;
    }
    leftViewUtil(root->left, level + 1, maxLevel);
    leftViewUtil(root->right, level + 1, maxLevel);
}

void leftView(struct Node* root) {
    int maxLevel = 0;
    leftViewUtil(root, 1, &maxLevel);
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

    printf("Left View: ");
    leftView(nodes[0]);
    printf("\n");
    return 0;
}
