#include<bits/stdc++.h>
using namespace std;

void bfstravesal( vector<vector<int>> & adj , int s ,int v ){


	vector<int> vis(v , 0);

	vis[s] = 1;

	queue<int> q;
	q.push(s);

	vector<int> bfs;

	while(!q.empty()){

		int node = q.front();
		q.pop();

		bfs.push_back(node);

		for(auto i : adj[node]){

			if(!vis[i]){
				vis[i] = 1;
				q.push(i);


			}
		}
	}


    for(int i = 0; i < bfs.size(); i++){

	   cout << i << endl;
  }

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// Taking input of Adjecncy list

  int v , e;
  cin >> v >> e;

  vector<vector<int>> adj(v);

  for(int i = 0; i < e; i++){

  	 int n , m;
  	 cin >> n >> m;

  	 adj[n].push_back(m);
  	 adj[m].push_back(n);
  }



bfstravesal(adj , 0 , v);




  return 0;

}


