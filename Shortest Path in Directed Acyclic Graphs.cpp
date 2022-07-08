#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
class Graph{
    public:
    unordered_map<int,vector<pair<int,int> > > adj;
    void addEdge(int u,int v,int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }cout<<endl;
        }
    } 
    void dfs(stack<int>& st,unordered_map<int,bool>& visited,int sv){
    visited[sv] = true;
    for(auto i:adj[sv]){
        if(!visited[i.first]){
            dfs(st,visited,i.first);
        }
    }
    st.push(sv);
}
void getshortestpath(int src,vector<int>& dist,stack<int>& st){
     dist[src] = 0;
     while(!st.empty()){ 
        int top = st.top();st.pop();
        if(dist[top]!=INT_MAX){
            for(auto i:adj[top]){
                if(dist[top] + i.second<dist[i.first]){
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }

      }
   }
};

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.print();
    int n = 6;
    unordered_map<int,bool> visited;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i])g.dfs(st,visited,i);
    }
    int src = 1;
    vector<int> dist(n,INT_MAX);
    g.getshortestpath(src,dist,st);
    for(int i=0;i<n;i++)cout<<dist[i]<<" "; 
    return 0;
}
