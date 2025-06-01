#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Return the maximum value that can be put in a knapsack of capacity W
    return dp[N][W];
}

int main() {
    int N, W;
    cout << "Enter number of items: ";
    cin >> N;

    vector<int> weights(N), values(N);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < N; i++)
        cin >> weights[i];

    cout << "Enter values of items:\n";
    for (int i = 0; i < N; i++)
        cin >> values[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxValue = knapsack(W, weights, values, N);
    cout << "Maximum value in Knapsack = " << maxValue << "\n";

    return 0;
}
