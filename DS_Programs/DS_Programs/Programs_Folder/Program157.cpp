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

// Inorder traversal to store elements in ascending order
void inorder(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }
    
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

// Function to find the k-th smallest element in the BST
int findKthSmallest(TreeNode* root, int k) {
    vector<int> arr;
    
    // Step 1: Store elements in inorder (ascending order)
    inorder(root, arr);
    
    // Step 2: Check if k is valid
    if (k > 0 && k <= arr.size()) {
        return arr[k - 1]; // k-1 because arrays are 0-indexed
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

    cout << "Enter k to find the k-th smallest element: ";
    cin >> k;

    int result = findKthSmallest(root, k);
    if (result != -1) {
        cout << "The " << k << "-th smallest element is: " << result << endl;
    }

    return 0;
}
