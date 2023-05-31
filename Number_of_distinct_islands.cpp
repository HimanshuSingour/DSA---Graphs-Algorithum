#include<bits/stdc++.h>
using namespace std;

void dfs(int row , int col , int baseRow , int baseCol , vector<vector<int>> & visited ,vector<vector<int>> & grid , vector<pair<int , int>> &vect){

	visited[row][col] = 1;
	vect.push_back({baseRow - row , baseCol - col});

	int n = grid.size();
	int m = grid[0].size();


	int arr1[] = {-1 , 0 , +1 , 0};
	int arr2[] = {0, -1 , 0 , 1};

	for(int i = 0; i < 4; i++){

		int nRow = row + arr1[i];
		int nCol = col + arr2[i];

		if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == 1){

			dfs(nRow , nCol , baseRow , baseCol , visited , grid , vect);
		}
	}

}

int countDistinctIslands(vector<vector<int>> grid){

	int n = grid.size();
	int m = grid[0].size();
   
   // creating imp datastructures
	vector<vector<int>> visited(n , vector<int>(m , 0));
	set<vector<pair<int , int>>> s;

  
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

			if(grid[i][j] == 1 && !visited[i][j]){

                vector<pair<int , int>> vect;
				dfs(i , j , i , j , visited , grid , vect);
				s.insert(vect);

			}
		}
	}

 return s.size();

}
	
int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int n, m;
cin >> n >> m;

vector<vector<int>> grid(n , vector<int>(m , 0));


for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){

		cin >> grid[i][j];
	}
}


 cout << countDistinctIslands(grid);


     return 0;

 }



