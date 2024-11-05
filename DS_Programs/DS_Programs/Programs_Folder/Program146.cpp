// BINARY TREE LEVEL ORDER TRAVERSAL

#include <iostream>
#include <queue>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function for level-order traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q; // Queue to hold nodes at each level
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " "; // Process the current node

        // Add left and right children to the queue if they exist
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

int main() {
    // Creating a simple binary tree for demonstration
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Level Order Traversal of the tree: ";
    levelOrderTraversal(root);

    return 0;
}

