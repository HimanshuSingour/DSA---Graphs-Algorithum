#include<bits/stdc++.h>
using namespace std;

// Anyone node who is part of cycle in a graph doest not having safe node
// Anone node who is connect to the cycle in a graph doest not having safe node

// cannot be a safe or terminal node

bool bfsCall(int visted[] , int pathVis[] , vector<int> adj[] ,  int node , int check[]){

	visted[node] = 1;
	pathVis[node] = 1;
	check[node] = 0;


	for(auto i : adj[node]){

		if(!visted[i]){

			if(bfsCall(visted , pathVis , adj , i , check) == true){
                check[i] = 0;
				return true;
			}
		}
		if(pathVis[i]){

			check[i] = 0;
			return true;
		}
	}

	pathVis[node] = 0;
	check[node] = 1;
	return false;
}

vector<int> Scan(vector<int> adj[] , int V){


	int visted[V] = {0};
	int pathVis[V] = {0};
	int check[V] = {0};

	vector<int> ans;


	for(int i = 0; i < V; i++){
		if(!visted[i]){

			bfsCall(visted , pathVis , adj , i , check);

		}
	}

	for(int i = 0; i < V; i++){

		if(check[i] == 1){

			ans.push_back(i);
		}
	}

	return ans;
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

vector<int>  ans = Scan(adj , V);

for(auto i : ans){

	cout << i << endl;
}

     return 0;
}




