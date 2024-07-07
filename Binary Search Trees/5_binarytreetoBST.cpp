#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void getInorder(Node* root, vector<int>& v) {
    if (!root) return;
    getInorder(root->left, v);
    v.push_back(root->data);
    getInorder(root->right, v);
}

void setInorder(vector<int> v, Node* root, int& i) {
    if (!root) return;
    setInorder(v, root->left, i);
    root->data = v[i];
    i++;
    setInorder(v, root->right, i);
}

Node* binaryTreeToBST(Node* root) {
    vector<int> v;
    getInorder(root, v);
    sort(v.begin(), v.end());
    int i = 0;
    setInorder(v, root, i);
    return root;
}

void printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    root = binaryTreeToBST(root);

    cout << "Inorder traversal of the converted BST: ";
    printInorder(root);

    return 0;
}
