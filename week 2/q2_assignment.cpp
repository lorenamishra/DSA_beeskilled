#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

// Push an element
void push(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    cout << value << " pushed into stack." << endl;
}

// Pop an element
void pop() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* temp = top;
    cout << top->data << " popped from stack." << endl;

    top = top->next;
    delete temp;
}

// Display the stack
void display() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* temp = top;

    cout << "Stack: ";

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}