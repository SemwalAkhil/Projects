// 19. CREATE COMPLETE BINARY TREE FROM THE GIVEN INPUT BY THE USER (DYNAMICALLY)
#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a complete binary tree based on user input
struct TreeNode *createCompleteBinaryTree(int *values, int index, int n)
{
    // Base case: if the index is out of bounds
    if (index >= n)
    {
        return NULL;
    }

    // Create the root node
    struct TreeNode *root = createNode(values[index]);

    // Recursively create left and right subtrees
    root->left = createCompleteBinaryTree(values, 2 * index + 1, n);
    root->right = createCompleteBinaryTree(values, 2 * index + 2, n);

    return root;
}

// Function to perform inorder traversal of the tree
void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the allocated memory for the tree
void freeTree(struct TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes for the complete binary tree: ");
    scanf("%d", &n);

    int values[n];
    printf("Enter the values for the nodes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }

    // Create the complete binary tree
    struct TreeNode *root = createCompleteBinaryTree(values, 0, n);

    // Display the inorder traversal of the constructed tree
    printf("Inorder traversal of the constructed complete binary tree: ");
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;
}
