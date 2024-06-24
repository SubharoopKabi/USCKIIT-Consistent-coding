#include <bits/stdc++.h>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

int subTreesHeight(Node* n, int* diameter) {

    if (!n) return 0;

    int l = subTreesHeight(n->left, diameter);
    int r = subTreesHeight(n->right, diameter);

    if (l + r + 1 > *diameter) *diameter = l + r + 1;

    return 1 + max(l, r);
}

int diameter(Node* root) {
    int diameter = 0;
    subTreesHeight(root, &diameter);
    return diameter;
}

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->right->right = new Node(10);

    int treeDiameter = diameter(root);
    
    cout << "Diameter of the tree is: " << treeDiameter << endl;

    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
