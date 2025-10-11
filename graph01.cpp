#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
using namespace std;

template<typename T>
class graph {
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    void printlist() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: " << endl;
    cin >> n >> m;
    graph<int > g;
    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        g.addEdge(u, v); // By default, undirected
    }
    g.printlist();
    return 0;
}