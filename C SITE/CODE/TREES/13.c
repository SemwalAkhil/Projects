// 13. FIND KTH SMALLEST ELEMENT IN A BINARY SEARCH TREE THROUGH ARRAY
#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Search Tree Node structure
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

// Function to insert a value into the Binary Search Tree
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

// Function to perform in-order traversal and store values in an array
void inorder(struct Node *root, int *array, int *index)
{
    if (root != NULL)
    {
        inorder(root->left, array, index);
        array[(*index)++] = root->data; // Store the node's data
        inorder(root->right, array, index);
    }
}

// Function to find the Kth smallest element in the BST
int findKthSmallest(struct Node *root, int k)
{
    int array[100]; // Assuming a maximum of 100 nodes
    int index = 0;

    // Perform in-order traversal to fill the array
    inorder(root, array, &index);

    // Kth smallest is at index [k - 1]
    if (k <= 0 || k > index)
    {
        printf("Invalid value of k: %d. There are only %d elements in the BST.\n", k, index);
        return -1; // Indicating an invalid request
    }
    return array[k - 1]; // Return the Kth smallest element
}

// Function to free the Binary Search Tree
void freeBST(struct Node *root)
{
    if (root != NULL)
    {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

// Main function
int main()
{
    struct Node *root = NULL; // Initialize the root of the BST
    int choice, value, k;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Find Kth Smallest Element\n");
        printf("3. Exit\n");
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
            printf("Enter value of k: ");
            scanf("%d", &k);
            int kthSmallest = findKthSmallest(root, k);
            if (kthSmallest != -1)
            {
                printf("The %dth smallest element is: %d\n", k, kthSmallest);
            }
            break;
        case 3:
            printf("Exiting...\n");
            freeBST(root); // Free allocated memory before exit
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
