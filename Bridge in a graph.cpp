#include<bits/stdc++.h>
void solve(vector<int> adj[],vector<int>& disc,vector<int>& low,int parent,vector<bool>& visited,vector<vector<int>>& res,int &timer,int sv){
    visited[sv] = true;
    disc[sv] = low[sv] = timer++;
    for(auto neighbour:adj[sv]){
        if(neighbour==parent)continue;
        if(!visited[neighbour]){
            solve(adj,disc,low,sv,visited,res,timer,neighbour);
            low[sv] = min(low[sv],low[neighbour]);
            //check edge is a bridge or not
            if(low[neighbour]>disc[sv])res.push_back({sv,neighbour});
        }else{
            //back edges
            low[sv] = min(low[sv],disc[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    vector<int> adj[v+1];
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc(v,-1);
    vector<bool> visited(v,false);
    vector<int> low(v,-1);
    int parent = -1;
    vector<vector<int>> res;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            solve(adj,disc,low,parent,visited,res,timer,i);
        }
    }
    return res;

}
