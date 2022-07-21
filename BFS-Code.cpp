Codestudio problem 
#include<bits/stdc++.h>
void solve(unordered_map<int,vector<int>>& adj,vector<int>& ans,unordered_map<int,bool>& visited,int sv ){
    queue<int> pn;
    pn.push(sv);
    visited[sv]=1;
    while(!pn.empty()){
        int front = pn.front();pn.pop();
        ans.push_back(front);
        for(auto i:adj[front]){
            if(!visited[i]){
                pn.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int v, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> visited;
    vector<int> ans;
    for(int i=0;i<edges.size();i++){
        int f = edges[i].first;
        int s = edges[i].second;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    for(int i=0;i<v;i++)sort(adj[i].begin(),adj[i].end());
    for(int i=0;i<v;i++){
        if(!visited[i]){
            solve(adj,ans,visited,i);
        }
    }
    return ans;
}
