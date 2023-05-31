#include<bits/stdc++.h>

using namespace std;

// Prim's Algorithum -> help us to find minimum Spanning tree (start with any Node)

int primsAlgo(vector<vector<int>> adj[] , int V){

	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
	vector<int> visited(V , 0);
	pq.push({0 , 0});
    

    int sum = 0;
	while(!pq.empty()){

		int weigh = pq.top().first;
		int node = pq.top().second;
		pq.pop();
      
		if(visited[node] == 1) continue;
		visited[node] = 1;

		// Here we are computing the sum of MST
		sum = sum + weigh; 

		for(auto i : adj[node]){

			int AdjW = i[1];
			int AdjN = i[0];

			if(!visited[AdjN]){

				pq.push({AdjW , AdjN});
			}
		}



	}

     return sum;

}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int V, E;
cin >> V >> E;

vector<vector<int>> adj[V];
     int i=0;
     while (i++<E) {

            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;

            t1.push_back(v);
            t1.push_back(w);

            adj[u].push_back(t1);

            t2.push_back(u);
            t2.push_back(w);

            adj[v].push_back(t2);
        }


  cout << primsAlgo(adj , V);
  
}