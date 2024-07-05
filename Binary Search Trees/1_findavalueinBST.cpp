#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int item) {
    Node* temp = new Node();
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key = 40;
    Node* result = search(root, key);
    if (result != NULL)
        std::cout << "Key " << key << " found in the tree.\n";
    else
        std::cout << "Key " << key << " not found in the tree.\n";

    return 0;
}
