#include<bits/stdc++.h>

using namespace std;

//Disjoind Set

// Question are Panding

class DisjoindSet{

	vector<int> rank;
	vector<int> parent;

public: 
	DisjoindSet(int n ){

		rank.resize(n + 1 , 0);
		parent.resize(n + 1);
	   for(int i = 0; i < n; i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int findParent(int node){
		if(parent[node] == node){
			return node;
		}
		else{
            // path compression
			parent[node] = findParent(parent[node]);
		}
	}

	void Union(int u , int v){

		u = findParent(u);
		v = findParent(v);

		if(rank[u] < rank[v]){
			parent[u] = v;
		}
		else if(rank[u] > rank[v]){
			parent[v] = u;
		}
		else{

			parent[u] = v;
			rank[u]++;
		}
	}

};


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

	DisjoindSet ds(7);
	ds.Union(1, 2); 
    ds.Union(2, 3); 
    ds.Union(4, 5); 
    ds.Union(6, 7); 
    ds.Union(5, 6);

    if(ds.findParent(3) == ds.findParent(7)){

    	cout << "same\n";
    } 
    else{

    	cout << "Not Same\n";
    }

    ds.Union(3, 7); 

        if(ds.findParent(3) == ds.findParent(7)){

    	cout << "same\n";
    } 
    else{

    	cout << "Not Same\n";
    }


    
 
  
}