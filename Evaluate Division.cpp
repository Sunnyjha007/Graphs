double solve(unordered_map<string,vector<pair<string,double>>>& adj,vector<string>& queries){
        queue<pair<string,double>>pn;
        unordered_map<string,bool> visited;
        string u = queries[0];
        string v = queries[1];
        if(adj.find(u)==adj.end())return -1.00000;
        if(adj.find(v)==adj.end())return -1.00000;
        pn.push({u,1.00000});
        visited[u] = true;
        while(!pn.empty()){
            auto front = pn.front();pn.pop();
            string node = front.first;
            double dist = front.second;
            if(node==v)return dist;
            for(auto &it:adj[node]){
                string nbrnode = it.first;
                double nbrdist = it.second;
                if(!visited[nbrnode]){
                    pn.push({nbrnode,dist*nbrdist});
                    visited[nbrnode] = true;
                }
            }
        }
        return -1.00000;
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double wt = values[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,1/wt});
        }
        vector<double> ans;
        for(auto it:queries){
            ans.push_back(solve(adj,it));
        }
        return ans;
}
