#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> zigZagTraversal(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    Node* curr;
    queue<Node*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        stack<Node*> s;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            curr = q.front();
            ans.push_back(curr->data);
            if (level % 2) {
                if (curr->left) s.push(curr->left);
                if (curr->right) s.push(curr->right);
            } else {
                if (curr->right) s.push(curr->right);
                if (curr->left) s.push(curr->left);
            }
            q.pop();
        }
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        level++;
    }
    return ans;
}

Node* newNode(int data) {
    return new Node(data);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<int> result = zigZagTraversal(root);

    cout << "Zigzag Traversal of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
