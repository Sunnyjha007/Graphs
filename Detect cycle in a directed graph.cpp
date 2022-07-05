//GFG
//DFS
bool solve(vector<int> adj[],vector<bool>& visited,vector<bool>& visited_dfs,int sv){
       visited[sv] = true;
       visited_dfs[sv] = true;
       for(auto i:adj[sv]){
           if(!visited[i]){
               if(solve(adj,visited,visited_dfs,i))return true;
           }else if(visited_dfs[i])return true;
       }
       visited_dfs[sv] = false;
       return false;
   }
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<bool> visited(n,false);
        vector<bool> visited_dfs(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(solve(adj,visited,visited_dfs,i))return true;
            }
        }
        return false;
}
