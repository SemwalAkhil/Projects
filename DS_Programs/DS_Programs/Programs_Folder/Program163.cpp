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

// Function to insert nodes in a complete binary tree
TreeNode* insertCompleteBinaryTree(TreeNode* root, int value) {
    // If the tree is empty, create the root
    if (root == nullptr) {
        return new TreeNode(value);
    }

    // Use a queue to perform level-order insertion
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // Check if the left child is empty
        if (current->left == nullptr) {
            current->left = new TreeNode(value);
            break;
        } else {
            q.push(current->left);
        }

        // Check if the right child is empty
        if (current->right == nullptr) {
            current->right = new TreeNode(value);
            break;
        } else {
            q.push(current->right);
        }
    }
    return root;
}

// Level order traversal to print the tree (to verify structure)
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";
        
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = nullptr;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter values of nodes:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insertCompleteBinaryTree(root, value);
    }

    cout << "Level order traversal of the complete binary tree:\n";
    printLevelOrder(root);

    return 0;
}
