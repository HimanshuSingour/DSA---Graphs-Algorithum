#include<bits/stdc++.h>
using namespace std;

// note that the topo generate = size of V

bool Indegree(vector<int> adj[] , int V){

    int inDegree[V] = {0};
    int size = sizeof(inDegree) / sizeof(int);

	for(int i = 0; i < V; i++){

		for(auto it : adj[i]){

			inDegree[it]++;
		}
	}

   queue<int> q;

	for(int i = 0; i < V; i++){
		if(inDegree[i] == 0){

			q.push(i);
		}
	}

   int c = 0;
	while(!q.empty()){

		int node = q.front();
		q.pop();
		c++;

		for(int it : adj[node]){
			inDegree[it]--;

			if(inDegree[it] == 0){
				q.push(it);
			}

		}
	}

   if(c == V) return true;
   else return false;

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

cout << Indegree(adj , V);


     return 0;
}




