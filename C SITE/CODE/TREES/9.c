// 9. FIND INORDER PREDECESSOR AND INORDER SUCCESSOR OF BINARY SEARCH TREE (DYNAMICALLY REPRESENTED)
#include <stdio.h>
#include <stdlib.h>

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

// Function to find the inorder predecessor
struct Node *inorderPredecessor(struct Node *root, struct Node *node)
{
    // If the node has a left subtree, return the maximum value in that subtree
    if (node->left != NULL)
    {
        struct Node *current = node->left;
        while (current->right != NULL)
        {
            current = current->right;
        }
        return current;
    }

    // Otherwise, go up to find an ancestor
    struct Node *predecessor = NULL;
    struct Node *current = root;
    while (current != NULL)
    {
        if (node->data < current->data)
        {
            current = current->left;
        }
        else if (node->data > current->data)
        {
            predecessor = current; // Update the predecessor
            current = current->right;
        }
        else
        {
            break;
        }
    }
    return predecessor;
}

// Function to find the inorder successor
struct Node *inorderSuccessor(struct Node *root, struct Node *node)
{
    // If the node has a right subtree, return the minimum value in that subtree
    if (node->right != NULL)
    {
        struct Node *current = node->right;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    // Otherwise, go up to find an ancestor
    struct Node *successor = NULL;
    struct Node *current = root;
    while (current != NULL)
    {
        if (node->data < current->data)
        {
            successor = current; // Update the successor
            current = current->left;
        }
        else if (node->data > current->data)
        {
            current = current->right;
        }
        else
        {
            break;
        }
    }
    return successor;
}

// Function to search for a value in the BST
struct Node *search(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }
    if (value < root->data)
    {
        return search(root->left, value);
    }
    return search(root->right, value);
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
    struct Node *node;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Find Inorder Predecessor\n");
        printf("3. Find Inorder Successor\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
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
            printf("Enter value to find inorder predecessor: ");
            scanf("%d", &value);
            node = search(root, value);
            if (node != NULL)
            {
                struct Node *predecessor = inorderPredecessor(root, node);
                if (predecessor != NULL)
                {
                    printf("Inorder Predecessor of %d: %d\n", value, predecessor->data);
                }
                else
                {
                    printf("No Inorder Predecessor found for %d.\n", value);
                }
            }
            else
            {
                printf("Value %d not found in BST.\n", value);
            }
            break;
        case 3:
            printf("Enter value to find inorder successor: ");
            scanf("%d", &value);
            node = search(root, value);
            if (node != NULL)
            {
                struct Node *successor = inorderSuccessor(root, node);
                if (successor != NULL)
                {
                    printf("Inorder Successor of %d: %d\n", value, successor->data);
                }
                else
                {
                    printf("No Inorder Successor found for %d.\n", value);
                }
            }
            else
            {
                printf("Value %d not found in BST.\n", value);
            }
            break;
        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
