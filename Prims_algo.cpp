//gfg
//calculate distance minimum
int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<bool> mst(n+1,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pn;
        pn.push({0,0});
        int sum=0;
        while(!pn.empty()){
            auto top = pn.top();pn.pop();
            int node = top.second;
            int wt = top.first;
            if(!mst[node]){
                for(auto it:adj[node]){
                    if(!mst[it[0]])pn.push({it[1],it[0]});
                }
                mst[node] = true;
                sum+=wt;
            }
        }
        return sum;
}
//codestudio
//calculate {u->v,key[i]}
#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> key(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    vector<bool> mst(n+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pn;
    pn.push({0,1});
    key[1]=0;
    while(!pn.empty()){
        auto top = pn.top();pn.pop();
        int node = top.second;
        int wt = top.first;
        mst[node] = true;
            for(auto &it:adj[node]){
                int v = it.first;
                int w = it.second;
                if(!mst[v]&&key[v]>w){
                    parent[v] = node;
                    key[v] = w;
                    pn.push({key[v],v});
                }
            }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
    
}
