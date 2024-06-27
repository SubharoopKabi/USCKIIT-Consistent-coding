#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void topView(Node* root) {
    if (root == nullptr) return;

    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    int hd = 0;
    int l = 0;
    int r = 0;

    stack<int> left;
    vector<int> right;

    Node* node;

    while (!q.empty()) {
        node = q.front().first;
        hd = q.front().second;

        if (hd < l) {
            left.push(node->data);
            l = hd;
        } else if (hd > r) {
            right.push_back(node->data);
            r = hd;
        }

        if (node->left) {
            q.push(make_pair(node->left, hd - 1));
        }
        if (node->right) {
            q.push(make_pair(node->right, hd + 1));
        }

        q.pop();
    }

    while (!left.empty()) {
        cout << left.top() << " ";
        left.pop();
    }

    cout << root->data << " ";

    for (int x : right) {
        cout << x << " ";
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

    cout << "Top view of the binary tree is: ";
    topView(root);

    return 0;
}
