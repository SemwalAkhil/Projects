#include <stdio.h>
#include <stdlib.h>

// A BST node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

struct Node* new_node(int x) {
    struct Node* p = malloc(sizeof(struct Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Recursive function to insert a key into BST
Node* insert(Node* root, int x) {
    if (root == NULL)
        return new_node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

// Function to find k'th smallest element in BST
int count = 0;
Node* kthSmallest(Node* root, int k) {
    // base case
    if (root == NULL)
        return NULL;

    // search in left subtree
    Node* left = kthSmallest(root->left, k);

    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;

    // if current element is k'th smallest, return it
    count++;
    if (count == k)
        return root;

    // else search in right subtree
    return kthSmallest(root->right, k);
}

// Function to print k'th smallest element in BST
void printKthSmallest(Node* root, int k) {
    // maintain index to count number of nodes processed so far
    Node* res = kthSmallest(root, k);
    if (res == NULL)
        printf("There are less than k nodes in the BST\n");
    else
        printf("K-th Smallest Element is %d\n", res->data);
}

// main function
int main() {
    Node* root = NULL;
    int numElements, k;

    // Prompt the user for the number of elements
    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &numElements);

    // Read elements from user
    printf("Enter the elements:\n");
    for (int i = 0; i < numElements; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Prompt the user for k
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Print the k-th smallest element
    printKthSmallest(root, k);

    return 0;
}
