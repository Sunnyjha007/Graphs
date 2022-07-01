 //DFS- Traversal
 bool check(vector<int> adj[],vector<int>& visited,int sv,int prev){
      visited[sv] = true;
      for(auto i:adj[sv]){
          if(!visited[i]){
              if(check(adj,visited,i,sv))return true;
          }else if(prev!=i)return true;
      }
      return false;
      
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(check(adj,visited,i,-1))return true;
            }
        }
        return false;
    }
};

//BFS - traversal
/*
bool check(vector<int> adj[],vector<int>& visited,int sv,int n){
      queue<pair<int,int>> pn;
      pn.push({sv,-1});
      visited[sv] = true;
      while(!pn.empty()){
          auto front = pn.front();pn.pop();
          int node = front.first;
          int prev = front.second;
          for(auto i:adj[node]){
              if(!visited[i]){
                  pn.push({i,node});
                  visited[i] = true;
              }else if(prev!=i)return true;
          }
      }
      return false;
}
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(check(adj,visited,i,n))return true;
            }
        }
        return false;
    }
