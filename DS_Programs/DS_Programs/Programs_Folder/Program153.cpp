#include <iostream>
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

// Function to find the minimum value node in the BST
TreeNode* findMin(TreeNode* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value node in the BST
TreeNode* findMax(TreeNode* root) {
    while (root && root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Function to find the inorder predecessor of a given key
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* node) {
    TreeNode* predecessor = nullptr;
    
    while (root != nullptr) {
        if (node->val > root->val) {
            predecessor = root; // Last right turn
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

// Function to find the inorder successor of a given key
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* node) {
    TreeNode* successor = nullptr;

    while (root != nullptr) {
        if (node->val < root->val) {
            successor = root; // Last left turn
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

int main() {
    TreeNode* root = nullptr;
    int choice, value;

    // Sample insertions to create a tree
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    cout << "Enter value to find predecessor and successor: ";
    cin >> value;

    // Search for the node with the given value
    TreeNode* node = root;
    while (node != nullptr && node->val != value) {
        if (value < node->val)
            node = node->left;
        else
            node = node->right;
    }

    if (node == nullptr) {
        cout << "Node not found in the tree.\n";
        return 0;
    }

    // Finding the inorder predecessor and successor
    TreeNode* pred = inorderPredecessor(root, node);
    TreeNode* succ = inorderSuccessor(root, node);

    if (pred != nullptr)
        cout << "Inorder Predecessor of " << value << " is: " << pred->val << endl;
    else
        cout << "Inorder Predecessor of " << value << " does not exist.\n";

    if (succ != nullptr)
        cout << "Inorder Successor of " << value << " is: " << succ->val << endl;
    else
        cout << "Inorder Successor of " << value << " does not exist.\n";

    return 0;
}
