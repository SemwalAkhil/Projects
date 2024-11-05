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

// Find the minimum value node in the BST
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Search for a key in the BST
bool search(TreeNode* root, int key) {
    if (root == nullptr) return false;
    if (root->val == key) return true;
    if (key < root->val) return search(root->left, key);
    return search(root->right, key);
}

// Preorder traversal of the BST
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal of the BST
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Postorder traversal of the BST
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Find the minimum element in the BST
int findMinimum(TreeNode* root) {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return -1;
    }
    TreeNode* minNode = findMin(root);
    return minNode->val;
}

int main() {
    TreeNode* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Preorder Traversal\n5. Inorder Traversal\n6. Postorder Traversal\n7. Find Minimum Element\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Value found in the tree.\n";
                else
                    cout << "Value not found in the tree.\n";
                break;

            case 4:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 7:
                cout << "Minimum Element: " << findMinimum(root) << endl;
                break;

            case 8:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
