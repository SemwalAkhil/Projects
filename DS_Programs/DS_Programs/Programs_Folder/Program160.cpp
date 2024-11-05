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

// Recursive function to build the BST from postorder traversal
TreeNode* buildBSTFromPostorderUtil(const vector<int>& postorder, int& index, int min, int max) {
    if (index < 0) {
        return nullptr;
    }

    int value = postorder[index];

    // Only insert if the current value is within the valid range (min, max)
    if (value < min || value > max) {
        return nullptr;
    }

    // Create the root node with the current value and move to the previous element
    TreeNode* root = new TreeNode(value);
    index--; // Move to the previous element in postorder array

    // Recursively build the right and left subtrees
    root->right = buildBSTFromPostorderUtil(postorder, index, value + 1, max);
    root->left = buildBSTFromPostorderUtil(postorder, index, min, value - 1);

    return root;
}

// Main function to initiate building the BST from postorder traversal
TreeNode* buildBSTFromPostorder(const vector<int>& postorder) {
    int index = postorder.size() - 1;
    return buildBSTFromPostorderUtil(postorder, index, INT_MIN, INT_MAX);
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
    cout << "Enter the number of nodes in the postorder traversal: ";
    cin >> n;

    vector<int> postorder(n);
    cout << "Enter the postorder traversal:\n";
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    // Build the BST from postorder traversal
    TreeNode* root = buildBSTFromPostorder(postorder);

    // Print the inorder traversal of the constructed BST
    cout << "Inorder traversal of the constructed BST:\n";
    printInorder(root);
    cout << endl;

    return 0;
}
