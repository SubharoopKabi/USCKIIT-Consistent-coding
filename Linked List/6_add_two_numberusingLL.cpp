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

// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to add two linked lists
struct Node* addTwoLists(struct Node* first, struct Node* second) {
    Node* head = NULL;
    Node* prev = NULL;
    Node* temp = NULL;
    first = reverse(first);
    second = reverse(second);

    int carry = 0;

    while (first != NULL || second != NULL) {
        int curr_sum = ((first) ? first->data : 0) + ((second) ? second->data : 0) + carry;

        carry = (curr_sum >= 10) ? 1 : 0;
        curr_sum = curr_sum % 10;

        temp = new Node(curr_sum);
        if (head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;

        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0) prev->next = new Node(carry);

    head = reverse(head);

    return head;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an initializer list
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

int main() {
    // Create two linked lists representing the numbers 243 (2 -> 4 -> 3) and 564 (5 -> 6 -> 4)
    Node* first = createLinkedList({2, 4, 3});
    Node* second = createLinkedList({5, 6, 4});

    // Print the two lists
    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);

    // Add the two lists
    Node* result = addTwoLists(first, second);

    // Print the result
    cout << "Result List: ";
    printList(result);

    // Clean up: Free allocated memory for the lists
    Node* temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }

    while (second != NULL) {
        temp = second;
        second = second->next;
        delete temp;
    }

    while (result != NULL) {
        temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
