#include<bits/stdc++.h>
using namespace std;

bool check(int source , int V , vector<int> adj[], int color[] , queue<int> & q){

color[source] = 0;

q.push(source);

while(!q.empty()){

	int node = q.front();
	q.pop();


	for(auto i : adj[node]){

		if(color[i] == -1){

			color[i] = !color[node];
			q.push(i);
		}
		else if(color[i] == color[node]){

			return false;
		}
	}
}

return true;
 

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


for(int i = 0; i < E; i++){

	int u, v;
	cin >> u >> v;

	adj[u].push_back(v);
	adj[v].push_back(u);

}
//Creating Some data structures
queue<int> q;
int color[V];

for(int i = 0; i < V; i++){
  color[i] = -1;

}


for(int i = 0; i < V; i++){
	if(color[i] == -1){

		if(check(i , V , adj , color , q) == false){

		    cout << " ";
		}
	}
}

cout << "Yes it .. ";


 

}





