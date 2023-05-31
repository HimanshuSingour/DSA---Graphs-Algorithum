#include<bits/stdc++.h>
using namespace std;

// Detect Cycle in Directed Graph
bool bfs(int node , int pathVis[] , int vis[] , vector<int> adj[]){

	vis[node] = 1;
	pathVis[node] = 1;

	for(auto i : adj[node]){

		if(!vis[i]){

			if(bfs(i , pathVis , vis , adj) == true) return true;
			
 		}

 		else if(pathVis[i]) {

 			return true;
 		}
	}

	pathVis[node] = 0;
	return false;
}
bool check(vector<int> adj[] , int V){
  

 int vis[V] = {0};
 int pathVis[V] = {0};

// looping for more component
 for(int i = 0; i < V; i++){
 	if(!vis[i]){
 		if(bfs(i , pathVis , vis , adj) == true) return true;
 	}
 }  
  return false;


}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int V, E;
cin >> V >> E;

vector<int> adj[V];

for(int i = 0; i < E; i++) {

    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);

 }

cout << check(adj , V);

}





