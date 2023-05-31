#include<bits/stdc++.h>
using namespace std;

void bsfcall(int row , int col ,vector<vector<int>> &visited, vector<vector<char>> adjMax ){
 
 visited[row][col] = 1;
 queue<pair<int , int>> q;
 q.push({row , col});

 int n = adjMax.size();
 int m = adjMax[0].size();


 while(!q.empty()){

 	int row = q.front().first;
 	int col = q.front().second; 
 	q.pop();

 	// traversing  the naboring of the elemnts
 	for(int i = -1; i <= 1; i++){

 		for(int j = -1; j <= 1; j++){

 			int nrow = row + i;
 			int ncol = col + j;

 			if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && adjMax[nrow][ncol] == '1'){

 				visited[nrow][ncol] = 1;
 				q.push({nrow , ncol});
 			}

 		}
 	}
 	
 }

}



int number(vector<vector<char>> &adjMax){

// // traversing to the matris which have land(0) not water and which is also not visited, and in each land we 
// // call bsf algorithum

int n = adjMax.size();
int m = adjMax[0].size();

vector<vector<int>> visited(n , vector<int>(m , 0));
int c = 0;

	for(int row = 0; row < n; row++){

	for(int col = 0; col < m; col++){

		if(adjMax[row][col] == '1' && !visited[row][col]){

			c++;
			bsfcall(row , col , visited , adjMax);
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
int n , m;
cin >> n >> m;

vector<vector<char>> adjMax(n , vector<char>(m , '0'));
for(int i = 0; i < n; i++){

	for(int j = 0; j < m; j++){

		cin >> adjMax[i][j];
	}
}



cout << number(adjMax);




  return 0;
}




