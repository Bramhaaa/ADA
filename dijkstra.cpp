#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Pair: (distance, vertex)
typedef pair<int, int> pii;

// Dijkstra's algorithm function
void dijkstra(int V, vector<vector<pii>>& adj, int src) {
    vector<int> dist(V, INT_MAX); // Distance from source to each vertex
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src}); // (distance, vertex)

    while (!pq.empty()) {
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        // Visit all neighbors of u
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > d_u + weight) {
                dist[v] = d_u + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output shortest distances
    cout << "Vertex\tDistance from Source " << src << "\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V, E, src;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    cout << "Enter edges in the format: u v weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }

    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}
