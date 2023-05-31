#include<bits/stdc++.h>
using namespace std;

int rottanOrange(vector<vector<int>>& grid){

   // Taking size of Row and colom of grid
	int n = grid.size();
	int m = grid[0].size();

   // Creating data structure like visited array same a grid but empty and queue data structure
    int visited[n][m];
	queue<pair<pair<int , int> , int>> q;

	int fresh = 0;


   // Traversing throw the Grid, and if Roten orange is found , put in a queue and mark them visited in the visited array
	for(int i = 0; i < n; i++){

		for(int j = 0; j < m; j++){

			if(grid[i][j] == 2){

			    q.push({{i , j} , 0});
			    visited[i][j] = 2;
			}
			// else mark all them 0
			else
			{

				visited[i][j] = 0;
			}

           // count of every fresh orange
			if(grid[i][j] == 1) fresh++;
		}
	}
    
    

    int t = 0;
    int c = 0;


  // We can run this while loop uniti the queue is empty , and pop every element,  from previously put in the queue
    while(!q.empty()){

     
    	int x = q.front().first.first;
    	int y = q.front().first.second;
    	int z = q.front().second;
    	t = max(t , z);
    	q.pop();

   // we have to go in 4 directon so, we go like this to the neboring cell 
        int arr1[] = {-1 , 0 , +1 , 0};
        int arr2[] = {0 , 1 , 0 , -1};

         
    	for(int i = 0; i < 4; i++){
        
        // this will visit the new cell from the previous cell
    		int newrow = x + arr1[i];
    		int newcol = y + arr2[i];

        // now 1st we check the some conditions of that cell, conditions satisfied matrk them visited and put in the queue
    		if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newrow] == 1 && visited[newrow][newcol] == 0){

    			q.push({{newrow , newcol} , t + 1});
    			visited[newrow][newcol] = 2;

    			// count of every roten orange
    			c++;

    		}
    	}

    }

    
    // if all ornages are not rotean
    if(c != fresh) return -1;

    return t;

   
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int n , m;
cin >> n >> m;


vector<vector<int>> grid(n , vector<int>(m , 0));

for(int i = 0; i < n; i++){

	for(int j = 0; j < m; j++){

		cin >> grid[i][j];
	}
}


cout << rottanOrange(grid);


  return 0;
}





