//gfg
vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;
        dist[s] = 0;
        st.insert(make_pair(0,s));
        while(!st.empty()){
            auto node = *(st.begin());
            int nodedist = node.first;
            int topnode = node.second;
            st.erase(st.begin());
            for(auto i:adj[topnode]){
                if(dist[i[0]]> i[1]+nodedist){
                    auto record = st.find(make_pair(dist[i[0]],i[0]));
                    if(record!=st.end())st.erase(record);
                    dist[i[0]] = nodedist+i[1];
                    st.insert(make_pair(dist[i[0]],i[0]));
                }
            }
        }
        return dist;
}
//codestudio
#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> dist(vertices,INT_MAX);
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert({0,source});
    while(!st.empty()){
        auto front = *st.begin();
        int topdist = front.first;
        int topnode = front.second;
        st.erase(st.begin());
        for(auto i:adj[topnode]){
            if(topdist+i.second<dist[i.first]){
                auto record = st.find({dist[i.first],i.first});
                if(record!=st.end())st.erase(record);
                dist[i.first] = topdist+i.second;
                st.insert({dist[i.first],i.first});
                
            }
        }
    }
    return dist;
}












