#include<bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int , int>> adj[] , int visited[] , int node , stack<int> & st){

  visited[node] = 1;

  for(auto i : adj[node]){

     int v = i.first;

  	if(!visited[v]){

  		dfs(adj , visited , v , st);
  	}
  }

  st.push(node);

}

vector<int> compomentScan(vector<vector<int>>& edges , int V, int E){

//Converting This Edge to Graph
vector<pair<int , int>> adj[V];

for(int i = 0; i < E; i++){

	int u = edges[i][0];
	int v = edges[i][1];
	int wt = edges[i][2];
	adj[u].push_back({v , wt});
}


// Checking for Component and perfome DFS
int visited[V] = {0};
stack<int> st;
for(int i = 0; i < V; i++){
    if(!visited[i]){
    	dfs(adj , visited , i , st);
    }
}

// making of distent array
vector<int> dis(V);
for(int i = 0; i < V; i++){
	dis[i] = 1e9;
}

// droping source in the distant array and pop one by one.
dis[0] = 0;
while(!st.empty()){

int node = st.top();
st.pop();

    for(auto i : adj[node]){
       
	    int v = i.first;
	    int wt = i.second;

	    if(dis[node] + wt < dis[v]){
	    	dis[v] = dis[node] + wt;
	    }
}

}

for(int i = 0; i < V; i++){
	if(dis[i] == 1e9) dis[i] = -1;
}

return dis;


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

vector<int> dis = compomentScan(edges , V , E);
for(auto i : dis){
	cout << i << endl;
}

     

     return 0;
}




