#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> undoStack;
stack<string> redoStack;

// Perform a new action
void performAction(string action) {
    undoStack.push(action);

    // Clear redo stack when a new action is performed
    while (!redoStack.empty()) {
        redoStack.pop();
    }

    cout << "Action performed: " << action << endl;
}

// Undo the last action
void undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo." << endl;
        return;
    }

    string action = undoStack.top();
    undoStack.pop();

    redoStack.push(action);

    cout << "Undo: " << action << endl;
}

// Redo the last undone action
void redo() {
    if (redoStack.empty()) {
        cout << "Nothing to redo." << endl;
        return;
    }

    string action = redoStack.top();
    redoStack.pop();

    undoStack.push(action);

    cout << "Redo: " << action << endl;
}

int main() {
    performAction("Type Hello");
    performAction("Type World");
    performAction("Delete World");

    cout << endl;

    undo();
    undo();

    cout << endl;

    redo();

    return 0;
}