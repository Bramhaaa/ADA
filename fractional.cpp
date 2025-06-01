#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int value, weight;
};

// Comparator to sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to get maximum value in the knapsack
double fractionalKnapsack(int W, vector<Item>& items, int N) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (int i = 0; i < N; i++) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int N, W;
    cout << "Enter number of items: ";
    cin >> N;

    vector<Item> items(N);

    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < N; i++) {
        cout << "Item " << i + 1 << " - Value: ";
        cin >> items[i].value;
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, items, N);
    cout << fixed << setprecision(2);
    cout << "Maximum value in knapsack = " << maxValue << "\n";

    return 0;
}
