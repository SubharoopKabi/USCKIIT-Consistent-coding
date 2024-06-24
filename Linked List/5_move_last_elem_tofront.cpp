#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node* createLinkedList(initializer_list<int> values) {
    Node* head = NULL;
    Node* current = NULL;

    for (int value : values) {
        if (head == NULL) {
            head = new Node(value);
            current = head;
        } else {
            current->next = new Node(value);
            current = current->next;
        }
    }

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


void moveToFront(Node* &head) {
    if (head == NULL || head->next == NULL) return;

    Node* last = head;
    Node* second_last = NULL;

    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;

    last->next = head;

    head = last;
}

int main() {

    Node* head = createLinkedList({1, 2, 3, 4, 5});

    cout << "Original list: ";
    printList(head);

    moveToFront(head);

    cout << "List after moving last node to front: ";
    printList(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
