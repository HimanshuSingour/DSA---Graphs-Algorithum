#include<bits/stdc++.h>
using namespace std;

bool DetctCycleUndirectedGrpah(vector<int> adj[] , int visited[] , int V , queue<pair<int , int>> & q){



 // push the source and parent in the q and mark them visited

	visited[0] = 1;
	q.push({0 , -1});

	
	while(!q.empty()){

		int node = q.front().first;
		int parent = q.front().second;
		q.pop();


		for(int i : adj[node]){

			if(!visited[i]){

				visited[i] = 1;
				q.push({i , parent});
			}
			else if(parent != i){

                return true;
			}
		}
	}

   return false;

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

for (int i = 0; i < E; i++) {

    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
   
   }


 // Creating datastructre
	int visited[V] = {0};
	queue<pair<int , int>> q;


for(int i = 0; i < V; i++){

	if(!visited[i]){
  
        if(DetctCycleUndirectedGrpah(adj , visited , i , q)) {

        	cout << "Yes";
        }

        else{

        	cout << "NO";
        }
        	
	}
        }
    


  return 0;
}




