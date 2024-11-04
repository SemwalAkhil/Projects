// 14. PRINT PREORDER TRAVERSAL TO POSTORDER TRAVERSAL OF BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>
#define INT_MIN 0
#define INT_MAX 100
// Structure for BST node
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

// Function to construct BST from preorder traversal
struct Node *constructBST(int preorder[], int *preIndex, int key,
                          int min, int max, int size)
{
    if (*preIndex >= size)
        return NULL;

    struct Node *root = NULL;

    // If current element can be placed at current position
    if (key > min && key < max)
    {
        root = newNode(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
        {
            // Construct left subtree
            root->left = constructBST(preorder, preIndex,
                                      preorder[*preIndex], min, key, size);
        }
        if (*preIndex < size)
        {
            // Construct right subtree
            root->right = constructBST(preorder, preIndex,
                                       preorder[*preIndex], key, max, size);
        }
    }

    return root;
}

// Function to print postorder traversal
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;

    // First recur on left subtree
    printPostorder(node->left);

    // Then recur on right subtree
    printPostorder(node->right);

    // Now print the data
    printf("%d ", node->data);
}

// Function to free memory
void freeTree(struct Node *node)
{
    if (node == NULL)
        return;

    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size!\n");
        return 1;
    }

    int *preorder = (int *)malloc(size * sizeof(int));
    if (preorder == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the preorder traversal elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &preorder[i]);
    }

    int preIndex = 0;
    struct Node *root = constructBST(preorder, &preIndex, preorder[0], INT_MIN, INT_MAX, size);

    printf("\nPostorder traversal of the constructed tree: ");
    printPostorder(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);
    free(preorder);

    return 0;
}