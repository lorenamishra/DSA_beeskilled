#include <iostream>
using namespace std;

#define SIZE 5

int arr[SIZE];
int front = -1;
int rear = -1;

// Insert into queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is full." << endl;
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    arr[rear] = value;

    cout << value << " inserted." << endl;
}

// Delete from queue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << arr[front] << " deleted." << endl;
    front++;
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue: ";

    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}