#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert node at the end
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Reverse using stack
void reverseUsingStack(Node*& head) {
    if (head == nullptr) {
        return;
    }

    stack<Node*> s;
    Node* temp = head;

    // Push all nodes into stack
    while (temp != nullptr) {
        s.push(temp);
        temp = temp->next;
    }

    // New head is the last node
    head = s.top();
    s.pop();

    temp = head;

    // Connect nodes in reverse order
    while (!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }

    temp->next = nullptr;
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Original Linked List: ";
    display(head);

    reverseUsingStack(head);

    cout << "Reversed Linked List: ";
    display(head);

    return 0;
}