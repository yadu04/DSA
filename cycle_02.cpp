// Cycle detection  to the Directed graph using the DFS
#include<bits/stdc++.h>
using namespace std;
bool iscyclic(vector<vector<int>> &adj,vector<int> &visited,int node,vector<int>&dfs){
  visited[node]=1;
  dfs[node]=1;
  for(auto &neighbour: adj[node]){
    if(!visited[neighbour]){
        bool cycle =iscyclic(adj,visited,neighbour,dfs);
        if(cycle) return true;
    }
    else if(dfs[neighbour]==1){
        return true;
    }
  }
  dfs[node]=0;
  return false;

}
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
     
    }

    vector<int> visited(V, false);
    vector<int> dfs(V,false);
    bool cycle_found = false;

    // Check for cycle in each component
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (iscyclic(adj, visited, i,dfs)) {
                cycle_found = true;
                break;
            }
        }
    }

    if (cycle_found)
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle detected in the graph." << endl;

    return 0;
}