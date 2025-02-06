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

void storeInorder(struct Node* root, int inorder[], int* index) {
    if (root == NULL) return;
    storeInorder(root->left, inorder, index);
    inorder[(*index)++] = root->data;
    storeInorder(root->right, inorder, index);
}

int findKthLargest(struct Node* root, int k) {
    int inorder[100]; // Adjust size as needed
    int index = 0;
    storeInorder(root, inorder, &index);
    return inorder[index - k]; // Kth largest
}

int main() {
    struct Node* root = NULL;
    int n, value, k;

    printf("Enter the number of elements to insert in the BST: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        // Insert into the BST (you may want to implement the insert function)
        // Here, we assume root is built properly before calling findKthLargest
    }

    printf("Enter K to find Kth largest element: ");
    scanf("%d", &k);
    int kthLargest = findKthLargest(root, k);
    printf("The %dth largest element in the BST is: %d\n", k, kthLargest);

    return 0;
}
