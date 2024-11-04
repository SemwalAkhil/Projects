// 1. CONSTRUCT BINARY TREE FROM PREORDER AND INORDER TRAVERSAL
#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
// Define a binary tree node
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

// Function to search for a value in an array
int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to construct binary tree from preorder and inorder traversals
struct Node *buildTree(int inorder[], int preorder[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
        return NULL;

    // The current node in preorder traversal is the root of the subtree
    int current = preorder[*preIndex];
    (*preIndex)++;
    struct Node *node = newNode(current);

    // If the node has no children, return it
    if (inStart == inEnd)
        return node;

    // Find the index of this node in inorder traversal
    int inIndex = search(inorder, inStart, inEnd, current);

    // Recursively build the left and right subtrees
    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

// Function to print the inorder traversal of the tree for verification
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int inorder[maxSize];
    int preorder[maxSize];
    int size;
    printf("Enter the number of nodes : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter inorder element : ");
        scanf("%d", &inorder);
    }
    for (int i = 0; i < size; i++)
    {
        printf("Enter preorder element : ");
        scanf("%d", &preorder);
    }
    int preIndex = 0;

    struct Node *root = buildTree(inorder, preorder, 0, size - 1, &preIndex);

    printf("Inorder traversal of the constructed tree:\n");
    printInorder(root);

    return 0;
}
