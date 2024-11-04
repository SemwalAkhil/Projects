// 15. CONSTRUCT BINARY SEARCH TREE FROM GIVEN PREORDER TRAVERSAL THROUGH ARRAYS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Function to construct BST from preorder traversal
struct TreeNode *constructBSTFromPreorder(int *preorder, int *preorderIndex, int n, int min, int max)
{
    // Base case: if we've processed all elements or if the current value is out of the bounds
    if (*preorderIndex >= n || preorder[*preorderIndex] < min || preorder[*preorderIndex] > max)
    {
        return NULL;
    }

    // Create the root node with the current value
    int key = preorder[*preorderIndex];
    (*preorderIndex)++;
    struct TreeNode *root = createNode(key);

    // Construct left and right subtrees with updated bounds
    root->left = constructBSTFromPreorder(preorder, preorderIndex, n, min, key);
    root->right = constructBSTFromPreorder(preorder, preorderIndex, n, key, max);

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
    printf("Enter the number of nodes in the preorder traversal: ");
    scanf("%d", &n);

    int preorder[n];
    printf("Enter the preorder traversal elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    int preorderIndex = 0; // Initialize index for preorder array
    struct TreeNode *root = constructBSTFromPreorder(preorder, &preorderIndex, n, INT_MIN, INT_MAX);

    // Display the inorder traversal of the constructed tree
    printf("Inorder traversal of the constructed BST: ");
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;
}
