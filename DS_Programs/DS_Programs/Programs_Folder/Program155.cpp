#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert a node in the Binary Tree (for building an example binary tree)
TreeNode* insertBinaryTree(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    
    // Insert left if available, else insert right
    if (!root->left) {
        root->left = insertBinaryTree(root->left, value);
    } else {
        root->right = insertBinaryTree(root->right, value);
    }
    return root;
}

// Inorder traversal to store values in an array
void storeInorder(TreeNode* node, vector<int>& arr) {
    if (node == nullptr) {
        return;
    }
    storeInorder(node->left, arr);
    arr.push_back(node->val);
    storeInorder(node->right, arr);
}

// Sort the array and rebuild the tree with sorted values
void arrayToBST(TreeNode* node, vector<int>& arr, int& index) {
    if (node == nullptr) {
        return;
    }
    arrayToBST(node->left, arr, index);
    node->val = arr[index++];
    arrayToBST(node->right, arr, index);
}

// Function to convert binary tree to BST
void binaryTreeToBST(TreeNode* root) {
    vector<int> arr;

    // Step 1: Store inorder traversal of the binary tree in an array
    storeInorder(root, arr);

    // Step 2: Sort the array
    sort(arr.begin(), arr.end());

    // Step 3: Convert the sorted array back to BST using inorder traversal
    int index = 0;
    arrayToBST(root, arr, index);
}

// Inorder traversal to print the BST
void printInorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    TreeNode* root = nullptr;
    
    // Create an example binary tree
    root = insertBinaryTree(root, 10);
    root = insertBinaryTree(root, 30);
    root = insertBinaryTree(root, 20);
    root = insertBinaryTree(root, 5);
    root = insertBinaryTree(root, 15);

    cout << "Inorder Traversal of Original Binary Tree: ";
    printInorder(root);
    cout << endl;

    // Convert binary tree to BST
    binaryTreeToBST(root);

    cout << "Inorder Traversal of Converted BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
