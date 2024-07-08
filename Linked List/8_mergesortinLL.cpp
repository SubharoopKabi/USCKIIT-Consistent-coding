#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node* merge(Node* head1, Node* head2) {
    // Create a dummy node to start the merged list
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    // Merge the two lists until one is exhausted
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    // Append the remaining list, if any
    while (head1 != nullptr) {
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }

    while (head2 != nullptr) {
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }

    Node* mergedHead = dummy->next;
    delete dummy; 
    return mergedHead;
}


Node* findMid(Node* head) {
    if (head == nullptr) return head;
    
    Node* slow = head;
    Node* fast = head->next;

    // Move slow by one step and fast by two steps
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Slow is now at the middle
}


Node* mergeSort(Node* head) {
    
    if (head == nullptr || head->next == nullptr)
        return head;

    
    Node* mid = findMid(head);
    Node* head2 = mid->next;
    mid->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(head2);


    return merge(left, right);
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    // Create an unsorted linked list
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(8);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);

    cout << "Unsorted Linked List:" << endl;
    printList(head);

    // Sort the linked list
    head = mergeSort(head);

    cout << "Sorted Linked List:" << endl;
    printList(head);

    // Free allocated memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
