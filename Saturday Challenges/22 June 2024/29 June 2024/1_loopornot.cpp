#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* floydDetectLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head) {
    if (head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);

    if (intersection == NULL)
        return NULL;

    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

int main() {
    // Creating nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = third;

    Node* startNode = getStartingNode(head);

    if (startNode != NULL) {
        cout << "Loop detected. Starting node of the loop is: " << startNode->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;
}



