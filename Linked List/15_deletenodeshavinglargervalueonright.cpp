#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* compute(Node* head) {
    head = reverse(head);
    Node* prev = head;
    Node* curr = head->next;

    while (curr) {
        if (curr->data >= prev->data) {
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }

    prev->next = NULL;
    head = reverse(head);
    return head;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    push(&head, 12);
    push(&head, 15);
    push(&head, 10);
    push(&head, 11);
    push(&head, 5);
    push(&head, 6);
    push(&head, 2);
    push(&head, 3);

    cout << "Original List: ";
    printList(head);
    cout << endl;

    head = compute(head);

    cout << "Modified List: ";
    printList(head);
    cout << endl;

    return 0;
}
