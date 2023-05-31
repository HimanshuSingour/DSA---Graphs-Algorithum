#include<bits/stdc++.h>
using namespace std;


int Enclaves(vector<vector<int>> & grid){

	int n = grid.size();
	int m = grid[0].size();

  vector<vector<int>> visited(n , vector<int>(m , 0));
   queue<pair<int , int>> q;
 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

			 if(i == 0 || j == 0 || i == n - 1 || j == m - 1){     

                if(grid[i][j] == 1){

                visited[i][j] = 1;
                q.push({i , j});  

                }

			 }

		}
	}

	while(!q.empty()){

		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		int arr1[] = {-1 , 0 , 1 , 0};
		int arr2[] = {0 , -1 , 0, 1};

		for(int i = 0; i < 4; i++){

			int nRow = row + arr1[i];
			int nCol = col + arr2[i];

			if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] == 0 && grid[nRow][nCol] == 1){

				visited[nRow][nCol] = 1;
				q.push({nRow , nCol});
			}
		}
	}

	int c = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 1 && visited[i][j] == 0 ){
				c++;
			}
		}
	}

	return c;



}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

int n, m;
cin >> n >> m;

vector<vector<int>> grid(n , vector<int>(m , '#'));


for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){

		cin >> grid[i][j];
	}
}


cout << Enclaves(grid);


     return 0;

 }



