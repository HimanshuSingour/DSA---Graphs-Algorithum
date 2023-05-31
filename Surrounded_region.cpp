#include<bits/stdc++.h>
using namespace std;

// Remember: if any o connect to the boundry means they cannot converted to X
// start from the boundary o's marth them they are not converted and conver the remining

void bfs(vector<vector<char>> & matrix , int row , int col , vector<vector<int>> & visited){


	visited[row][col] = 1;

	int n = matrix.size();
	int m = matrix[0].size();

    // check for top right left bottom
	int arr1[] = {-1 , 0 , +1 , 0};
	int arr2[] = {0 , 1 , 0 , -1};

	for(int i = 0; i < 4; i++){

		int nRow = row + arr1[i];
		int nCol = col + arr2[i];

		if(0 >= nRow && n < nRow && 0 >= nCol && m < nCol && !visited[nRow][nCol] && matrix[nRow][nCol] == 'o'){

			 bfs(matrix , nRow , nCol , visited);
		}
	}

}

void calculaterowCol(vector<vector<char>>  matrix){

	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>> visited(m , vector<int>(m , 0));

   // first row and last row
	for(int j = 0; j < m; j++){
       
       //first row
		if(matrix[0][j] == 'o' && !visited[0][j]){
            
            bfs(matrix , 0 , j , visited);
		}

        // last row
		if(matrix[n-1][j] == 'o' && !visited[n - 1][j]){

			bfs(matrix , n-1 , j , visited);
		}  

	}

  // first colum and last colum
	for(int i = 0; i < n; i++){


       // first coulm
		if(matrix[i][0] == 'o' && !visited[i][0]){

			bfs(matrix , i , 0 , visited);
		}

       // last colum
		if(matrix[i][m - 1] == 'o' && !visited[i][m - 1]){

			bfs(matrix , i , m - 1 , visited);
		}
	}


	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

			if(!visited[i][j] && matrix[i][j] == 'o'){

				matrix[i][j] = 'x';
			}
		}
	}


  // printing the modified matrix
	for(int i = 0; i < matrix.size(); i++){
	    for(int j = 0; j < matrix[0].size(); j++){

		 cout << matrix[i][j] << " ";
	}

	cout << endl;
}

}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

int n, m;
cin >> n >> m;

vector<vector<char>> matrix(n , vector<char>(m , '#'));


for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){

		cin >> matrix[i][j];
	}
}

calculaterowCol(matrix);




     return 0;

 }



