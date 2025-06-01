#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Topological Sort using Kahn's Algorithm
void topologicalSort(int V, vector<vector<int> >& adj) {
    vector<int> inDegree(V, 0);

    // Compute in-degree of each vertex
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topoOrder;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    // Check for cycle
    if (topoOrder.size() != V) {
        cout << "The graph has a cycle. Topological sorting is not possible.\n";
        return;
    }

    // Output the topological order
    cout << "Topological Order: ";
    for (int node : topoOrder)
        cout << node << " ";
    cout << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int> > adj(V);

    cout << "Enter each directed edge (from to):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSort(V, adj);

    return 0;
}
