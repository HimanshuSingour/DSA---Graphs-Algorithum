#include<bits/stdc++.h>

using namespace std;

int CheapestFLight(vector<vector<int>> flights , int src , int dst , int k , int n){
    
    //Creating Of Graphs
	vector<pair<int , int>> adj[n];
	for(auto i : flights){

         // node     to      node  EdgeW
		adj[i[0]].push_back({i[1], i[2]});
	}

    queue<pair<int , pair<int , int>>> q;
    q.push({0 , {src , 0}});

    vector<int> dist(n , 1e9);
    dist[src] = 0;

    while(!q.empty()){

    	int Kth = q.front().first;
    	int node = q.front().second.first;
    	int edgeW = q.front().second.second;
    	q.pop();
        
    	for(auto i : adj[node]){

    		int adJnode = i.first;
    		int AedgeW = i.second;


    		if(edgeW + AedgeW < dist[adJnode] && Kth <= k){

    			dist[adJnode] = edgeW + AedgeW;
    			q.push({Kth + 1 , {adJnode , edgeW + AedgeW}});
    		}
    	}
    }



 if(dist[dst] == 1e9) return -1;
 else return dist[dst];




}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int n; 
cin>>n;
int edge;
cin>>edge;

vector<vector<int>> flights;
        
for(int i=0; i<edge; ++i){

    vector<int> temp;
    for(int j=0; j<3; ++j){

        int x; 
        cin>>x;

    temp.push_back(x);
}
            
        flights.push_back(temp);
}
        
int src,dst,k;
cin>>src>>dst>>k;

cout << CheapestFLight(flights , src , dst , k , n); 

}