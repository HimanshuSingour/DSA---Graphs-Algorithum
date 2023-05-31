#include<bits/stdc++.h>
using namespace std;

void printAdjeccyList( vector<vector<int>> & adj , int v){


	for(int i = 0; i < v; i++){
          

          cout << i << " ---> ";
		for(int j = 0; j < adj[i].size(); j++){

         cout << adj[i][j] << " ";

		}

		cout << "\n";
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



printAdjeccyList(adj , v);




  return 0;

}


