#include<bits/stdc++.h>
using namespace std;

int printDfs(vector<vector<int>> & adj ,  vector<int> & visited ,   vector<int> & ans , int s){

	
  visited[s] = 1;
  ans.push_back(s);

  for(int i : adj[s]){

  	 if(!visited[i]){

  	 	printDfs(adj , visited , ans , i);

  	 }
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

  
 // Creating datastructure
 vector<int> visited(v , 0); 
 vector<int> ans;

 printDfs(adj , visited , ans , 0);

 for(int i = 0; i < ans.size(); i++){

 	cout << i << endl;
 }



  return 0;

}


