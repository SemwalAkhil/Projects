// 15. CONSTRUCT BINARY SEARCH TREE FROM GIVEN PREORDER TRAVERSAL THROUGH ARRAYS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a node structure for the BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Helper function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive function to construct BST from preorder traversal
struct Node *constructBST(int preorder[], int *index, int key, int min, int max, int n)
{
    // Base case: If the entire preorder array is traversed or key is out of range
    if (*index >= n || key < min || key > max)
    {
        return NULL;
    }

    // Allocate memory for the root node of the BST
    struct Node *root = newNode(key);
    *index = *index + 1;

    // If there are more elements in preorder, construct the left and right subtrees
    if (*index < n)
    {
        // Construct the left subtree for values less than the current key
        root->left = constructBST(preorder, index, preorder[*index], min, key - 1, n);

        // Construct the right subtree for values greater than the current key
        root->right = constructBST(preorder, index, preorder[*index], key + 1, max, n);
    }

    return root;
}

// Utility function to print the inorder traversal of the BST
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in preorder traversal: ");
    scanf("%d", &n);

    int preorder[n];
    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    int index = 0;
    struct Node *root = constructBST(preorder, &index, preorder[0], INT_MIN, INT_MAX, n);

    printf("Inorder traversal of the constructed BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
