#include<bits/stdc++.h>
using namespace std;

bool isValid(int i , int j,vector<vector<char>> adjMax){

	int n = adjMax.size();
	int m = adjMax[0].size();

	if(i >= 0 && i < n && j >= 0 && j < m && adjMax[i][j] == '1'){

		return true;
	}

	return false;


}

void bsfcall(int i , int j ,vector<vector<char>>& adjMax ){

	adjMax[i][j] = '0';

	if(isValid(i + 1 , j , adjMax))
		bsfcall(i + 1 , j , adjMax);

	if(isValid(i - 1 , j , adjMax))
	   	bsfcall(i - 1 , j , adjMax);


	if(isValid(i  , j + 1 , adjMax))
	    bsfcall(i , j + 1, adjMax);

	if(isValid(i , j - 1 , adjMax))
	     bsfcall(i , j - 1 , adjMax);

}



int number(vector<vector<char>> &adjMax){

// // traversing to the matris which have land(0) not water and which is also not visited, and in each land we 
// // call bsf algorithum

int n = adjMax.size();
int m = adjMax[0].size();

int c = 0;

	for(int row = 0; row < n; row++){

	for(int col = 0; col < m; col++){

		if(adjMax[row][col] == '1'){

			c++;
			bsfcall(row , col ,adjMax);
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




