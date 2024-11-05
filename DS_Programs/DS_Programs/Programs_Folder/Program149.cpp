#include <iostream>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to find the index of a value in the inorder array
int findInorderIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive helper function to construct the binary tree
TreeNode* buildTreeHelper(int postorder[], int inorder[], int& postorderIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    // Get the current root value from postorder traversal
    int rootVal = postorder[postorderIndex--];
    TreeNode* root = new TreeNode(rootVal);

    // If this node has no children, return it
    if (inorderStart == inorderEnd) {
        return root;
    }

    // Find the index of this root in the inorder array
    int inorderIndex = findInorderIndex(inorder, inorderStart, inorderEnd, rootVal);

    // Recursively build the right subtree first, then the left subtree
    root->right = buildTreeHelper(postorder, inorder, postorderIndex, inorderIndex + 1, inorderEnd);
    root->left = buildTreeHelper(postorder, inorder, postorderIndex, inorderStart, inorderIndex - 1);

    return root;
}

// Main function to build the tree from postorder and inorder arrays
TreeNode* buildTree(int postorder[], int inorder[], int n) {
    int postorderIndex = n - 1; // Start from the last element of postorder
    return buildTreeHelper(postorder, inorder, postorderIndex, 0, n - 1);
}

// Utility function to print the inorder traversal of the constructed tree
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Utility function to print the postorder traversal of the constructed tree
void printPostorder(TreeNode* node) {
    if (node == nullptr) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->val << " ";
}

int main() {
    int postorder[] = {9, 15, 7, 20, 3};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTree(postorder, inorder, n);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << "\nPostorder traversal of the constructed tree: ";
    printPostorder(root);

    return 0;
}
