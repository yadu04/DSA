// topological sort using the Khan's algorithm#
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> topo(vector<vector<int>> &adj){
    int n=adj.size();
    vector<int> indegree(n,0);
    for(auto i:adj){
        for(auto j:i){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        // push that to the answer
        ans.push_back(front);
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0) q.push(neighbour);
        }
    }
   return ans;

}
int main() {
    cout << "Enter the number of nodes and edges" << endl;
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v); // Correct type for adjacency list
    for (int i = 0; i < e; i++) {
        cout<<"Enter the U and V "<< endl;
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
    }

    vector<int> result = topo(adj);
    cout << "Topological order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}