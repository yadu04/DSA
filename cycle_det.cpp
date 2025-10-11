#include<bits/stdc++.h>
using namespace std;
bool iscyclic(vector<vector<int>> &adj,vector<int> &parent ,vector<int>&visited,int node){
    queue<int>q;
    q.push(node);
    visited[node]=true;
    parent[node]=-1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto &neighbour :adj[front]){
            if(visited[node] && neighbour !=parent[node]){
                return true;
            }
            else if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
                parent[neighbour]=front;
                
            }
        }

    }

}
int main(){

}