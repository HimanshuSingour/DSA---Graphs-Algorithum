#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> & image , int i , int j , int color){

    int n = image.size();
    int m = image[0].size();

	if(i >= 0 && i < n && j >= 0 && j < m && image[i][j] == color){

		return true;
	}
	return false;

}

vector<vector<char>> floodFill(vector<vector<char>> & image , int i , int j , char newColor , int color){


	image[i][j] = newColor;

	int n = image.size();
	int m = image[0].size();


	if(isValid(image , i + 1, j, color))
		floodFill(image , i + 1  , j, newColor , color);

	if(isValid(image , i - 1, j, color))
		floodFill(image , i - 1  , j, newColor , color);


	if(isValid(image , i , j + 1, color))
		floodFill(image , i  , j + 1, newColor , color);


	if(isValid(image , i, j - 1, color))
		floodFill(image , i, j - 1, newColor , color);


	return image;


}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int n , m;
cin >> n >> m;

vector<vector<char>> image(n , vector<char>(m , 0));

for(int i = 0; i < n; i++){

	for(int j = 0; j < m; j++){

		cin >> image[i][j];
	}
}


int sr , sc;
cin >> sr >> sc;

char newColor;
cin >> newColor;


int color = image[sc][sr];


floodFill(image , sc , sr , newColor , color);

for(int i = 0; i < n; i++){

	for(int j = 0; j < m; j++){

		cout << image[i][j] << " ";
	}

	cout << "\n";

  }




  return 0;
}




