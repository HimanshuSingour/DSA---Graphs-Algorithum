#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bfs(vector<vector<int>> grid , vector<vector<int>> & modified){

	queue<pair<pair<int , int > , int>> q;

	int n = grid.size();
	int m = grid[0].size();


vector<vector<int>> visited (n, vector<int>(m, 0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

			if(grid[i][j] == 1){
          
              q.push({{i , j} , 0});
				visited[i][j] = 1;
				
			}
			else{

				visited[i][j] = 0;
			}
		}
	}


   int arr1[] = {-1 , 0 , +1 , 0};
   int arr2[] = {0 , +1 , 0, -1};

	while(!q.empty()){

		int rows = q.front().first.first;
		int cols = q.front().first.second;
		int steps = q.front().second;
		q.pop();

		modified[rows][cols] = steps;


      for(int i = 0; i < 4; i++){

      	int newRow = rows + arr1[i];
      	int newCol = cols + arr2[i];

      	if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && visited[newRow][newCol] == 0){

      		visited[newRow][newCol] = 1;
      		q.push({{newRow , newCol} , steps + 1});
      	}
      }
	}


 return modified;
  
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

int n, m;
cin >> n >> m;

vector<vector<int>> grid (n, vector<int>(m, 0));


for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){

		cin >> grid[i][j];
	}
}

vector<vector<int>> modified (n, vector<int>(m, 0));

bfs(grid , modified);


for(int i = 0; i < modified.size(); i++){

	for(int j = 0; j < modified[0].size(); j++){

		cout << modified[i][j] << " ";
	}

	cout << "\n";
}


     return 0;

 }



