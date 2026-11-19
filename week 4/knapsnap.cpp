
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= W; w++) {

            // If item weight is less than or equal to capacity
            if (wt[i - 1] <= w) {

                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );

            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], val[n];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum profit: "
         << knapsack(W, wt, val, n);

    return 0;
}
