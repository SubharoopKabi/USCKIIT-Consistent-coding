#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int x) : data(x), next(NULL) {}
};

Node* newNode(int data) {
    return new Node(data);
}

Node* sortList(Node* head) {
    if (!head || !(head->next))
        return head;

    Node* zeroD = newNode(0);
    Node* oneD = newNode(0);
    Node* twoD = newNode(0);

    Node* zero = zeroD, * one = oneD, * two = twoD;

    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = NULL;

    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(1);

    head = sortList(head);

    printList(head);

    return 0;
}
