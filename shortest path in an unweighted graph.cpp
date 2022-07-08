#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    unordered_map<int,vector<int>> map;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        map[u].push_back(v);
        map[v].push_back(u);
      }
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> pn;
    pn.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!pn.empty()){
        int front = pn.front();pn.pop();
        for(auto i:map[front]){
            if(!visited[i]){
                pn.push(i);
                parent[i] = front;
                visited[i] = true;
            }
        }
    }
    vector<int> ans;
    int currentnode = t;
    ans.push_back(t);
    while(currentnode!=s){
        currentnode = parent[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}
