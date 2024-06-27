#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void bottomView(Node* root) {
    if (root == nullptr) return;

    // Map to store the last node at each horizontal distance
    map<int, int> hdMap;

    // Queue to store nodes along with their horizontal distance from the root
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* node = temp.first;
        int hd = temp.second;

        // Store or update the map with the node data at horizontal distance hd
        hdMap[hd] = node->data;

        if (node->left) {
            q.push(make_pair(node->left, hd - 1));
        }
        if (node->right) {
            q.push(make_pair(node->right, hd + 1));
        }
    }

    // Print the bottom view
    for (auto it : hdMap) {
        cout << it.second << " ";
    }
    cout << endl;
}

Node* newNode(int data) {
    return new Node(data);
}

int main() {
    /* Create a binary tree
              1
             / \
            2   3
           / \   \
          4   5   6
                 /
                7
    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->right->right->left = newNode(7);

    cout << "Bottom view of the binary tree is: ";
    bottomView(root);

    return 0;
}
