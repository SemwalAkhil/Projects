// 5. CONSTRUCT BINARY TREE FROM POSTORDER AND INORDER TRAVERSAL
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

// Function to find the index of a value in the inorder array
int search(int *inorder, int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
        {
            return i;
        }
    }
    return -1; // Should not happen
}

// Function to construct the binary tree from postorder and inorder traversals
struct Node *buildTree(int *inorder, int *postorder, int inorderStart, int inorderEnd, int *postIndex)
{
    // Base case
    if (inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Get the current root value from the postorder array
    int rootValue = postorder[*postIndex];
    struct Node *root = newNode(rootValue);
    (*postIndex)--; // Move to the next root in postorder

    // If this node has no children then return
    if (inorderStart == inorderEnd)
    {
        return root;
    }

    // Find the index of this root in inorder array
    int inorderIndex = search(inorder, inorderStart, inorderEnd, rootValue);

    // Recursively build the right and left subtrees
    root->right = buildTree(inorder, postorder, inorderIndex + 1, inorderEnd, postIndex);
    root->left = buildTree(inorder, postorder, inorderStart, inorderIndex - 1, postIndex);

    return root;
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Menu-driven program to interact with the user
int main()
{
    int n, *inorder, *postorder;

    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    inorder = (int *)malloc(n * sizeof(int));
    postorder = (int *)malloc(n * sizeof(int));

    printf("Enter the inorder traversal:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
    }

    printf("Enter the postorder traversal:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &postorder[i]);
    }

    int postIndex = n - 1; // Last index of postorder array
    struct Node *root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder traversal of the constructed tree:\n");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory
    free(inorder);
    free(postorder);

    return 0;
}
