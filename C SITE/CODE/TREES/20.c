// 20. COUNT THE NUMBER OF NODES IN BINARY SEARCH TREE CONSTRUCTED DYNAMICALLY
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

// Function to insert a new value into the BST
struct TreeNode *insert(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count the number of nodes in the BST
int countNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0; // Base case: empty tree
    }
    return 1 + countNodes(root->left) + countNodes(root->right); // Count this node plus left and right subtrees
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
    printf("Enter the number of nodes to insert into the BST: ");
    scanf("%d", &n);

    struct TreeNode *root = NULL;

    printf("Enter the values for the nodes: ");
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        root = insert(root, value); // Insert value into the BST
    }

    // Count the number of nodes in the BST
    int nodeCount = countNodes(root);
    printf("The number of nodes in the BST is: %d\n", nodeCount);

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;
}
