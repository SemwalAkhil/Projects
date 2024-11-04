// 8. CREATE BINARY SEARCH TREE DYNAMICALLY (INSERT, DELETE, SEARCH, PREORDER, INORDER, POSTORDER, MINIMUM ELEMENT)
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
        return createNode(value); // Create a new node if the position is empty
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value); // Insert in the left subtree
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value); // Insert in the right subtree
    }
    else
    {
        printf("Value %d already exists in the BST.\n", value); // Prevent duplicates
    }
    return root;
}

// Function to search for a value in the BST
struct Node *search(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root; // Return the node if found or NULL if not found
    }
    if (value < root->data)
    {
        return search(root->left, value); // Search in the left subtree
    }
    return search(root->right, value); // Search in the right subtree
}

// Function to find the minimum element in the BST
struct Node *minimum(struct Node *root)
{
    if (root == NULL)
    {
        printf("BST is empty.\n");
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left; // Traverse to the leftmost node
    }
    return root; // Return the minimum node
}

// Function to delete a value from the BST
struct Node *delete(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("Value %d not found in BST.\n", value);
        return root; // Return if the tree is empty
    }
    if (value < root->data)
    {
        root->left = delete (root->left, value); // Delete in the left subtree
    }
    else if (value > root->data)
    {
        root->right = delete (root->right, value); // Delete in the right subtree
    }
    else
    {
        // Node with the value found
        if (root->left == NULL)
        {
            struct Node *temp = root->right; // Node has only right child
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left; // Node has only left child
            free(root);
            return temp;
        }
        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node *temp = minimum(root->right);
        root->data = temp->data;                        // Copy the inorder successor's value to this node
        root->right = delete (root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to perform inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);       // Visit left child
        printf("%d ", root->data); // Visit node
        inorder(root->right);      // Visit right child
    }
}

// Function to perform preorder traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); // Visit node
        preorder(root->left);      // Visit left child
        preorder(root->right);     // Visit right child
    }
}

// Function to perform postorder traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);     // Visit left child
        postorder(root->right);    // Visit right child
        printf("%d ", root->data); // Visit node
    }
}

// Menu-driven program to interact with the user
int main()
{
    struct Node *root = NULL; // Initialize the root of the BST
    int choice, value;
    struct Node *searchResult; // Declare searchResult here
    struct Node *minNode;      // Declare minNode here

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Find Minimum Element\n");
        printf("8. Exit\n");
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
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = delete (root, value);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            searchResult = search(root, value);
            if (searchResult != NULL)
            {
                printf("Value %d found in BST.\n", searchResult->data);
            }
            else
            {
                printf("Value %d not found in BST.\n", value);
            }
            break;
        case 4:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 6:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 7:
            minNode = minimum(root);
            if (minNode != NULL)
            {
                printf("Minimum element: %d\n", minNode->data);
            }
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
