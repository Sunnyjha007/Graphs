//BFS
bool solve(int n,vector<int>adj[],vector<int>& visited,int sv){
    queue<int> pn;
    pn.push(sv);
    visited[sv] = 0;
    while(!pn.empty()){
        auto front = pn.front();pn.pop();
        for(auto i:adj[front]){
            if(visited[i]==-1){
                visited[i] = 1 - visited[front];
                pn.push(i);
            }else if(visited[i] == visited[front])return false;
        }
    }
    return true;
}
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> visited(n,-1);
	    for(int i=0;i<n;i++){
	        if(visited[i]==-1){
	            if(!solve(n,adj,visited,i))return false;
	        }
	    }
	    return true;
	}
//DFS
bool solve(int n, vector<int>adj[],vector<int>& visited,int sv){
        if(visited[sv]==-1)visited[sv] = 1;
        for(auto i:adj[sv]){
            if(visited[i]==-1){
                visited[i] = 1 - visited[sv];
                if(!solve(n,adj,visited,i))return false;
            }else if(visited[sv] == visited[i])return false;
        }
        return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> visited(n,-1);
	    for(int i=0;i<n;i++){
	        if(visited[i]==-1){
	            if(!solve(n,adj,visited,i))return false;
	        }
	    }
	    return true;
	}
