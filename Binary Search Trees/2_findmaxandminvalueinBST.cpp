#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int item) {
    Node* temp = new Node();
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

int minValue(Node* root) {
    if (root == NULL)
        return -1;
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int maxValue(Node* root) {
    if (root == NULL)
        return -1;
    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
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

    int min = minValue(root);
    int max = maxValue(root);

    std::cout << "Minimum value in BST is " << min << std::endl;
    std::cout << "Maximum value in BST is " << max << std::endl;

    return 0;
}
