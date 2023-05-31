#include<bits/stdc++.h>
using namespace std;


void bfs(int visited[] , vector<int> adj[] , int node , stack<int> & st){

	visited[node] = 1;

    for(auto i : adj[node]){

    	if(!visited[i]){

    		bfs(visited , adj , i , st);
    	}
    }

    st.push(node);

}

vector<int> componentScan(vector<int> adj[] , int V){
   
   int visited[V] = {0};
   stack<int> st;
   vector<int> ans;

	for(int i = 0; i < V; i++){
		if(!visited[i]){

			bfs(visited , adj , i , st);
			

		}
	}

	while(!st.empty()){

		int a = st.top();
		ans.push_back(a);
		st.pop();

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



vector<int> ans =  componentScan(adj , V);


for(auto i : ans){
	cout << i << endl;
} 

     return 0;
}




