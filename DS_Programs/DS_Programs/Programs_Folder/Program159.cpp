#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to build the BST from preorder traversal
TreeNode* buildBSTFromPreorderUtil(const vector<int>& preorder, int& index, int min, int max) {
    if (index >= preorder.size()) {
        return nullptr;
    }

    int value = preorder[index];

    // Only insert if the current value is within the valid range (min, max)
    if (value < min || value > max) {
        return nullptr;
    }

    // Create the root node with the current value and move to the next element
    TreeNode* root = new TreeNode(value);
    index++; // Move to the next element in preorder array

    // Recursively build the left and right subtrees
    root->left = buildBSTFromPreorderUtil(preorder, index, min, value - 1);
    root->right = buildBSTFromPreorderUtil(preorder, index, value + 1, max);

    return root;
}

// Main function to initiate building the BST from preorder traversal
TreeNode* buildBSTFromPreorder(const vector<int>& preorder) {
    int index = 0;
    return buildBSTFromPreorderUtil(preorder, index, INT_MIN, INT_MAX);
}

// Inorder traversal to print the BST (to verify it is constructed correctly)
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cout << "Enter the number of nodes in the preorder traversal: ";
    cin >> n;

    vector<int> preorder(n);
    cout << "Enter the preorder traversal:\n";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    // Build the BST from preorder traversal
    TreeNode* root = buildBSTFromPreorder(preorder);

    // Print the inorder traversal of the constructed BST
    cout << "Inorder traversal of the constructed BST:\n";
    printInorder(root);
    cout << endl;

    return 0;
}
