#include<iostream>
using namespace std;
int ranks[100000];
int parent[100000];
void makeset(){
	for(int i=0;i<=100000;i++){
		parent[i] = i;
		ranks[i] = 0;
	}
}
int findparent(int node){
	if(node == parent[node])return node;
  //path compression
	return parent[node] = findparent(parent[node]);
}
//union by rank
void unionfind(int u,int v){
	u = findparent(u);
	v = findparent(v);
	if(ranks[u]<ranks[v]){
		ranks[u] = v;
	}else if(ranks[v]<ranks[u]){
		parent[v] = u;
	}else{
		parent[v] = u;
		ranks[u ]++;
	}
}
int main(){
	makeset();
	int t;
	cin>>t;
	while(t--){
		int u,v;
		cin>>u>>v;
		unionfind(u,v);
	}
	if(findparent(2)!=findparent(6)){
		cout<<"Different parent"<<endl;
	}else cout<<"same parent";
	return 0;
}
