
#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& dp) {

    // Base cases
    if (n <= 1)
        return n;

    // If already calculated
    if (dp[n] != -1)
        return dp[n];

    // Calculate and store result
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);

    return dp[n];
}

int main() {

    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << "Fibonacci number using Memoization: "
         << fibonacci(n, dp);

    return 0;
}





#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {

    vector<int> dp(n + 1, 0);

    // Base cases
    if (n >= 1)
        dp[1] = 1;

    // Calculate Fibonacci numbers
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {

    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number using Tabulation: "
         << fibonacci(n);

    return 0;
}
