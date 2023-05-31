#include<bits/stdc++.h>
using namespace std;

bool ifPossible(vector<pair<int , int>> & prerequisites , int N){

  vector<int> adj[N];

  for(auto i : prerequisites){
  	adj[i.first].push_back(i.second);
  }

  int indegree[N] = {0};

  for(int i = 0; i < N; i++){
  	for(auto it : adj[i]){
      indegree[it]++;

  	}
  }

  queue<int> q;

  for(int i = 0; i < N; i++){
  	if(indegree[i] == 0){
  		q.push(i);
  	}
  }


  int c = 0;
  while(!q.empty()){

  	int node = q.front();
  	q.pop();
  	c++;

  	for(auto i : adj[node]){
  		indegree[i]--;

  		if(indegree[i] == 0) q.push(i);
  	}
  }

  if(N == c) return true;
  else return false;


}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int N, E;
cin >> N >> E;

vector<pair<int , int>> prerequisites;

for(int i = 0; i < E; i++) {

    int u, N;
    cin >> u >> N;

    prerequisites.push_back(make_pair(u , N));


}

if(ifPossible(prerequisites , N)){

	cout << "Yes";
}
else{

	cout << "No";
}


     return 0;
}




