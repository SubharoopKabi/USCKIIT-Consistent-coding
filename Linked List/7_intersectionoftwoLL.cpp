#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// Function to print a linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to insert a new node at the end of the list
Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* findIntersection(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* temp;
    Node* prev = NULL;
    while (head1 && head2) {
        int a = head1->data;
        int b = head2->data;

        if (a == b) {
            temp = new Node(a);
            if (head == NULL) {
                head = temp;
            } else {
                prev->next = temp;
            }
            head2 = head2->next;
            head1 = head1->next;
            prev = temp;
        } else if (a > b) {
            head2 = head2->next;
        } else {
            head1 = head1->next;
        }
    }
    return head;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Creating the first linked list
    list1 = insert(list1, 1);
    list1 = insert(list1, 2);
    list1 = insert(list1, 3);
    list1 = insert(list1, 4);
    list1 = insert(list1, 6);

    // Creating the second linked list
    list2 = insert(list2, 2);
    list2 = insert(list2, 4);
    list2 = insert(list2, 6);
    list2 = insert(list2, 8);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Finding the intersection
    Node* intersection = findIntersection(list1, list2);

    cout << "Intersection List: ";
    printList(intersection);

    return 0;
}
