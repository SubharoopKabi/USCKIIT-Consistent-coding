#include <iostream>
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

struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }

    void reverse()
    {
        Node* current = head;
        Node* prev = NULL, * next = NULL;

        while (current != NULL) {
       
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList L;
    L.push(20);
    L.push(4);
    L.push(15);
    L.push(85);

    cout << "Given linked list\n";
    L.print();

    L.reverse();

    cout << "\nReversed Linked list \n";
    L.print();
    return 0;
}