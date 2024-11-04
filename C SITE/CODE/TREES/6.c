// 6. FIND THE MAXIMUM DEPTH OF BINARY TREE
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node in the binary tree
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the maximum depth of the binary tree
int maxDepth(struct Node *node)
{
    // Base case: if the node is NULL, return depth as 0
    if (node == NULL)
    {
        return 0;
    }

    // Compute the depth of each subtree
    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);

    // Return the greater of the two depths plus one for the current node
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Menu-driven program to interact with the user
int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Find Maximum Depth of Binary Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted %d into the binary tree.\n", value);
            break;
        case 2:
            printf("Maximum Depth of the Binary Tree: %d\n", maxDepth(root));
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
