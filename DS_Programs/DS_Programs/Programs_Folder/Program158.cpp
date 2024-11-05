#include <iostream>
#include <vector>
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

// Function to build a BST from preorder traversal
TreeNode* buildBSTFromPreorder(const vector<int>& preorder) {
    TreeNode* root = nullptr;
    for (int val : preorder) {
        root = insert(root, val);
    }
    return root;
}

// Postorder traversal of the BST
void postorderTraversal(TreeNode* root, vector<int>& postorder) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->val);
}

int main() {
    int n;
    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    vector<int> preorder(n);
    cout << "Enter the preorder traversal of the BST:\n";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    // Step 1: Build the BST from the preorder traversal
    TreeNode* root = buildBSTFromPreorder(preorder);

    // Step 2: Perform postorder traversal
    vector<int> postorder;
    postorderTraversal(root, postorder);

    // Print the postorder traversal
    cout << "Postorder traversal of the BST:\n";
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
