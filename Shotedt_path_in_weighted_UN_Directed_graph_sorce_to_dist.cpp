#include<bits/stdc++.h>

using namespace std;

vector<int> isPossible(vector<vector<int>> & edges , int V , int  E , int S){

	 // Graph creation
	vector<pair<int , int>> adj[V + 1];

	for(auto i : edges){
     
    adj[i[0]].push_back({i[1] , i[2]});
    adj[i[1]].push_back({i[0] , i[2]});
	
	}

	vector<int> parent(V + 1);

	for(int i = 0; i < V; i++){
       
       parent[i] = i;
	}

	//Createing PQ
	priority_queue <pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
	pq.push({0 , 1});

	//distiend array
	vector<int> dist(V + 1 , 1e9);
	dist[1] = 0;

	while(!pq.empty()){

		int node = pq.top().second; 
		int dis = pq.top().first;
		pq.pop();

		  for(auto i : adj[node]){

		  	 int adjNode = i.first;
		  	 int adjdis = i.second;

		  	 if(dis + adjdis < dist[adjNode]){

		  	 	dist[adjNode] = dis + adjdis;
		  	 	pq.push({dist[adjNode] , adjNode});
		  	 	parent[adjNode] = node;
		  	 }
		  }
	}

	//if not get return list of -1

	if(dist[V] == 1e9) return {-1};


	int node = V; //5

	vector<int> path;

	while(parent[node] != node){

		path.push_back(node);
		node = parent[node];

	}

	path.push_back(1);
	reverse(path.begin() , path.end());
	return path;
     
}

 
int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int v, e;
        cin >> v >> e;

        vector<vector<int>> edges;

        for (int i = 0; i < e; ++i) {

            vector<int> temp;

            for (int j = 0; j < 3; ++j) {

                int x;
                cin >> x;

                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        
vector<int> ans = isPossible(edges , v , e , 1);

for(auto i : ans){
	cout << i << endl;
}

 
 

}