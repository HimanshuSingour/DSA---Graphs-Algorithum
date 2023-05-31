#include<bits/stdc++.h>
using namespace std;

vector<int> Indegree(vector<int> adj[] , int V){

    int inDegree[V] = {0};

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

   vector<int> ans;
	while(!q.empty()){

		int node = q.front();
		q.pop();
		ans.push_back(node);

		for(int it : adj[node]){
			inDegree[it]--;

			if(inDegree[it] == 0){
				q.push(it);
			}

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

vector<int> ans = Indegree(adj , V);

for(auto i : ans){
	cout << i << endl;
}



     return 0;
}




