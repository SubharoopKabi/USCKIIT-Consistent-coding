#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) : data(x), next(NULL), random(NULL) {}
};

Node* clone(Node* start) {
    Node* curr = start, * temp;

    while (curr) {
        temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;

    while (curr) {
        if (curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node* original = start, * copy = start->next;
    temp = copy;

    while (original && copy) {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}

void printList(Node* head) {
    while (head != NULL) {
        std::cout << "Data = " << head->data << ", Random = "
                  << (head->random ? head->random->data : -1) << std::endl;
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    Node* cloned_head = clone(head);

    std::cout << "Original list:" << std::endl;
    printList(head);

    std::cout << "Cloned list:" << std::endl;
    printList(cloned_head);

    return 0;
}
