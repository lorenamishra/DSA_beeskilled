#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Insert at the end
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Inserted " << value << endl;
}

// Delete a value
void deleteNode(int value) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // If the first node contains the value
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Deleted " << value << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value not found." << endl;
    } else {
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;

        cout << "Deleted " << value << endl;
    }
}

// Display the list
void display() {
    Node* temp = head;

    if (temp == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Linked List: ";

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    deleteNode(20);

    display();

    return 0;
}