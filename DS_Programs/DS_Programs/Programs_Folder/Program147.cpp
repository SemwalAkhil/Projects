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

// Recursive function to print the left view of the binary tree
void printLeftView(TreeNode* node, int level, int& maxLevel) {
    if (node == nullptr) return;

    // If this is the first node of this level
    if (maxLevel < level) {
        cout << node->val << " ";
        maxLevel = level;
    }

    // Recurse for left and right subtrees
    printLeftView(node->left, level + 1, maxLevel);
    printLeftView(node->right, level + 1, maxLevel);
}

// Function to initiate left view printing
void leftView(TreeNode* root) {
    int maxLevel = 0;
    cout << "Left View of the Binary Tree: ";
    printLeftView(root, 1, maxLevel);
    cout << endl;
}

int main() {
    // Create binary tree from user input
    TreeNode* root = createBinaryTree();
    
    // Print left view
    leftView(root);
    
    return 0;
}
