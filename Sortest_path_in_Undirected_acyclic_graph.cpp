#include<bits/stdc++.h>
using namespace std;


vector<int> compomentScan(vector<vector<int>> & edges , int V ,int E ,int scr){

// converting the edge to graph
	vector<int> adj[V];
	for(auto i : edges){

		adj[i[0]].push_back(i[1]);
		adj[i[1]].push_back(i[0]);
	}

	int dist[V];
	for(int i = 0; i < V; i++){
		dist[i] = 1e9;
	}
    
    dist[scr] = 0;
	queue<int> q;
	q.push(scr);

	while(!q.empty()){

		int node = q.front();
		q.pop();

		for(auto i : adj[node]){
           
           if(dist[node] + 1 < dist[i]){

           	dist[i] = 1 + dist[node];
           	q.push(i);

           }

		}
	}

	vector<int> ans(V , -1);

	for(int i = 0; i < V; i++){
		if(dist[i] != 1e9){
			ans[i] = dist[i];
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

vector<vector<int>> edges;

for(int i=0; i<E; ++i){

    vector<int> temp;

    for(int j=0; j<3; ++j){

        int x; cin>>x;
        temp.push_back(x);

            }

            edges.push_back(temp);
        }

vector<int> dis = compomentScan(edges , V , E , 0);

for(auto i : dis){
	cout << i << endl;
}

     

     return 0;
}




