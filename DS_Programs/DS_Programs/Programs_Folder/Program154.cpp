#include <iostream>
#include <climits>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert a node in the BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to check for dead end
bool isDeadEnd(TreeNode* root, int min = 1, int max = INT_MAX) {
    if (root == nullptr) {
        return false;
    }

    // If this is a dead end
    if (min == max) {
        return true;
    }

    // Recur for left and right subtrees with updated ranges
    return isDeadEnd(root->left, min, root->val - 1) || isDeadEnd(root->right, root->val + 1, max);
}

int main() {
    TreeNode* root = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values of nodes:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    if (isDeadEnd(root)) {
        cout << "The Binary Search Tree contains a dead end.\n";
    } else {
        cout << "The Binary Search Tree does not contain a dead end.\n";
    }

    return 0;
}
