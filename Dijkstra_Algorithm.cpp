#include<bits/stdc++.h>

using namespace std;

vector<int> DijkstraAlgorithum(int V , int S , vector<vector<int>> adj[]){

   priority_queue <pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
   vector<int> dis(V);

   for(int i = 0; i < V; i++){
   	 dis[i] = 1e9;
   }
  
   dis[S] = 0;
   pq.push({0 , S});
   
   while(!pq.empty()){
     
     int distance = pq.top().first;
     int node = pq.top().second;
     pq.pop();
     
        for(auto i : adj[node]){

           int adjnode = i[0];
           int adjDis = i[1];

           if(distance + adjDis < dis[adjnode]){

           	  dis[adjnode] = distance + adjDis;
           	  pq.push({dis[adjnode] , adjnode});


           }

       
        }

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
        int S;
        cin>>S;


vector<int> ans = DijkstraAlgorithum(V , S , adj);

 for(int i : ans){
 	cout << i << endl;
 }


}