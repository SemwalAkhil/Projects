// TODO
// 16. CONSTRUCT BINARY SEARCH TREE FROM GIVEN POSTORDER TRAVERSAL THROUGH ARRAYS
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

// Function to construct BST from postorder traversal
struct TreeNode *constructBSTUtil(int postorder[], int *index, int minValue, int maxValue, int n)
{
    // Base case
    if (*index < 0)
    {
        return NULL;
    }

    int current = postorder[*index];

    // If the current value is out of the allowed range
    if (current < minValue || current > maxValue)
    {
        return NULL;
    }

    // Create the node and move to the next index
    struct TreeNode *root = createNode(current);
    (*index)--;

    // Construct right and left subtrees (right first because of postorder)
    root->right = constructBSTUtil(postorder, index, current, maxValue, n);
    root->left = constructBSTUtil(postorder, index, minValue, current, n);

    return root;
}

// Function to construct BST from postorder traversal
struct TreeNode *constructBST(int postorder[], int n)
{
    int index = n - 1; // Start from the last element
    return constructBSTUtil(postorder, &index, INT_MIN, INT_MAX, n);
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct TreeNode *root)
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
    printf("Enter the number of nodes in the postorder traversal: ");
    scanf("%d", &n);

    int postorder[n];
    printf("Enter the postorder traversal elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &postorder[i]);
    }

    struct TreeNode *root = constructBST(postorder, n);

    printf("Inorder traversal of the constructed BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
