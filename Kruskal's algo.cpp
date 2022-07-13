#include<bits/stdc++.h>
bool cmp(vector<int>& a,vector<int>& b){
    return a[2]<b[2];
}
void makeset(vector<int>& parent,vector<int>& rank,int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
T.c = O(mlog(m)) -> m = edges
int findparent(int node,vector<int>& parent){
    if(node==parent[node])return node;
    return parent[node] = findparent(parent[node],parent);
}
void unionset(int u,int v,vector<int>& parent,vector<int>& rank){
    u = findparent(u,parent);
    v = findparent(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[v]<rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n),rank(n);
    makeset(parent,rank,n);
    int ans = 0;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        u = findparent(u,parent);
        v = findparent(v,parent);
        if(u!=v){
            ans+=wt;
            unionset(u,v,parent,rank);
        }
    }
    return ans;
}
