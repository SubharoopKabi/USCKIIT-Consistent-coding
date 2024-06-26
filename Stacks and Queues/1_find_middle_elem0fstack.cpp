#include <bits/stdc++.h>
using namespace std;

class DLLNode {
    public:
    DLLNode* prev;
    int data;
    DLLNode* next;
};

class myStack {
    public:
    DLLNode* head;
    DLLNode* mid;
    int count;

        // Constructor to initialize the stack
    myStack() : head(nullptr), mid(nullptr), count(0) {}

    // Function to print the stack
    void printStack() {
        if (head == nullptr) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        DLLNode* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

myStack* createMyStack()
{
    myStack* ms = new myStack();
    ms->count = 0;
    return ms;
};

void push(myStack* ms, int new_data) {

    DLLNode* new_DLLNode = new DLLNode();
    new_DLLNode->data = new_data;

    new_DLLNode->prev = NULL;

    new_DLLNode->next = ms->head;

    ms->count += 1;

    if (ms->count == 1) {
        ms->mid = new_DLLNode;
    }
    else {
        ms->head->prev = new_DLLNode;

        if (!(ms->count
            & 1)) 
            ms->mid = ms->mid->prev;
    }

    ms->head = new_DLLNode;
}

int pop(myStack* ms) {

    if (ms->count == 0) {
        cout << "Stack is empty\n";
        return -1;
    }

    DLLNode* head = ms->head;
    int item = head->data;
    ms->head = head->next;

    if (ms->head != NULL)
        ms->head->prev = NULL;

    ms->count -= 1;

    if ((ms->count) & 1)
        ms->mid = ms->mid->next;

    free(head);

    return item;
}


int findMiddle(myStack* ms)
{
    if (ms->count == 0) {
        cout << "Stack is empty now\n";
        return -1;
    }

    return ms->mid->data;
}

int  deletemiddle(myStack* ms)
{
    int temp = ms->mid->data;
    ms->mid->prev->next = ms->mid->next;
    ms->mid->next->prev = ms->mid->prev->next;

    delete ms->mid;
    return temp;
}

void printstack(myStack* ms){
        if (ms->count == 0) {
        cout << "Stack is empty now\n";
        
    }
    
}

int main()
{
    myStack* ms = createMyStack();

    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
    ms->printStack();
    cout <<endl<< "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    cout << "deleted mid element " << deletemiddle(ms) << endl;
    return 0;
}