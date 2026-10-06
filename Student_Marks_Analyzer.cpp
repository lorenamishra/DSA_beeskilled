#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 3) {
        cout << "Please enter at least 3 students." << endl;
        return 0;
    }

    int marks[n];
    int sum = 0;

    cout << "Enter marks of " << n << " students: ";

    for (int i = 0; i < n; i++) {
        cin >> marks[i];
        sum += marks[i];
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    // Top 3 marks
    cout << "Top 3 marks: ";

    for (int i = n - 1; i >= n - 3; i--) {
        cout << marks[i] << " ";
    }

    cout << endl;

    // Average
    double average = (double)sum / n;

    cout << "Average score: " << average << endl;

    return 0;
}