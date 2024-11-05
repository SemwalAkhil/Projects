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

// Reverse inorder traversal to store elements in descending order
void reverseInorder(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }
    
    reverseInorder(root->right, arr);
    arr.push_back(root->val);
    reverseInorder(root->left, arr);
}

// Function to find the k-th largest element in the BST
int findKthLargest(TreeNode* root, int k) {
    vector<int> arr;
    
    // Step 1: Store elements in reverse inorder (descending order)
    reverseInorder(root, arr);
    
    // Step 2: Check if k is valid
    if (k > 0 && k <= arr.size()) {
        return arr[k - 1];
    } else {
        cout << "k is out of bounds." << endl;
        return -1; // or handle the error as appropriate
    }
}

int main() {
    TreeNode* root = nullptr;
    int n, value, k;

    // Building a sample BST
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values of nodes:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Enter k to find the k-th largest element: ";
    cin >> k;

    int result = findKthLargest(root, k);
    if (result != -1) {
        cout << "The " << k << "-th largest element is: " << result << endl;
    }

    return 0;
}
