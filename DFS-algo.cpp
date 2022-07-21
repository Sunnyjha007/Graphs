//codestudio - DFS Traversal
void solve(unordered_map<int,vector<int>> &adj,vector<int>& v,unordered_map<int,bool>& visited,int sv){
    v.push_back(sv);
    visited[sv] = 1;
    for(auto i:adj[sv]){
        if(!visited[i]){
            solve(adj,v,visited,i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;
    for(int i=0;i<edges.size();i++){
        int f = edges[i][0];
        int s = edges[i][1];
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> v;
            solve(adj,v,visited,i);
            ans.push_back(v);
        }
    }
    return ans;   
}
