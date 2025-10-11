#include <bits/stdc++.h>
using namespace std;

// Perform BFS from a given start node
vector<int> bfsTraversal(vector<vector<int>> &adj, vector<bool> &visited, int start) {
    queue<int> q;
    vector<int> comp; // stores nodes in the current connected component

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        comp.push_back(node);

        for (auto &neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    return comp;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // Sort adjacency list so BFS processes nodes in ascending order
    for (int i = 0; i < V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> visited(V, false);
    vector<vector<int>> components;

    // Run BFS for all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> comp = bfsTraversal(adj, visited, i);
            components.push_back(comp);
        }
    }

    // Output
    cout << "Number of connected components: " << components.size() << "\n";
    for (auto &comp : components) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
