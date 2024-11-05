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

// Recursive function to print the right view of the binary tree
void printRightView(TreeNode* node, int level, int& maxLevel) {
    if (node == nullptr) return;

    // If this is the first node of this level
    if (maxLevel < level) {
        cout << node->val << " ";
        maxLevel = level;
    }

    // Recurse for right and left subtrees
    printRightView(node->right, level + 1, maxLevel);
    printRightView(node->left, level + 1, maxLevel);
}

// Function to initiate right view printing
void rightView(TreeNode* root) {
    int maxLevel = 0;
    cout << "Right View of the Binary Tree: ";
    printRightView(root, 1, maxLevel);
    cout << endl;
}

int main() {
    // Create binary tree from user input
    TreeNode* root = createBinaryTree();
    
    // Print right view
    rightView(root);
    
    return 0;
}
