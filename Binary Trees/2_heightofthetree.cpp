#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* left, * right;

    // Constructor to initialize the node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


int height( Node* node)
{
    // if node is null, we return 0.
    if (node == NULL) return 0;

    else {
        int lHeight = height(node->left);
        int rHeight = height(node->right);

        if (lHeight > rHeight) {
            return lHeight + 1;
        }
        else {
            return rHeight + 1;
        }
    }
}

int main(){
 // Creating a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);

    // Calculating the height of the tree
    int treeHeight = height(root);
    
    // Printing the height of the tree
    cout << "Height of the tree is: " << treeHeight << endl;

    // Clean up the dynamically allocated memory
    // A tree destructor can be used in place of this.
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}