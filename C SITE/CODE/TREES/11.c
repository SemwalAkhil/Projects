// 11. CREATE BINARY TREE TO BINARY SEARCH TREE THROUGH ARRAY.
#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Tree Node structure
struct BTNode
{
    int data;
    struct BTNode *left;
    struct BTNode *right;
};

// Definition of the Binary Search Tree Node structure
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new Binary Tree Node
struct BTNode *createBTNode(int value)
{
    struct BTNode *newNode = (struct BTNode *)malloc(sizeof(struct BTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new Binary Search Tree Node
struct BSTNode *createBSTNode(int value)
{
    struct BSTNode *newNode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the Binary Search Tree
struct BSTNode *insertBST(struct BSTNode *root, int value)
{
    if (root == NULL)
    {
        return createBSTNode(value);
    }
    if (value < root->data)
    {
        root->left = insertBST(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertBST(root->right, value);
    }
    return root;
}

// Function to perform in-order traversal of the Binary Search Tree
void inorderBST(struct BSTNode *root)
{
    if (root != NULL)
    {
        inorderBST(root->left);
        printf("%d ", root->data);
        inorderBST(root->right);
    }
}

// Function to convert a Binary Tree to a Binary Search Tree
struct BSTNode *convertBTtoBST(struct BTNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    struct BSTNode *bstRoot = NULL;

    // In-order traversal of Binary Tree and insert into BST
    // This can also be done using a dynamic array if you want to collect all values first
    struct BTNode *queue[100]; // Assuming maximum 100 nodes
    int front = 0, rear = 0;

    // Perform level order traversal (BFS) to fill the queue
    queue[rear++] = root;

    while (front < rear)
    {
        struct BTNode *currentNode = queue[front++];
        bstRoot = insertBST(bstRoot, currentNode->data); // Insert into BST

        // Enqueue left child
        if (currentNode->left != NULL)
        {
            queue[rear++] = currentNode->left;
        }
        // Enqueue right child
        if (currentNode->right != NULL)
        {
            queue[rear++] = currentNode->right;
        }
    }

    return bstRoot;
}

// Function to free the Binary Tree
void freeBT(struct BTNode *root)
{
    if (root != NULL)
    {
        freeBT(root->left);
        freeBT(root->right);
        free(root);
    }
}

// Function to free the Binary Search Tree
void freeBST(struct BSTNode *root)
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
    // Constructing a sample Binary Tree
    struct BTNode *root = createBTNode(10);
    root->left = createBTNode(5);
    root->right = createBTNode(15);
    root->left->left = createBTNode(2);
    root->left->right = createBTNode(7);
    root->right->right = createBTNode(20);

    printf("Binary Tree created. Converting to Binary Search Tree...\n");

    // Convert Binary Tree to Binary Search Tree
    struct BSTNode *bstRoot = convertBTtoBST(root);

    printf("In-order Traversal of the Binary Search Tree:\n");
    inorderBST(bstRoot);
    printf("\n");

    // Free allocated memory
    freeBT(root);
    freeBST(bstRoot);

    return 0;
}
