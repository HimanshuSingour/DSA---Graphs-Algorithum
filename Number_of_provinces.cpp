#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adjList[] ,  int node , int visited[]){


	visited[node] = 1;

	for(auto i : adjList[node]){

		if(!visited[i]){

			dfs(adjList ,  i , visited);
		}
	}


}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif



// taking input adjectent matrix
int V;

cin >> V;
        
 vector<vector<int>> adj;
        
  for(int i = 0; i < V; i++)

     {
            vector<int> temp;

      for(int j = 0; j < V; j++)

            {   
            	int x;
                cin>>x;
                temp.push_back(x);

            }

            adj.push_back(temp);
        }
        

// Converting adj (matrix) to adj (list);
vector<int> adjList[V];

for(int i = 0; i < V; i++){

	for(int j = 0; j < V; j++){

		if(adj[i][j] == 1 && i != j){

			adjList[i].push_back(j);
			adjList[j].push_back(i);
		}
	}
}


int visited[V] = {0};

int c = 0;

for(int i = 0; i < V; i++){

	if(!visited[i]){

		c++;

		dfs(adjList , i , visited);
	}
}

cout << c;



 

  return 0;

}


