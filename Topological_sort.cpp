//DFS
void solve(vector<int> adj[],vector<bool>& visited,int sv,vector<int>& ans){
	    visited[sv] = true;
	    for(auto i:adj[sv]){
	        if(!visited[i])solve(adj,visited,i,ans);
	    }
	    ans.push_back(sv);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(n,false);
	    vector<int> ans;
	    //stack<int> s;
	    for(int i=0;i<n;i++){
	        if(!visited[i]){
	            solve(adj,visited,i,ans);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	   // while(!s.empty()){
	   //     ans.push_back(s.top());
	   //     s.pop();
	   // }
	   
	    return ans;
}
//BFS - Kahn's algo
vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    queue<int> pn;
	    vector<int> indegree(n,0);
	    for(int i=0;i<n;i++){
	        for(auto it:adj[i])indegree[it]++;
	    }
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0)pn.push(i);
	    }
	    vector<int> ans;
	    while(!pn.empty()){
	        int front = pn.front();pn.pop();
	        ans.push_back(front);
	        for(auto i:adj[front]){
	            indegree[i]--;
	            if(indegree[i]==0)pn.push(i);
	        }
	    }
	    return ans;
	}
