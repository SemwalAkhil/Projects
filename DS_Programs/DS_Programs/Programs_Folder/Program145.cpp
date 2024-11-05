// CONSTRUCT BINARY TREE FROM PREORDER AND INORDER TRAVERSAL

#include <iostream>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the index of a value in the inorder array
int findInorderIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

// Helper function to construct the binary tree
TreeNode* buildTreeHelper(int preorder[], int inorder[], int& preorderIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    // Pick current node from Preorder traversal using preorderIndex and increment preorderIndex
    int rootVal = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootVal);

    // If this node has no children, return the node
    if (inorderStart == inorderEnd) {
        return root;
    }

    // Find the index of this node in Inorder traversal
    int inorderIndex = findInorderIndex(inorder, inorderStart, inorderEnd, rootVal);

    // Using index in Inorder traversal, construct left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, preorderIndex, inorderStart, inorderIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd);

    return root;
}

// Function to build tree given preorder and inorder arrays
TreeNode* buildTree(int preorder[], int inorder[], int n) {
    int preorderIndex = 0;
    return buildTreeHelper(preorder, inorder, preorderIndex, 0, n - 1);
}

// Utility function to print the inorder traversal of the tree
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Utility function to print the preorder traversal of the tree
void printPreorder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTree(preorder, inorder, n);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << "\nPreorder traversal of the constructed tree: ";
    printPreorder(root);

    return 0;
}

