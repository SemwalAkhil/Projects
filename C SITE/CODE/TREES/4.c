// 4. DISPLAY THE RIGHT VIEW OF BINARY TREE
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

// Function to print the right view of the binary tree
void rightViewUtil(struct Node *root, int level, int *maxLevel)
{
    // Base case
    if (root == NULL)
        return;

    // If this is the first node of the current level
    if (*maxLevel < level)
    {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    // Recur for right and left subtrees (right first)
    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}

// Wrapper function to initiate right view printing
void rightView(struct Node *root)
{
    int maxLevel = 0;
    rightViewUtil(root, 1, &maxLevel);
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
        printf("2. Print Right View of Binary Tree\n");
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
            printf("Right View of the Binary Tree:\n");
            rightView(root);
            printf("\n");
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
