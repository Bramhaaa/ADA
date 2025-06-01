#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define INF 99999  // A large value representing "infinity"

// Function to implement Floyd–Warshall algorithm
void floydWarshall(vector<vector<int>>& dist, int V) {
    // k is the intermediate vertex
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Update dist[i][j] only if the path through k is shorter
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

// Function to print the shortest distance matrix
void printMatrix(const vector<vector<int>>& dist, int V) {
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (use 99999 for INF):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    floydWarshall(graph, V);
    printMatrix(graph, V);

    return 0;
}
