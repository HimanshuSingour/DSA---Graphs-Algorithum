#include<bits/stdc++.h>

using namespace std;

int number(vector<vector<int>> & road , int n){

	// Graph
    vector<pair<int , int>> adj[n];
	for(auto i : road){
   
     adj[i[0]].push_back({i[1] , i[2]});
     adj[i[1]].push_back({i[0] , i[2]});

	}

	int mod = (int)(1e9 + 7);

	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
	vector<int> dist(n , 1e9);
	vector<int> ways(n , 0);
	pq.push({0 , 0});
    dist[0] = 0;
    ways[0] = 1;

    while(!pq.empty()){

    	int diff = pq.top().first;
    	int node = pq.top().second;
    	pq.pop();

    	 for(auto i : adj[node]){

    	 	int AdjNode = i.first;
    	 	int AdjDiff = i.second;

    	 	if(diff + AdjDiff < dist[AdjNode]){

    	 		dist[AdjNode] = diff + AdjDiff;
    	 		pq.push({diff + AdjDiff , AdjNode});
    	 		ways[AdjNode] = ways[node]; 
                
    	 	}
    	 	
    	 	else if(diff + AdjDiff == dist[AdjNode]){

    	 		ways[AdjNode] = (ways[AdjNode] + ways[node]) % mod;
    	 	}
    	 }
    }

     return ways[n - 1] % mod;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
 int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

cout << number(adj , n); 

}