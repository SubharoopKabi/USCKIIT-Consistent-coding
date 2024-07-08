#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int size(Node* temp) {
    Node* head = temp;
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int getNthFromLast(Node* head, int n) {
    int sz = size(head);
    if (sz - n < 0) return -1;
    for (int i = 0; i < sz - n; i++) {
        head = head->next;
    }
    return head->data;
}

int getNthFromLastTwoPointer(Node* head, int n) {
    Node* left = head;
    Node* right = head;
    while (n && right) {
        right = right->next;
        n--;
    }
    if (right == NULL && n > 0) return -1;
    while (right) {
        left = left->next;
        right = right->next;
    }
    return left->data;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    cout << "Element at 2nd position from end (using size method) is: " << getNthFromLast(head, 2) << endl;
    cout << "Element at 2nd position from end (using two-pointer method) is: " << getNthFromLastTwoPointer(head, 2) << endl;

    return 0;
}
