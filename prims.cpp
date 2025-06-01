#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define MAX 100

int minKey(const vector<int> &key, const vector<bool> &mstSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMST(int graph[MAX][MAX], int V) {
    vector<int> parent(V);   // To store constructed MST
    vector<int> key(V, INT_MAX); // Used for key values to pick minimum weight edge
    vector<bool> mstSet(V, false); // To represent set of vertices included in MST

    key[0] = 0;     // Start from first vertex
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    // Print the MST and total cost
    int totalCost = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
        totalCost += graph[i][parent[i]];
    }
    cout << "Total cost of MST: " << totalCost << "\n";
}

int main() {
    int V;
    int graph[MAX][MAX];

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph, V);

    return 0;
}
