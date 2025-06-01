#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator to sort edges by weight
bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal’s Algorithm
void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdge);

    DSU dsu(V);
    vector<Edge> result;
    int totalCost = 0;

    for (const auto& edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            result.push_back(edge);
            totalCost += edge.weight;
            dsu.unite(edge.src, edge.dest);
        }
    }

    cout << "Edge \tWeight\n";
    for (const auto& edge : result)
        cout << edge.src << " - " << edge.dest << "\t" << edge.weight << "\n";

    cout << "Total cost of MST: " << totalCost << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter each edge in the format: src dest weight\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(V, edges);

    return 0;
}
