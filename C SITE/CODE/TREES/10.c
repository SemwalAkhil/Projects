// 10. CHECK WHETHER BINARY SEARCH TREE CONTAINS DEAD END
// A dead end occurs in a BST when a node has no left or right child, and its value is not the minimum or maximum possible value for that subtree. Specifically, if a node has both a left child and a right child, it can create a situation where you can't insert any further nodes.
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 100
// Definition of the BST Node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        printf("Value %d already exists in the BST.\n", value);
    }
    return root;
}

// Function to check for dead ends in the BST
int checkDeadEnd(struct Node *node, int min, int max)
{
    // Base case: if the node is NULL, return false (no dead end)
    if (node == NULL)
    {
        return 0;
    }

    // If the node has no children, check if it's a dead end
    if (node->left == NULL && node->right == NULL)
    {
        // A dead end exists if the current value is equal to min + 1 and max - 1
        if (node->data == min + 1 && node->data == max - 1)
        {
            return 1; // Dead end found
        }
    }

    // Check left and right subtrees with updated ranges
    return checkDeadEnd(node->left, min, node->data) || checkDeadEnd(node->right, node->data, max);
}

// Wrapper function to initiate dead end check
int hasDeadEnd(struct Node *root)
{
    // Initial call with range of values for a BST (assuming values are positive)
    return checkDeadEnd(root, 0, INT_MAX);
}

// Function to perform inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Menu-driven program to interact with the user
int main()
{
    struct Node *root = NULL; // Initialize the root of the BST
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Check for Dead End\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            if (hasDeadEnd(root))
            {
                printf("The BST contains a dead end.\n");
            }
            else
            {
                printf("The BST does not contain any dead end.\n");
            }
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
