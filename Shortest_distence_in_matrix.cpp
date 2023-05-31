#include<bits/stdc++.h>

using namespace std;

int shortestPath(vector<vector<int>> &grid , pair<int , int> source , pair<int , int> destination){

   queue<pair<int , pair<int , int>>> q;
   q.push({0 , {source.first , source.second}});
   
   int n = grid.size();
   int m = grid[0].size();

   vector<vector<int>> dist(n , vector<int>(m , 1e9));

   dist[source.first][source.second] = 0;

   //Traverl to the 4 Directions
   int arr1[] = {-1 , 0 , 1 , 0};
   int arr2[] = {0 , 1 , 0 , -1};

   while(!q.empty()){


   	int dis = q.front().first;
   	int row = q.front().second.first;
   	int col = q.front().second.second;
   	q.pop();
   

    for(int i = 0; i < 4; i++){

    	int Nrow = row + arr1[i];
    	int Ncol = col + arr2[i];

    	if(Nrow >= 0 && Nrow < n && Ncol >= 0 && Ncol < m && grid[Nrow][Ncol] == 1 && dis + 1 < dist[Nrow][Ncol]){
            
    		dist[Nrow][Ncol] = 1 + dis;

    		 if(Nrow == destination.first && Ncol == destination.second) return dis + 1;

    		q.push({1 + dis , {Nrow , Ncol}});
    	}
    }


   }

   return -1;

}

 
int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int V, E;
cin >> V >> E;

vector<vector<int>> grid(V, vector<int>(E));

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < E; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination; 
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
       

   cout << shortestPath(grid , source , destination);
 

}