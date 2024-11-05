#include <iostream>
#include <algorithm> // for max function
#include <queue>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert nodes in a binary tree level by level
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        
        // Insert in the left subtree
        if (temp->left == nullptr) {
            temp->left = new TreeNode(value);
            break;
        } else {
            q.push(temp->left);
        }
        
        // Insert in the right subtree
        if (temp->right == nullptr) {
            temp->right = new TreeNode(value);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Function to create a binary tree from user input
TreeNode* createBinaryTree() {
    TreeNode* root = nullptr;
    int n, value;
    
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the node values:\n";
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insertNode(root, value);
    }
    
    return root;
}

// Recursive function to find the maximum depth of the binary tree
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    // Create binary tree from user input
    TreeNode* root = createBinaryTree();
    
    // Calculate and display the maximum depth
    int depth = maxDepth(root);
    cout << "Maximum Depth of the Binary Tree: " << depth << endl;
    
    return 0;
}
