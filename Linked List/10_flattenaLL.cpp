#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* bottom;
    
    Node(int x) : data(x), next(NULL), bottom(NULL) {}
};

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

void printList(Node* root) {
    while (root != NULL) {
        std::cout << root->data << " ";
        root = root->bottom;
    }
    std::cout << std::endl;
}

int main() {
    Node* root = new Node(5);
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);

    root->next = new Node(10);
    root->next->bottom = new Node(20);

    root->next->next = new Node(19);
    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next = new Node(28);
    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    root = flatten(root);

    printList(root);

    return 0;
}
