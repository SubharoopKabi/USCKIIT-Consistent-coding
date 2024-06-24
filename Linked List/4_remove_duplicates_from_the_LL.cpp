#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void removeDuplicates(struct Node* start)
{
    struct Node* ptr1, * ptr2, * dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

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
    Node* head = createLinkedList({1, 2, 2, 3, 4, 4, 4, 5});

    cout << "Original list: ";
    printList(head);

    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
