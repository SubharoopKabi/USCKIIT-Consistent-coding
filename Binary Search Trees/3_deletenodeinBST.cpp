#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newNode(int item) {
    return new TreeNode(item);
}

TreeNode* insert(TreeNode* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->val)
        node->left = insert(node->left, data);
    else if (data > node->val)
        node->right = insert(node->right, data);
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;

    if (root->val == key) {
        if (!root->right) {
            TreeNode* left = root->left;
            delete root;
            return left;
        } else if (!root->left) {
            TreeNode* right = root->right;
            delete root;
            return right;
        } else {
            TreeNode* right = root->right;
            while (right->left) {
                right = right->left;
            }
            std::swap(root->val, right->val);
        }
    }

    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorderTraversal(root);
    cout << std::endl;

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorderTraversal(root);
    cout << std::endl;

    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorderTraversal(root);
    cout << std::endl;

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorderTraversal(root);
    cout << std::endl;

    return 0;
}
