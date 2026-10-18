#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert nodes to create a BST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find the first violating node
bool validateBST(Node* root, long long minVal,
                 long long maxVal, int &badNode) {
    if (root == nullptr)
        return true;

    if (root->data <= minVal || root->data >= maxVal) {
        badNode = root->data;
        return false;
    }

    if (!validateBST(root->left, minVal,
                      root->data, badNode))
        return false;

    if (!validateBST(root->right, root->data,
                      maxVal, badNode))
        return false;

    return true;
}

// Display tree using inorder traversal
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Free allocated memory
void deleteTree(Node* root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "DATABASE INDEX VALIDATION\n";
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of nodes.\n";
        return 0;
    }

    cout << "Enter node values:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    int badNode = 0;

    if (validateBST(root, LLONG_MIN,
                     LLONG_MAX, badNode)) {
        cout << "\nResult: Valid Binary Search Tree.\n";
        cout << "Database index validation successful.\n";
    } else {
        cout << "\nResult: Invalid Binary Search Tree.\n";
        cout << "First violating node: " << badNode << endl;
    }

    deleteTree(root);
    return 0;
}



